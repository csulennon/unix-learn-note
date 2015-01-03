#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* FILE 和 文件描述符之间的转换 */
int main(int argc, char* argv[])
{
    int fd;
    FILE* stream;
    unlink("test.txt");
    
    // 打开或者创建文件，并制定权限
    fd = open("test.txt", O_CREAT| O_WRONLY | S_IREAD | S_IRGRP | S_IWRITE);
    
    // 以下转换成流
    stream = fdopen(fd, "w"); // 用O_WRONLY模式打开
    if(stream == NULL) {
        printf("fdopen 出错.\n");
    } else {
        fprintf(stream, "Hello world!\n");
        fclose(stream);
    }
    printf("The conten of the test.txt is:\n");
    system("cat test.txt");
    
    return 0;
}