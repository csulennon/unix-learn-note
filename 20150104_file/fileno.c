#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fp1, fp2;

    /* ��������ļ����ļ������� */
    printf("stdin is:\t %d\n", fileno(stdin));// ��׼�����豸
    printf("stdout is:\t %d\n", fileno(stdout));// ��׼����豸
    printf("stderr is:\t %d\n", fileno(stderr));// ��׼�����豸


    // ���ļ����������򱨴�
    if((fp1 = open("/home/lennon/share/dev/apue/chapter03/test.txt", O_WRONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // ����һ���ļ����������򱨴�
    if((fp2 = open("/home/lennon/share/dev/apue/chapter03/test2.txt", O_WRONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("test.txt is :\t%d\n", fp1);
    printf("test2.txt is :\t%d\n", fp2);

    close(fp1);
    close(fp2);

    exit(0);
}