#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void test()
{
	int * i = NULL;
	*i = 2;
}

void main()
{
	printf("pid = %d\n", getpid());
	printf("1 + 2 = %d\n", add(1,2));	
	test();

}
