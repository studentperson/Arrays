#!/bin/bash
# This is a comment
#By default ints don't print out leading 0's
#This is a test to print out leading zeroes for
	#easier sorting of files
for number in {1..200}
do
	((h = number / 100))
	((t = number / 10 % 10))
	((o = number % 10 ))
	#These two didn't work
	#echo "Hello"(($number / 100))(($number / 10 % 10))(($number % 10))
	#echo ((number / 100))
	echo "Hello"$h$t$o
done