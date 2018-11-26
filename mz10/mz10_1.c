#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void prnt(int fd[2], const char format[]){
    wait(NULL);
    time_t tm;
    close(fd[1]);
    read(fd[0], &tm, sizeof(tm));
    struct tm date;
    localtime_r(&tm, &date);
    char s[100];
    strftime(s, sizeof(s), format, &date);
    printf("%s\n", s);
}


int main(int argc, char const *argv[])
{   
    int fd[2];
    pipe (fd);
    if (!fork()) {
        if(!fork()) {
            if (!fork()) {
                time_t tm = time(NULL);
                for (int t = 0; t < 3; t++) {
                    close(fd[0]);
                    write(fd[1], &tm, sizeof(tm));
                }
            } else {
                prnt(fd, "D:%d");
            }
        } else {
            prnt(fd, "M:%m");
        }
    } else {
        prnt(fd, "Y:%Y");
    }
    close(fd[1]);
    close(fd[0]);
    return 0;
}