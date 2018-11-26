#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }
    int pid = getpid();
    char s[PATH_MAX], s1[PATH_MAX];
    char *dir;
    if ((dir = getenv("TMPDIR")) == NULL) {
        if ((dir = getenv("XDG_RUNTIME_DIR")) == NULL) {
            char s2[] = "/tmp";
            dir = s2; 
        }
    }
    
    snprintf(s, PATH_MAX, "%sp%d.py", dir, pid);
    int py = open(s, O_WRONLY|O_CREAT|O_TRUNC, 0700);
    write(py, "print(1", strlen("print(1"));
    for (int t = 1; t < argc; t++) {
        write(py, "*", 1);
        write(py, argv[t], strlen(argv[t]));
    }
    write(py, ")", 1);
    close(py);

    snprintf(s, PATH_MAX, "%ss%d.sh", dir, pid);
    int sc = open(s, O_WRONLY|O_CREAT|O_TRUNC, 0700);
    snprintf(s1, PATH_MAX, "#! /bin/bash\npython3 %sp%d.py\nrm %sp%d.py\nrm $0", dir, pid, dir, pid);
    write(sc, s1, strlen(s1));
    close(sc);
    execlp("sh", "sh", s, NULL);
    
    return 0;
}