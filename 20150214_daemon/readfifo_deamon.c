#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void set_deamon();
void readfifo();


int main(int argc, char* argv[])
{
	readfifo();
//	set_deamon();
	return 0;
}

void readfifo()
{
	char buf[100];
	memset(buf, 0, sizeof(buf));

	int fd = open("/home/lennon/share/20150214/fifo1", O_RDONLY|O_NONBLOCK);
	printf("hello....");
	if(fd == -1)
	{
		printf("%m\n");
		exit(-1);
	}
	
	int len = 0;
	while((len = read(fd, buf, sizeof(buf))) > 0)
	{
		printf("%s\n", buf);
		memset(buf, 0, sizeof(buf));
	}
	close(fd);
}


void set_deamon()
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
		/*
		umask(0);
		chdir("/");
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		*/
		//syslog(LOG_INFO, "这是一条日志");
		while(1)
		{
			sleep(1);
		}
	}

	return ;
}

