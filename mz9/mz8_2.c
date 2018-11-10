#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int mysys(const char *str) {
    int pid = fork();
    if (pid < 0) {
        return -1;
    }
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", str, (char *) 0);
        _exit(127);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFSIGNALED(status)) {
            return 128 + WTERMSIG(status);
        } else {
            return WEXITSTATUS(status);
        } 
    }

}
