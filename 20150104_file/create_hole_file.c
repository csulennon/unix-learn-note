#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main()
{
    int fd      =   0;
    if((fd = creat("file.hole", FILE_MODE)) < 0) {
        fprintf(stderr, "creat file error!\n");
    }
    
    if(write(fd, buf1, 10) != 10) {
        fprintf(stderr, "write buf1 error!\n");
    }
    
    //printf("current seek position:%d\n", )
    
    /* 移动文件指针 */
    if(lseek(fd, 16384, SEEK_SET) == -1) {
        fputs("seek error!\n", stderr);
    }
    
    if(write(fd, buf2, 10) != 10) {
        fprintf(stderr, "write buf2 error!\n");
    }
    
    exit(0);
    
}

