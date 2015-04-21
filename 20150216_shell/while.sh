#! /bin/sh
times=0
while [ "$times" != "5" ];
do
    echo $times
#   times=$[$times + 1] # 不知道为什么这种方式不行
	times=`expr $times + 1`
done
