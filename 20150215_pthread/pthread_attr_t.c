#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* func(void *arg)
{
	int argue = *(int*)arg;
	printf("线程%d运行...\n", argue);
	int * rtn_val = malloc(sizeof(int));
	*rtn_val = argue * 100;
	return rtn_val;
}

int main(int argc, char* argv[])
{
	pthread_t thrd1, thrd2;
	int arg1 = 10;
	int arg2 = 20;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int rtn = pthread_create(&thrd1, &attr, func, &arg1);
	if (rtn != 0 )
	{
		printf("线程创建出错!错误:%d\n", rtn);
	}
	else 
	{
		printf("线程创建成功!\n");
	}
	
	pthread_create(&thrd2, NULL, func, &arg2);

	pthread_attr_destroy(&attr);

	// 线程1已经分离,主线程join无效,会立即返回.
	pthread_join(thrd1, NULL);


	return EXIT_SUCCESS;
}
