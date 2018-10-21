#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
int main(int argc, char const *argv[])
{   
    
    if (argc < 2) {
        return 1;
    }
    DIR * d = opendir(argv[1]);
    if (!d) {
        return 1;
    }
    unsigned int id = getuid();
    unsigned long long int sum = 0;
    struct dirent *dd; 
    while((dd = readdir(d))) {
        char s[PATH_MAX + 2];
        struct stat st;
        if (!strcmp(dd->d_name, ".") || !strcmp(dd->d_name, "..")) {
            continue;
        }
        if (snprintf(s, PATH_MAX + 1, "%s/%s", argv[1], dd->d_name) > 0) {

            if (stat(s, &st) <  0) {
                continue;
            }
            
            if (S_ISREG(st.st_mode) && id == st.st_uid ){
                if (dd->d_name[0] >= 'A' && dd->d_name[0] <= 'Z'){
                    sum += st.st_size;
                }
            }
        }
        

    }
    closedir(d);
    printf("%llu\n", sum);
    return 0;
}