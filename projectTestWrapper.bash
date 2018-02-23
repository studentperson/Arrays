#!/bin/sh
# make executable with chmod permissions scriptname
	# i.e. chmod 754 projectTestMain.bash
		# 4 read, 2 write, 1 execute, 0 none
		# permissions: user group other; 7 for user, 5 for group, 4 for other
#To be used with projectTestMain.bash and projectTestHelper.bash
#{start..end} includes the start and end index
#The main purpose is so that the sort ones could be separated from
#the long ones and you can run the long routines together without having to
#manually reenter the shell script
#{0..0} means you are just running the first length
#{0..3} shortish
#{4..5} long 5 is super long
for count00 in {0..0}
do
	#echo "Hello "$sorttype" "$order" "$length
	./projectTestMain.bash $count00
done
