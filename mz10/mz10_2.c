#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


enum 
{
    CH_OP = 2
};

int main(int argc, char const *argv[])
{   
    int fd[CH_OP];
    long long int sum = 0;
    pipe (fd);
    if (!fork()) {
        if(!fork()) {
            close(fd[1]);
            int a;
            int flag;
            while ( (flag = read(fd[0], &a, sizeof(a)) ) == sizeof(a)) {
                sum += a;
            }
            printf("%lld\n", sum);
            return 0;
        } else {
            close(fd[1]);
            close(fd[0]);
        }
    } else {
        close(fd[0]);
        int a;
        while (scanf("%d", &a) == 1) {
            if (write(fd[1], &a, sizeof(a)) != sizeof(a)) {
                return 1;
            }
            
        }
        close(fd[1]);
    }
    wait(NULL);
    
    return 0;
}