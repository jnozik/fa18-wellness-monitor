# Wellness Generator

## Overview
To build a specific wellness monitor, a designer would describe specific desired features (e.g., line length, alpha bandpower, discrete wavelet transform, etc.), and the generator would build and connect the necessary filters, FFT blocks, feature extractors, and supplementary blocks. The generator would then connect the computed features to a PCA block followed by a SVM block. The principle is that each feature requires a particular datapath to compute a feature for the PCA from an input. For example, in order to extract the alpha bandpower, there would need to be a pre-filter, an FFT buffer, an FFT, and a bandpower block designed for the alpha band.

## Use
The actual wellness monitor generator in `WellnessGen.scala` receives its parameters from `WellnessParams.scala`. Within `WellnessParams.scala`, a designer would edit a parameter wrapper object to select desired features. For example, suppose the designer wants a wellness monitor of type `FixedPoint`. The designer would edit a few selected lines in the object `FixedPointWellnessGenParams`:
```
val nFFT: Int = 8
val dataWidth = 32
val dataBP = 8
```
* `nFFT` sets the number of FFT point, or equivalently, the window size for frequency domain features
* `dataWidth` sets the fixed point width
* `dataBP` sets the fixed point binary point

Then, suppose the designer wants a bandpower with a particular pre-filter and band:
```
val filterTapsA: Seq[Double] = Seq(1.0, 2.0, 3.0, 4.0, 5.0, 0.0)
datapathsArr += makeBandpower(
  channel = 0,
  filterType = "FIR",
  filterTapsA = filterTapsA,
  filterTapsA = filterTapsA,
  idxLowBin = 0,
  idxUpBin = 2
)
```
* `channel` sets the input channel (data srouce)
* `filterType` sets the filter type to either FIR (`"FIR"`) or IIR (`"IIR"`)
* `filterTapsA` sets the sequence of filter coefficients
  * For an IIR filter, this is the first set of coefficients (see [IIR filter](https://github.com/ucberkeley-ee290c/fa18-wellness-monitor/blob/master/doc/iir.md))
* `filterTapsB` sets the second sequence of filter coefficients
* `idxLowBin` sets the index of the lower frequency bound of the frequency range of interest (see [Bandpower](https://github.com/ucberkeley-ee290c/fa18-wellness-monitor/blob/master/doc/bandpower.md))
* `idxUpBin` sets the index of the upper frequency bound (exclusive) of the frequency range of interest

## Implementation Details
The first step to generating a wellness monitor is generating the parameter information for the entire system. Each object in `WellnessParams.scala` (e.g., `FixedPointWellnessGenParams`) contains functions to define parameter datapaths for different features (e.g., makeBandpower). In the object, these generated parameter datapaths are added to an array that, together with PCA, SVM, and configuration parameter information, thus defines the entire system.
Next, these parameters are passed into `wellnessGenModule` to generate the hardware. (Note that these parameters are passed all the way through all the layers of abstraction needed for RocketChip integration.) In this class, each datapath is then generated by iterating through each parameter datapath and instantianting the appropriate blocks with the appropriate parameters. Then, each datapath is properly connected together, with the wellness monitor inputs connected to the datapaths and the datapath outputs connected to the PCA. The PCA output feeds into the SVM output, which outputs the classification to RocketChip.

## To Do
There are many features and optimizations that can be made to improve the wellness monitor generator. For example, the generator could allow frequency domain feature definitions to also define the number of FFT points desired. In terms of optimization, the current implementation can potentially produce many duplicate blocks. This hardware inefficiency can be avoided by first reducing the array of parameter datapaths to a tree of parameter datapaths before module generation and connection. The challenge is creating an appropriate tree structure to contain the generated modules for easy access for connection.