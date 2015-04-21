/*
 * fok.c
 *
 *  Created on: 2015年1月27日
 *      Author: lennon
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(void)
{
	printf("begin...\n");
	pid_t child = fork();

	if (child == -1)
	{
		printf("进程创建失败!%m\n");
	}
	else if (child == 0)
	{
		printf("子进程:pid = %d, ppid = %d\n", getpid(), getppid());
	} else {
		printf("父进程:pid = %d, ppid = %d\n", getpid(), getppid());
	}
	printf("end...\n");

	return EXIT_SUCCESS;
}
