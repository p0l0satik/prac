//подготовка к кр
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
    if (argc < 3) {
        return 1;
    }
    long long offset, offset2 = 0;
    if (!sscanf(argv[1],"%llu", &offset)) {
        return 1;
    }
    int fd = open(argv[2], O_RDONLY);
    long long int ct_bites = 0, ct_str = 0; 
    while (offset2) {
        offset = offset + offset2;
        ct_str ++;
        if (!lseek(fd, offset, SEEK_SET)){
            break;
        }
        unsigned short size;
        if(!read(fd, &size, sizeof(size))) {
            break;
        }
        ct_bites += size;
        if (!lseek(fd, offset, SEEK_CUR)) {
            break;
        }
        if(!read(fd, &offset2, sizeof(offset2))) {
            break;
        }

    }
    close(fd);
    printf("%lld %lld\n", ct_bites, ct_str);

    return 0;
}