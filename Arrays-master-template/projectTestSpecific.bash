#!/bin/sh
# for a command line shell script argument
# $0 is the shell script $1+ are the arguments
# make executable with chmod permissions scriptname
	# i.e. chmod 754 projectTestMain.bash
		# 4 read, 2 write, 1 execute, 0 none
		# permissions: user group other; 7 for user, 5 for group, 4 for other
		
#fvar0
toSort()
{
	#echo "start function test"
	#echo $1
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
			fvar0="null"
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}

#fvar0
toOrder()
{
	#echo "start function test"
	#echo $1
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
			fvar0="null"
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}

#fvar0
toLength()
{
	#echo "start function test"
	#echo $1
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
			fvar0=0
			echo "Error not in scope"
			;;
	esac
	#echo "end function test"
}
		
for countLength in {0..5..1}
do
	for countSort in {0..0..1}
	do
		for countOrder in {0..3..1}
		do
			
			toSort $countSort
			sorttype=$fvar0

			toOrder $countOrder
			order=$fvar0
			
			toLength $countLength
			length=$fvar0
			
			echo "Hello "$sorttype" "$order" "$length
			#Note the directory has to exist for it to save it there
			#./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
			
			if [ "$sorttype" != "null" ] && [ "$order" != "null" ] && [ "$length" -gt "0" ]
				then
					#Note the directory has to exist for it to save it there
					./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
					#echo "if success"
				else
					echo "skipped"
			fi
			
			echo "Bye "$sorttype" "$order" "$length
			echo ""
		done
	done
done

for countLength in {0..5..1}
do
	for countSort in {1..1..1}
	do
		for countOrder in {0..3..1}
		do
			
			toSort $countSort
			sorttype=$fvar0

			toOrder $countOrder
			order=$fvar0
			
			toLength $countLength
			length=$fvar0
			
			echo "Hello "$sorttype" "$order" "$length
			#Note the directory has to exist for it to save it there
			#./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
			
			if [ "$sorttype" != "null" ] && [ "$order" != "null" ] && [ "$length" -gt "0" ]
				then
					#Note the directory has to exist for it to save it there
					./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
					#echo "if success"
				else
					echo "skipped"
			fi
			
			echo "Bye "$sorttype" "$order" "$length
			echo ""
		done
	done
done

for countLength in {0..5..1}
do
	for countSort in {2..2..1}
	do
		for countOrder in {0..3..1}
		do
			
			toSort $countSort
			sorttype=$fvar0

			toOrder $countOrder
			order=$fvar0
			
			toLength $countLength
			length=$fvar0
			
			echo "Hello "$sorttype" "$order" "$length
			#Note the directory has to exist for it to save it there
			#./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
			
			if [ "$sorttype" != "null" ] && [ "$order" != "null" ] && [ "$length" -gt "0" ]
				then
					#Note the directory has to exist for it to save it there
					./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
					#echo "if success"
				else
					echo "skipped"
			fi
			
			echo "Bye "$sorttype" "$order" "$length
			echo ""
		done
	done
done

for countLength in {0..6..1}
do
	for countSort in {3..3..1}
	do
		for countOrder in {0..3..1}
		do
			
			toSort $countSort
			sorttype=$fvar0

			toOrder $countOrder
			order=$fvar0
			
			toLength $countLength
			length=$fvar0
			
			echo "Hello "$sorttype" "$order" "$length
			#Note the directory has to exist for it to save it there
			#./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
			
			if [ "$sorttype" != "null" ] && [ "$order" != "null" ] && [ "$length" -gt "0" ]
				then
					#Note the directory has to exist for it to save it there
					./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
					#echo "if success"
				else
					echo "skipped"
			fi
			
			echo "Bye "$sorttype" "$order" "$length
			echo ""
		done
	done
done

for countLength in {0..6..1}
do
	for countSort in {4..4..1}
	do
		for countOrder in {0..3..1}
		do
			
			toSort $countSort
			sorttype=$fvar0

			toOrder $countOrder
			order=$fvar0
			
			toLength $countLength
			length=$fvar0
			
			echo "Hello "$sorttype" "$order" "$length
			#Note the directory has to exist for it to save it there
			#./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
			
			if [ "$sorttype" != "null" ] && [ "$order" != "null" ] && [ "$length" -gt "0" ]
				then
					#Note the directory has to exist for it to save it there
					./projectTestHelper.bash $countSort $countOrder $length > ./results/$sorttype$order$countLength
					#echo "if success"
				else
					echo "skipped"
			fi
			
			echo "Bye "$sorttype" "$order" "$length
			echo ""
		done
	done
done
