#include <stdio.h>
#include <unistd.h>
// #include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

volatile int a = 0;

enum
{
    LAST_SIG = 5
};

void sig(int par) {
    signal(SIGHUP, sig);
    if (a < LAST_SIG) {
        printf("%d\n", a);
        fflush(stdout);
        a++;
        
    } else {
        exit(0);
    }
}
int main(int argc, char const *argv[])
{
    signal(SIGHUP, sig);
    printf("%d\n", getpid());
    fflush(stdout);

    while(1){
        pause();
    }
    
    return 0;
}