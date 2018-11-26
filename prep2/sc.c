#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
volatile int fd[2];
volatile int n;
volatile int pid1, pid2;
void sg1(int p) {
    signal(SIGUSR1, sg1);
    printf("1\n");
    int a;
    read(fd[0], &a, sizeof(a));
    printf("1 %d\n", a);
    a++;
    if (a > n) {
        close(fd[0]);
        close(fd[1]);
        exit(0);
    } else { 
        write(fd[1], &a, sizeof(a));
        kill(pid2, SIGUSR1);
    }
}
void sg2(int p) {
    signal(SIGUSR1, sg2);
    printf("2\n");
    int a;
    read(fd[0], &a, sizeof(a));
    printf("1 %d\n", a);
    a++;
    if (a > n) {
        close(fd[0]);
        close(fd[1]);
        exit(0);
    } else { 
        write(fd[1], &a, sizeof(a));
        kill(pid1, SIGUSR1);
    }
}

int main(int argc, char const *argv[])
{   
    
    sscanf(argv[1], "%d", &n);
    pipe((int *)fd);
    pid1 = fork();

    sigset_t s1, s2;
    sigemptyset(& s1);
    sigaddset(&s1, SIGUSR1);
    sigprocmask(SIG_BLOCK, &s1, &s2);

    if (!pid1){
        signal(SIGUSR1, sg1);
        int pd2 = (int) pid2;

        read(fd[0], &pd2, sizeof(pd2));
        
        while(1)sigsuspend(&s1);

    } else {
        pid2 = fork();
        
        if (!pid2) {
            
            signal(SIGUSR1, sg2);
            
            
            
            while(1)sigsuspend(&s1);
        }
        int pd2 = (int)pid2;
        write(fd[1], &pd2, sizeof(pd2));
        int a = 1;
        write(fd[1], &a, sizeof(a));
        kill(pid1, SIGUSR1);

    }
    return 0;
}
