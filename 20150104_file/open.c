#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd_open, fd_open_create, fd_create;
    
    
    /* ������һ���ļ� */
    if((fd_open = open("/bin/ls", O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("The file's descriptor is :%d\n", fd_open);
    
    /* �򿪲������������򱨴� */
    if((fd_open_create = open("./tmp1", O_CREAT | O_EXCL, 0644)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("The temp1 file descriptor is :%d\n", fd_open_create);
    
    /* ���� */
    if((fd_create = creat("./tmp2", 0644) ) == -1) {
        perror("create");
        exit(EXIT_FAILURE);
    }
    printf("The temp2 file descriptor is :%d\n", fd_create);
    
    // �ر��ļ�
    close(fd_open);
    close(fd_open_create);
    close(fd_create);
    
    return 0;
}