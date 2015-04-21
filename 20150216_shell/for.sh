#! /bin/sh
sum=0

for i in 1 2 3 4 5;
do
	sum=`expr $sum + $i`
	#echo $i
done
echo $sum
