#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
volatile int fl = 0;
void sg (int p) {
    signal(SIGUSR1, sg);
    printf("%d\n", getpid());
    fl = 1;
}
int main(int argc, char const *argv[])
{
    int fd[2];
    pipe(fd);
    int file = open("tes.txt", O_RDONLY);
    int pid1 = fork();
    signal(SIGUSR1, sg);
    if (!pid1) {
        char a;
        int pid2 = getpid();
        int pid1;
        printf("ddd\n");
        read(fd[0], &pid1, sizeof(pid1));

        printf("%d %d\n", pid1, pid2);
        close(fd[0]);
        close(fd[1]);
        
        fl = 0;
        int t = 1;
        while (t == 1) {
            // printf("ddd\n");
            if (fl) {
                t = read(file, &a, sizeof(a)); 
                fl = 0;
                // if (t == 1) { 
                    printf("%d %c\n", getpid(), a);
                // }
                kill(pid1, SIGUSR1);
            }
        } 
        
        close(file);
        return 0;
    } else {
        if (!fork()){
            char a;
            printf("%d\n", pid1);
            int pid2 = getpid();
            write(fd[1], &pid2, sizeof(pid2));
            close(fd[0]);
            close(fd[1]);

            fl = 1;
            int t = 1;
            while (t == 1) {
                // printf("fff\n");
                if (fl) {
                    t = read(file, &a, sizeof(a)); 
                    fl = 0;
                    // if (t == 1) {
                        printf("%d %c\n", getpid(), a);

                    // }
                    kill(pid1, SIGUSR1);
                }
            }   
            close(file);
            
            return 0;
        }
    }
    
    close(file);
    while(wait(NULL) != -1);

    return 0;
}