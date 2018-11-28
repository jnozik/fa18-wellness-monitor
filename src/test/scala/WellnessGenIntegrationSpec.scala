package wellness
import chisel3._
import chisel3.core.FixedPoint
import dsptools.numbers._
import features._
import fft._
import firFilter._
import org.scalatest.{FlatSpec, Matchers}
import pca._
import svm._

import scala.collection.mutable.ArrayBuffer
import scala.collection.{Seq, mutable}

abstract class filterGenParamsTemplate {
  val taps:Seq[Double]
}
abstract class lineLengthGenParamsTemplate {
  val windowSize:Int
}



class wellnessGenIntegrationParameterBundle {

  // the numbers here are actually irrelevant, you just need to put something
  // these will be overwritten anyway in the WellnessIntegrationSpec class
  // the 'requires' are not even being checked!
  val filter1Params:filterGenParamsTemplate = new filterGenParamsTemplate {
    val taps = Seq(0.toDouble)
  }
  val lineLength1Params:lineLengthGenParamsTemplate = new lineLengthGenParamsTemplate {
    val protoData = SInt(64.W)
    val windowSize = 5
  }
}

class wellnessGenIntegrationSpec extends FlatSpec with Matchers {
  behavior of "Wellness"


  // I am leaving this SInt implementation as is, since my testbench is meant for floats/fixedpoints
  it should "pass the input through filters (SInt)" in {

    val debug = 0

    val tap_count = 4
    val coefficients1 = Seq(1,2,3,4)

    val goldenModelParameters = new wellnessGenIntegrationParameterBundle {
      override val filter1Params: filterGenParamsTemplate = new filterGenParamsTemplate {
        val taps: Seq[Double] = coefficients1.map(_.toDouble)
      }
      override val lineLength1Params: lineLengthGenParamsTemplate = new lineLengthGenParamsTemplate {
        override val windowSize: Int = 4
      }
    }

    val wellnessGenParams1 = new wellnessGenParams[SInt] {
      val protoData = SInt(64.W)
    }


    wellnessGenIntegrationTesterSInt(wellnessGenParams1: wellnessGenParams[SInt],
      goldenModelParameters: wellnessGenIntegrationParameterBundle, debug) should be (true)
  }
}