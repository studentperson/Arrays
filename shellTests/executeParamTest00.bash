#!/bin/bash
# This is a comment
#command line arguments are represented by integers
#$0 is the shell script $1+ are the arguments
	#shellScript 3 1
		#$0 is shellScript, $1 is 3, $2 is 1
for number in {1..10}
do
	#./ means the directory that the shell script is currently in
	#a.exe is the executable name; any name will do
		#./executableName.exe
	./a.exe $number $1 $2 $3
done