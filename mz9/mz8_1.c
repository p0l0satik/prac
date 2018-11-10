#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum 
{
    THE_
};
int main(int argc, char const *argv[])
{
    if (argc < 5) {
        return 1;
    }
    
    if (!fork()) {
        int fd2 = open(argv[3], O_WRONLY|O_APPEND|O_CREAT,0660);
        int fd3 = open(argv[4], O_WRONLY|O_TRUNC|O_CREAT, 0660);
        int fd1 = open(argv[2], O_RDONLY);
        if (fd1 == -1 || fd2 == -1 || fd3 == -1) {
            return 42;
        }
        if (dup2(fd1, 0) < 0 || dup2(fd2, 1) < 0 || dup2(fd3, 2) < 0) {
            return 42;
        }
        execlp(argv[1], argv[1], NULL);
        return 42;  
    } else {
        int status;
        wait(&status);
        printf("%d\n", status);

    }
    return 0;
}
