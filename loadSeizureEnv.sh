#!/bin/bash
# Load the seizure detection modules from src/main/scala/seizureDetection*
# Also load the corresponding test environment from src/test/scala/seizureDetection*
# For Adel use
# Use with caution, it overwrites some important files 

# From the stash folders, put the files in the main directory

if [ $# -eq 0 ]; then
	echo "No arguments provided! Check the script"
else
	check=0
	if [ $1 = "logistic" ]; then
		check=1
		cp src/main/scala/seizureDetectionLogistic/* src/main/scala/
		cp src/test/scala/seizureDetectionLogistic/* src/test/scala/
	elif [ $1 = "rf" ]; then
		check=1
		cp src/main/scala/seizureDetectionRF/* src/main/scala/
		cp src/test/scala/seizureDetectionRF/* src/test/scala/
	elif [ $1 = "nn" ]; then
		check=1
		cp src/main/scala/seizureDetectionNN/* src/main/scala/
		cp src/test/scala/seizureDetectionNN/* src/test/scala/
	elif [ $1 = "svm" ]; then
		check=1
		cp src/main/scala/seizureDetectionSVM/* src/main/scala/
		cp src/test/scala/seizureDetectionSVM/* src/test/scala/
	elif [ $1 = "gen" ]; then
		cp src/main/scala/previousWellnessGenLogistic/* src/main/scala

		if [ -f "src/main/scala/Wellness.scala" ]; then
			rm src/main/scala/Wellness.scala
		fi
		
		FILE=src/main/scala/ConfigurationMemory.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/Main.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/WellnessGen.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/WellnessParams.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		cp src/test/scala/previousWellnessGenLogistic/* src/test/scala

		if [ -f "src/test/scala/WellnessIntegrationSpec.scala" ]; then
			rm src/test/scala/WellnessIntegrationSpec.scala
			rm src/test/scala/WellnessIntegrationTester.scala
		fi

		FILE=src/test/scala/ConfigurationMemorySpec.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/test/scala/ConfigurationMemoryTester.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/test/scala/WellnessGenIntegrationSpec.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/test/scala/WellnessGenIntegrationTester.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		echo "Reverted to Generator config"
	else
		echo "Wrong arguments given! Check the script"
	fi

	if [ $check = 1 ]; then
		# If ConfigurationMemory testers are present, delete it
		if [ -f "src/test/scala/ConfigurationMemorySpec.scala" ]; then
			rm src/test/scala/ConfigurationMemory*
		fi

		# If WellnessGen exists, delete it
		if [ -f "src/test/scala/WellnessGenIntegrationSpec" ]; then
			rm src/test/scala/WellnessGen*
			rm src/main/scala/WellnessGen.scala
		fi

		# Now remove the 1st and last lines of added files, to uncomment the blocks
		FILE=src/main/scala/ConfigurationMemory.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/Main.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/Wellness.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/main/scala/WellnessParams.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/test/scala/WellnessIntegrationSpec.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"

		FILE=src/test/scala/WellnessIntegrationTester.scala
		tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
		head -n -1 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE"
	
		echo "Done replacing files, check it out"
	fi
fi

