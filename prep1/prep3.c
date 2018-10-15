#include <dirent.h>
#include <limits.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);
    int fd3 = open(argv[3], O_WRONLY);

    double a, b;
    while (read(fd1, &a, sizeof(a)) || read(fd2, &b, sizeof(b))) {
        if (a > b) {
            write(fd3, &a, sizeof(a));
            while(read(fd1, &a, sizeof(a))) {
                write(fd3, &a, sizeof(a));
            }
        }
        if (b >= a) {
            write(fd3, &b, sizeof(b));
            while(read(fd2, &b, sizeof(b))) {
                write(fd3, &b, sizeof(b));
            }
        }
    }
    return 0;
}