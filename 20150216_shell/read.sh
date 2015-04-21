#! /bin/sh

echo 请输入被加数：
read a
echo 'a='$a

echo 请输入加数：
read b
echo 'b='$b

echo `expr $a + $b`


