#! /bin/sh

# 这种if语句常用来测试文件的
# -f 选项：测试文件是否存在
# -d 选项：测试是否为目录
# -r 选项：测试是否可读
# -w 选项：测试是否可写
# -x 选项：测试是否可执行
if [ -f $1 ]; then
	echo '文件已经存在了！'
else
	touch $1
	echo '创建文件'$1
fi
