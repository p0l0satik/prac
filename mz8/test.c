#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int start_pr(char const * name) {
    if (!fork()) {
        execlp(name, name, NULL);
        exit(1);
    } else {
        int s;
        wait(&s);
        return WIFEXITED(s) && !WEXITSTATUS(s);
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 4) {
        return 1;
    }
    printf("%d\n", (start_pr(argv[1]) || start_pr(argv[2])) && start_pr(argv[3]));

    return 0;
}
