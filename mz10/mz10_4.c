#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void kill_them_all(int *pid_arr, int n) {
    for (int t = 0; t < n; t++) {
        kill(pid_arr[t], SIGKILL);
        
    }
    free(pid_arr);
    close(0);
    while(wait(NULL) != -1);
}
void cls(int fd[2]) {
    close(fd[1]);
    close(fd[0]);
}
int main(int argc, char const *argv[])
{
    int fd[2];
    if (argc < 2) {
        return 0;
    }
    int *pid_arr = calloc(argc - 1, sizeof(*pid_arr));

    for(int t = 1; t < argc - 1; t++) {
        if (pipe(fd) == -1) {
            kill_them_all(pid_arr, t - 1);
            exit(1);
        }
        int pid = fork();
        
        if (pid == -1) {
            cls(fd);
            kill_them_all(pid_arr, t - 1);
            exit(1);
        }
        pid_arr[t - 1] = pid;
        if (!pid) {
            dup2(fd[1], 1);
            cls(fd);
            execlp(argv[t], argv[t], NULL);
            exit(1);
        } 
        if (dup2(fd[0], 0) == -1) {
            cls(fd);
            kill_them_all(pid_arr, t);
            exit(1);
        }
        cls(fd);
    }
    int pid = fork();
    if (pid == -1) {
        kill_them_all(pid_arr, argc - 1);
        return 1;
    }
    if (!pid) {
        execlp(argv[argc - 1], argv[argc - 1], NULL);
        exit(1);
    }
    close(0);
    while(wait(NULL) != -1);
    free(pid_arr);
    return 0;
}