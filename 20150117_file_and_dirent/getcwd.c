#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buf[1024];
	memset(buf, 0, sizeof(buf));

	// 显示当前目录，并不是程序所在的目录
	char* ret = getcwd(buf, sizeof(buf));
	
	// 测试%m格式，相当于strerror(errno)
	open("abc", O_RDONLY);
	if(NULL != ret)
	{
		printf("%m\n");	
	}

	printf("%s\n", buf);

	return 0;
}

