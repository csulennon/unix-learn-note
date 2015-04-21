#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// 使用无名管道进行进程间通信
// 使用范围是有关系(父子进程)的两个进程
int main()
{
	int fd[2];
	int len;
	char buf[100];

	int rtn = pipe(fd);
	bzero(buf, sizeof(buf));

	if(rtn == -1)
	{
		printf("%m\n");
		exit(-1);
	}

	int pid = fork();
	if(pid == 0)
	{
		// 子进程
		close(fd[1]);
		while((len = read(fd[0], buf, sizeof(buf))) > 0)
		{
			write(STDOUT_FILENO, buf, len);
		}
	}
	else
	{
		// 父进程
		close(fd[0]);
		sprintf(buf, "%s\n", "hello, pipe!");
		write(fd[1], buf, strlen(buf));
		close(fd[1]);
		waitpid(pid, NULL, 0);// 等待子进程退出
	}


	return 0;
}

