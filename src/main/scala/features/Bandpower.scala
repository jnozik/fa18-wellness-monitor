package features

import chisel3._
import chisel3.util._
import dsptools.numbers._
import dspjunctions._
import breeze.numerics.log2

// Currently designed with a lane for each bin

trait BandpowerParams[T <: Data] {
  val idxStartBin: Int
  val idxEndBin: Int
  val nBins: Int
  val genIn: DspComplex[T]
  val genOut: T
}

class BandpowerIO[T <: Data](params: BandpowerParams[T]) extends Bundle {
  val in = Flipped(ValidWithSync(Vec(params.nBins, params.genIn.cloneType)))
  val out = ValidWithSync(params.genOut.cloneType)

  override def cloneType: this.type = BandpowerIO(params).asInstanceOf[this.type]
}
object BandpowerIO {
  def apply[T <: Data](params: BandpowerParams[T]): BandpowerIO[T] = new BandpowerIO(params)
}

class Bandpower[T <: Data : Real : BinaryRepresentation](val params: BandpowerParams[T]) extends Module {
  require(params.idxEndBin > params.idxStartBin, f"End index ${params.idxEndBin} must be greater than start index ${params.idxStartBin}")
  require(((params.idxEndBin - params.idxStartBin) & (params.idxEndBin - params.idxStartBin - 1)) == 0,
    f"Difference between the two indices must be a power of 2, currently ${params.idxEndBin - params.idxStartBin}")
  require(params.nBins/2 >= params.idxEndBin,
    f"End index ${params.idxEndBin} must be at most half of the total number of bins ${params.nBins}")

  val io = IO(new BandpowerIO[T](params))

  // Take mag squared of FFT output
  val p2 = io.in.bits.map(_.abssq())
  // Except for DC and sampling freq, 2x for 2-sided to 1-sided
  val p1Scaled = p2.slice(1, params.nBins/2 - 1).map(_ * 2)
  // Concatenate back in unscaled DC and sampling freq elems
  val p1 = VecInit(p2(0)) ++ p1Scaled ++ VecInit(p2(params.nBins/2))
  // Sum and divide by num of bins of interest squared
  val outNext = p1.slice(params.idxStartBin, params.idxEndBin).reduce(_ + _) >> (2 * log2(params.idxEndBin - params.idxStartBin).toInt)

  val outReg = RegEnable(outNext, io.in.valid)
  val valReg = RegNext(io.in.valid)
  val syncReg = RegNext(io.in.sync)

  io.out.bits := outReg
  io.out.valid := valReg
  io.out.sync := syncReg
}