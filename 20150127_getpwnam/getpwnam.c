/*
 * getpid.c
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
	// 获取当前程序的进程id,以及父进程的进程id
	printf("pid = %d, ppid = %d\n", getpid(), getppid());

	char * login = NULL;
	struct passwd * pwd = NULL;

	login = getlogin();
	pwd = getpwnam("lennon");
	printf("login:%s\tpw_name:%s\tpw_passwd:%s\tpw_dir:%s\n", login, pwd->pw_name, pwd->pw_passwd, pwd->pw_dir);
	return 0;
}
