#!/bin/sh

for number in {0..4}
do
	order="null"
	#Works with things other than int
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
			order="rev"
			echo $order
			;;
		3)
			order="part"
			echo $order
			;;
		#The catch all clause
		*)
			echo "Error not in scope"
			;;
	esac

	echo "Hello "$order
done
