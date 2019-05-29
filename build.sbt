scalacOptions ++= Seq(
  "-Xsource:2.11",
  "-deprecation",
  "-explaintypes",
  "-feature",
  "-language:reflectiveCalls",
  "-Xcheckinit",
  "-Xlint:infer-any",
  "-Xlint:missing-interpolator",
  "-Ywarn-unused:imports",
  "-Ywarn-unused:locals",
  "-Ywarn-value-discard",
)

parallelExecution in Test := false

libraryDependencies ++= Seq(
  "edu.berkeley.cs" %% "rocket-dsptools" % "1.2-031419-SNAPSHOT"
)

resolvers ++= Seq(
  Resolver.sonatypeRepo("snapshots"),
  Resolver.sonatypeRepo("releases")
)

name := "ee290c"
organization := "edu.berkeley.cs"
version := "0.1-SNAPSHOT"
scalaVersion := "2.12.8"
