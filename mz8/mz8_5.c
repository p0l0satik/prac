
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

enum
{
    NUMBER_OF_PROCESSES = 3,
    LEN_OF_STR = 8
};
int i = 0;
int main(void)
{   
    int a;
    while(1){
        int pid = fork();
        if (pid == -1) {
            printf("-1\n");
            return -1;
        } else if (!pid) {
            
            if(scanf("%d", &a) != 1) {
                return 0;
            }
        } else {
            int status;
            wait(&status);
            if (WEXITSTATUS(status) != 0) {
                if (!i) {
                    return 0;
                } else {
                    return -1;
                }
                
            }
            if (i) {
                printf("%d\n", a);
            }            
            return 0;
        }
        i++;
    }

    return 0;
}