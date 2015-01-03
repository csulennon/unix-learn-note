#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINES 4096

int main()
{
    char    buf[MAX_LINES] ;
    pid_t   pid;
    int     status;
    
    printf("%% ");

    while(fgets(buf, MAX_LINES, stdin) != NULL) {
        
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = '\0';
        }
        
        if((pid = fork()) < 0) {
            fprintf(stderr, "创建子进程出错!\n");
        } else if(pid == 0) { /* 子进程 */
            execlp(buf, buf, (char*)0);
            fprintf(stderr, "不能执行%s命令!\n", buf);
            exit(127);
        }
        
        /* parent */
        if((pid = waitpid(pid, &status, 0)) < 0) {
            fprintf(stderr, "waitepid error!\n");
        }
        
        printf("%% ");
    }
    
    
    
    
    exit(0);
}
