#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

void cls(int fd[2]){
    close(fd[0]);
    close(fd[1]);
}

int main(int argc, char const *argv[])
{
    if (argc < 6) {
        return 1;
    }
    int fd[2];
    pipe(fd);
    if (!fork()){
        

        dup2(fd[1], 1);
        cls(fd);
        if (!fork()) {
            int inp = open(argv[4], O_RDONLY);
            if (inp < 0) {
                return 1;
            }
            dup2(inp, 0);
            close(inp);
            execlp(argv[1], argv[1], NULL);
            exit(1);
        } 
        int s;
        wait(&s);
        if (WIFEXITED(s) && !WEXITSTATUS(s)) {
            if (!fork()) {
                execlp(argv[2], argv[2], NULL);
                exit(1);
            } 
        } 

        wait(NULL);
        return 0;
            
        
    } 
    if (!fork()) {
        dup2(fd[0], 0);
        cls(fd);
        int out = open(argv[5], O_APPEND | O_CREAT | O_WRONLY, 0660);
        if (out < 0){
            return 1;
        }
        dup2(out, 1);
        close(out);
        execlp(argv[3], argv[3], NULL);
        exit(1);
    }
    
    cls(fd);
    while (wait(NULL) != -1);
    return 0;
}

