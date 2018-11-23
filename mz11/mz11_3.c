#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{   
    int n;
    if (sscanf(argv[1], "%d", &n)!= 1) 
    {
        return 1;
    }
    int sum = 0;
 
    for(int t = 2; (t < n + 2) && (t < argc); t++) {
        FILE *f = fopen(argv[t], "r");
        if (!f) {
            continue;
        }
        char s[PATH_MAX];
        fgets(s, PATH_MAX, f);
        if (s[strlen(s) - 1] == '\n') {
            s[strlen(s) - 1] = 0;
        }
        fclose(f);
        if (!fork()){
            execlp(s, s, NULL);
            exit(0);
        }
    }
    int status;
    while(wait(&status) != -1) {
        if (WIFEXITED(status) && !WEXITSTATUS(status)) {
            sum++;
        }
    }
    for( int t = n + 2; t < argc; t++) {
        FILE *f = fopen(argv[t], "r");
        if (!f) {
            continue;
        }
        char s[PATH_MAX];
        fgets(s, PATH_MAX, f);
        if (s[strlen(s) - 1] == '\n') {
            s[strlen(s) - 1] = 0;
        }
        fclose(f);
        if (!fork()){
            execlp(s, s, NULL);
            exit(0);
        }
        wait(&status);
        if (WIFEXITED(status) && !WEXITSTATUS(status)) {
            sum++;
        }

    }
    printf("%d\n", sum);
    return 0;
}