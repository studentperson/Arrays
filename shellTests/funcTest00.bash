#!/bin/sh
#To test line arguments sent into the script
# $0 is the shell script $1+ are the arguments
	# currently the parameters don't do anything
	# other than print stuff out
	
#functions cannot return a good amount of values
#in order to "return" a value they have to share
	#a global variable
#they can take an input but can't give an output

#fvar0
funcTest()
{
	echo "start function test"
	echo $1
	echo $2
	echo "end function test"
}

#varToSort #may want to create unique variable for recursion
#fvar0
toSort()
{
	#echo "start function test"
	echo $1
	case $1 in
		0)
			fvar0="sel"
			;;
		1)
			fvar0="ins"
			;;
		2)
			fvar0="bub"
			;;
		3)
			fvar0="mrg"
			;;
		4)
			fvar0="qik"
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}

#fvar0
toOrder()
{
	#echo "start function test"
	echo $1
	case $1 in
		0)
			fvar0="rand"
			;;
		1)
			fvar0="sort"
			;;
		2)
			fvar0="rev"
			;;
		3)
			fvar0="part"
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}

#fvar0
toLength()
{
	#echo "start function test"
	echo $1
	case $1 in
		0)
			fvar0=1
			;;
		1)
			fvar0=10
			;;
		2)
			fvar0=100
			;;
		3)
			fvar0=1000
			;;
		4)
			fvar0=10000
			;;
		5)
			fvar0=100000
			;;
		6)
			fvar0=1000000
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}
	
for number in {0..0}
do
	order="null"
	sorttype="null"
	length=0

	toSort $1
	sorttype=$fvar0

	toOrder $2
	order=$fvar0
	
	toLength $3
	length=$fvar0

	echo "Hello "$sorttype" "$order" "$length
	#funcTest $sorttype $order
done
