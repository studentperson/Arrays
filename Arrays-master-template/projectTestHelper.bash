#!/bin/bash
# This is a comment
#parameters are 1 sorting algorithms, 2 order type, 3 length
#1 0-4, 2 0-3, 3 0-infinity(int limit)
# make executable with chmod permissions scriptname
	# i.e. chmod 754 projectTestMain.bash
		# 4 read, 2 write, 1 execute, 0 none
		# permissions: user group other; 7 for user, 5 for group, 4 for other
for number in {1..100}
do
	#./a.exe $number 
	./a.exe $number $1 $2 $3
	#echo $number" "$1" "$2" "$3
done