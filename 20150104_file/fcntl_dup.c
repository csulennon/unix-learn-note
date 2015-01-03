#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *ptr = "helloworld\n";
    int fd_open, fd_dup;
    if((fd_open = open("tmp1", O_WRONLY|O_CREAT, 0644)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    // 复制文件描述符
    fd_dup = fcntl(fd_open, F_DUPFD);
    
    printf("fd_open = %d, fd_dup = %d\n", fd_open, fd_dup);
    printf("write %d bytes to fd_open\n", write(fd_open, ptr, strlen(ptr)));// 写入内容
    printf("write %d bytes to fd_dup\n", write(fd_dup, ptr, strlen(ptr)));// 写入内容
    
    close(fd_open);
    close(fd_dup);
    
    printf("now the content of the file:\n");
    system("cat tmp1");

    return 0;
}