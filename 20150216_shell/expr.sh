#! /bin/sh
a=8
b=9
var1=$a+$b
echo $var1

#使用expr来计算表达式
var2=`expr $a + $b` # 注意！‘+’两边必须要有空格否则仍旧无用
echo $var2
