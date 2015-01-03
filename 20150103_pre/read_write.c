#include "lennon.h"
#define BUFFER_SIZE  4096

int main()
{
    int n;
    char buf[BUFFER_SIZE];
    
    // STDIN_FILENO = 0, STDOUT_FILENO = 1
    // 他们再unistd.h中被定义
    while((n = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error!\n");
        }
    }
    
    if(n < 0) 
    {
        printf("read error!");
    }
    
    exit(0);
}


