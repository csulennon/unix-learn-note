#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* FILE �� �ļ�������֮���ת�� */
int main(int argc, char* argv[])
{
    int fd;
    FILE* stream;
    unlink("test.txt");
    
    // �򿪻��ߴ����ļ������ƶ�Ȩ��
    fd = open("test.txt", O_CREAT| O_WRONLY | S_IREAD | S_IRGRP | S_IWRITE);
    
    // ����ת������
    stream = fdopen(fd, "w"); // ��O_WRONLYģʽ��
    if(stream == NULL) {
        printf("fdopen ����.\n");
    } else {
        fprintf(stream, "Hello world!\n");
        fclose(stream);
    }
    printf("The conten of the test.txt is:\n");
    system("cat test.txt");
    
    return 0;
}