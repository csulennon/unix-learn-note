#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main()
{
    printf("组id = %d, 用户id = %d\n", getgid(), getuid());
    exit(0);
}
