#! /bin/sh
# ""或者''引起来的是字符串，``之间的表示命令
echo "今天是："`date`

# 也可以使用变量的方式
DATE=`date`
echo '今天是：'$DATE

