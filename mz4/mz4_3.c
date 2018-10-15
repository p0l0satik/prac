#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

unsigned long long hash_function(unsigned long long);

int main(int argc, char *argv[]){
    unsigned long long int h0, count;
    if (argc != 4) {
        return 1;
    }
    if (sscanf(argv[2], "%llx", &h0) != 1) {
            return 1;
    }
    if (sscanf(argv[3], "%llu", &count) != 1) {
            return 1;
    }
    int fd;
    if ((fd = open(argv[1], O_WRONLY | O_CREAT, 0660)) < 0) {
        return 1;
    }
    if (count){
        if (lseek(fd, sizeof(h0) * (count + 1), SEEK_END) < 0) {
            close(fd);
            return 1;
        }
    }

    for (; count; count--){

        if(lseek(fd, ((long) sizeof(h0)) * -2, SEEK_CUR) < 0) {
            close(fd);
            return 1;
        }
        if(write(fd, &h0, sizeof(h0)) != sizeof(h0)){
            close(fd);
            return 1;
        }
        h0 = hash_function(h0);

    }
    close(fd);
    return 0;
}