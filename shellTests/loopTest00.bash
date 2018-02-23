#!/bin/bash
# This is a comment
#This is just testing loops
	#{start..end..interval}
		#{start..start} just runs the loop once
for number in {1..10..2}
do
	echo $number
done