#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void* func2(void * arg)
{
	pthread_t th = *(pthread_t*)arg;
	sleep(2);
	pthread_cancel(th);
	return NULL;
}

void * func(void * arg)
{
	pthread_mutex_lock(&mutex);
	int th = *(int*) arg;
	printf("线程%d正在运行...\n", th);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		count++;
		printf("线程%d running...%d\n", th, count);
		sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	printf("线程%d结束\n", th);
	pthread_exit(NULL);
	//return NULL;
}

int main()
{
	pthread_t thrd1, thrd2, thrd3;
	int arg[2] = { 1, 2 };
	pthread_create(&thrd1, NULL, func, &arg[0]);
	pthread_create(&thrd2, NULL, func, &arg[1]);
	pthread_create(&thrd3, NULL, func2, &thrd2);

	pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);

	return 0;
}

