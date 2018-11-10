#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

enum
{
    NUMBER_OF_PROCESSES = 3
};

int main(int argc, char const *argv[])
{
    int n = NUMBER_OF_PROCESSES;
    for (int t = 1; t <= n; t++) {
            
            if (t < n) {
                if (fork()){
                    wait(NULL);
                    if (t == 1) {
                        printf("%d\n", t);
                    } else {
                        printf("%d ", t);
                    }
                    
                    break;
                }
            } else {
                printf("%d ", t);
            }
    }
    return 0;
}