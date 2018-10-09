
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned long long int sum = 0;
    for (int t = 1; t < argc; t++){
        struct stat st;
        if (lstat(argv[t], &st) == 0 && S_ISREG(st.st_mode) && st.st_nlink == 1){
            sum += st.st_size;
        }
    }
    printf("%llu\n", sum);
    
    return 0;
}