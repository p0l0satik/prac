#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    unsigned int get, conv;
    if (!argv[1]) {
        return 1;
    }
    int fd = open(argv[1], O_WRONLY| O_CREAT, 0600);
    while (fscanf(stdin, "%u", &get) == 1){
        conv = get;
        for(int t = 0; t < 3; t++){
            conv += get & 255;
            conv <<= 8;
            get >>= 8;
        }
        conv >>= 1;
        conv += get & 256;
        

        write(fd, &conv, 4);
        
    }
    close(fd);
    
}