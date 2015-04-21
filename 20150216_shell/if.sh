#! /bin/sh
if (test "start" = "$1") then # 测试条件的=两边要有空格，否则就是永远为真了
	echo "让我们开始吧！"
else
	echo "你要说start我才会开始！"
fi
