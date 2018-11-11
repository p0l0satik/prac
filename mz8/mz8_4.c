#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int t = 1; t <= n; t++) {
        
        if (t == n ) {
            printf("%d\n", t);
        } else {
            printf("%d ", t);
        }
        fflush(stdout);
        if (t < n)  {
            if (fork()){
                wait(NULL);
                break;
            } 
        }

        
    }

    return 0;
}