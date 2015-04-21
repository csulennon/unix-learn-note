#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* func(void *arg)
{
	printf("线程运行...\n");
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t thrd;
	int rtn = pthread_create(&thrd, NULL, func, NULL);
	if (rtn != 0 )
	{
		printf("线程创建出错!错误:%d\n", rtn);
	}
	else 
	{
		printf("线程创建成功!\n");
	}

	usleep(30);

	return EXIT_SUCCESS;
}
