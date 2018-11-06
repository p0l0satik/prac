#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    for (int t = 1; t <= 3; t++){
        if (!fork()){
            char str[8];
            if (read(0, str, 8) != -1) {
                int a;
                sscanf(str, "%d", &a);
                printf("%d %d\n", t, a * a);
                fflush(stdout);
            }
            return 0;
        }
    }
    while(wait(NULL) != -1);

    return 0;
}