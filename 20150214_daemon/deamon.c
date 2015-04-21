#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>

/*
 * 创建一个守护进程的步骤:
 * 1. fork一个进程
 * 2. 父进程退出
 * 3. 调用setsid()函数,新建一个会话
 * 4. 调用chdir()改变当前目录为根目录
 * 5. 设置umask()为0
 * 第4/5两步不是必须,但是推荐.保证程序的健壮性.
 */
int main(int argc, char* argv[])
{

	int pid = fork();
	if(pid < 0)
	{
		printf("%m\n");
		exit(-1);
	}
	else if(pid > 0)
	{
		exit(0);
	}
	else
	{
		setsid();
		umask(0);
		chdir("/");
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		
		syslog(LOG_INFO, "这是一条日志");
		while(1)
		{
			sleep(1);
			//printf("hello\n");
		}
	}

	return 0;
}
