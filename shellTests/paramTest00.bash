#!/bin/sh
#testing line arguments
# $0 is the shell script $1+ are the arguments
# currently the parameters don't do anything
# other than print stuff out
for number in {0..3}
do
	order="null"
	order00="null"
	sorttype="null"
	length=0
	#switch statement; should work for things other than int
	case $number in
		0)
			order="rand"
			echo $order
			;;
		1)
			order="sort"
			echo $order
			;;
		2)
			order="revs"
			echo $order
			;;
		3)
			order="part"
			echo $order
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	case $1 in
		0)
			sorttype="bub"
			echo $sorttype
			;;
		1)
			sorttype="ins"
			echo $sorttype
			;;
		2)
			sorttype="sel"
			echo $sorttype
			;;
		3)
			sorttype="mrg"
			echo $sorttype
			;;
		4)
			sorttype="qik"
			echo $sorttype
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	case $2 in
		0)
			order00="rand"
			echo $order00
			;;
		1)
			order00="sort"
			echo $order00
			;;
		2)
			order00="rev"
			echo $order00
			;;
		3)
			order00="part"
			echo $order00
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	case $3 in
		0)
			length=10
			echo $length
			;;
		1)
			length=100
			echo $length
			;;
		2)
			length=1000
			echo $length
			;;
		3)
			length=10000
			echo $length
			;;
		4)
			length=100000
			echo $length
			;;
		5)
			length=1000000
			echo $length
			;;
		*)
			echo "Error not in scope"
			;;
	esac
	echo "Hello "$order" "$order00" "$sorttype" "$length
done
