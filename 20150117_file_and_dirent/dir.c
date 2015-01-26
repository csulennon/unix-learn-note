/*
 * dir.c
 *
 *  Created on: Jan 17, 2015
 *      Author: lennon
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("参数错误:使用方式:main dirname.\n");
		return 0;
	}

	DIR * dp = NULL;
	struct dirent* dirp = NULL;
	dp = (DIR*)opendir(argv[1]);

	while((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n",dirp->d_name);
	}
	closedir(dp);

	return 0;
}

