#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char* argv[]) {
    unsigned get;
    if (argc < 2 ) {
        return 1;
    } 
    char buf[sizeof(get)];
    int fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);
    while (scanf("%u", &get) == 1 ){
        for (int t = 0; t < sizeof(get); t++){
            buf[sizeof(get) - 1 - t] = (get >> t * 8) & 0xFF; 
        }
        write(fd, &buf, sizeof(get));
    }
    
    close(fd);
    

    return 0;
}