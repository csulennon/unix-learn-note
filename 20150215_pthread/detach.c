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

	int rtn = pthread_create(&thrd1, NULL, func, &arg1);
	if (rtn != 0 )
	{
		printf("线程创建出错!错误:%d\n", rtn);
	}
	else 
	{
		printf("线程创建成功!\n");
	}
	
	pthread_create(&thrd2, NULL, func, &arg2);

	pthread_detach(thrd1);
	pthread_detach(thrd2);

	sleep(1);
/*
	int* val;
	pthread_join(thrd1, (void**)&val);
	printf("线程的返回值是:%d\n", *val);

	pthread_join(thrd2, (void**)&val);
	printf("线程的返回值是:%d\n", *val);
*/
	return EXIT_SUCCESS;
}
