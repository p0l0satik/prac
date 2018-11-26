#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum 
{   
    NUMBER_OF_ARGS = 5,
    INP = 2,
    OUTP = 3, 
    ERR = 4,
    DEEP_THOUGHT_ANSWER = 42,
    INP_STREAM = 0,
    OUTP_STREAM = 1,
    ERR_STREAM = 2,
    RIGHTS = 0660
};
int main(int argc, char const *argv[])
{
    if (argc < NUMBER_OF_ARGS) {
        return 1;
    }
    
    if (!fork()) {
        int fd2 = open(argv[OUTP], O_WRONLY|O_APPEND|O_CREAT, RIGHTS);
        int fd3 = open(argv[ERR], O_WRONLY|O_TRUNC|O_CREAT, RIGHTS);
        int fd1 = open(argv[INP], O_RDONLY);
        if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
            return DEEP_THOUGHT_ANSWER;
        }
        if (dup2(fd1, INP_STREAM) < 0 || dup2(fd2, OUTP_STREAM) < 0 || dup2(fd3, ERR_STREAM) < 0) {
            return DEEP_THOUGHT_ANSWER;
        }
        execlp(argv[1], argv[1], NULL);
        return DEEP_THOUGHT_ANSWER;  
    } else {
        int status;
        wait(&status);
        printf("%d\n", status);
    }
    return 0;
}
