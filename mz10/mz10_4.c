#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>


#include <signal.h>

void cls(int fd[2]){
    close(fd[0]);
    close(fd[1]);
}


int main(int argc, char const *argv[])
{   
    if (argc == 1) {
        return 0;
    }
    int *pids = calloc(argc, sizeof(int));


    int fd[2];
    for (int t = 1; t < argc - 1; t++) {
        pipe(fd);
        int pid =  fork();
        if (pid == -1) {
            for(int i = 1; i < t - 1; i++) {
                if (!waitpid(pids[i], NULL, WNOHANG)) {
                    kill(pids[i], SIGKILL);
                }
            }
            free(pids);
            cls(fd);
            return 1;
        } else {
            pids[t] = pid;
        }
        if(!pid) {
            dup2(fd[1], 1);
            cls(fd);
            execlp(argv[t], argv[t], NULL);
            _exit(1);
        } else {
            dup2(fd[0], 0);
            cls(fd);
        }
    }
    int pid = fork();

    if (pid == -1) {
        for(int i = 0; i < argc - 1; i++) {
            if (!waitpid(pids[i], NULL, WNOHANG)) {
                kill(pids[i], SIGKILL);
            }
        }
        free(pids);
        cls(fd);
        return 1;
    }
    if (!pid) {
        execlp(argv[argc - 1], argv[argc - 1], NULL);
        _exit(1);
    }
    while(wait(NULL) != -1);
    free(pids);
   
    return 0;
}