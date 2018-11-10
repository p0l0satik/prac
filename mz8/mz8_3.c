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

int main(void)
{
    for (int t = 1; t <= NUMBER_OF_PROCESSES; t++) {
        if (!fork()) {
            char str[LEN_OF_STR];
            if (read(0, str, LEN_OF_STR) != -1) {
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