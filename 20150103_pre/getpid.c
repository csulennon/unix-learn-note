#include <stdio.h>
#include <unistd.h>

int 
main()
{
    printf("程序的进程id是：%d\n", getpid());
    exit(0);
}
