#!/bin/sh
# for a command line shell script argument
# $0 is the shell script $1+ are the arguments
# make executable with chmod permissions scriptname
	# i.e. chmod 754 projectTestMain.bash
		# 4 read, 2 write, 1 execute, 0 none
		# permissions: user group other; 7 for user, 5 for group, 4 for other
for count00 in {0..4}
do
	for count01 in {0..3}
	do
		order="null"
		sorttype="null"
		length=0
		case $count00 in
			0)
				sorttype="sel"
				#echo $sorttype
				;;
			1)
				sorttype="ins"
				#echo $sorttype
				;;
			2)
				sorttype="bub"
				#echo $sorttype
				;;
			3)
				sorttype="mrg"
				#echo $sorttype
				;;
			4)
				sorttype="qik"
				#echo $sorttype
				;;
			*)
				echo "Error not in scope"
				;;
		esac
		case $count01 in
			0)
				order="rand"
				#echo $order
				;;
			1)
				order="sort"
				#echo $order
				;;
			2)
				order="rev"
				#echo $order
				;;
			3)
				order="part"
				#echo $order
				;;
			*)
				echo "Error not in scope"
				;;
		esac
		case $1 in
			0)
				length=1
				#echo $length
				;;
			1)
				length=10
				#echo $length
				;;
			2)
				length=100
				#echo $length
				;;
			3)
				length=1000
				#echo $length
				;;
			4)
				length=10000
				#echo $length
				;;
			5)
				length=100000
				#echo $length
				;;
			6)
				length=1000000
				#echo $length
				;;
			*)
				echo "Error not in scope"
				;;
		esac
		echo "Hello "$sorttype" "$order" "$length
		#Note the directory has to exist for it to save it there
		./projectTestHelper.bash $count00 $count01 $length > ./results/$sorttype$order$1
		echo "Bye "$sorttype" "$order" "$length
	done
done
