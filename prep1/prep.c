//подготовка к кр
#include <dirent.h>
#include <limits.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    if (argc < 2) {
        return 1;
    }
    DIR *d;
    if (!(d = opendir(argv[1]))) {
        return 1;
    }
    struct dirent *dd;
    while ((dd = readdir(d))){
        char s[PATH_MAX + 2];
        struct stat st;
        sprintf(s, "%s%s", argv[1], dd->d_name);
        unsigned long  len = strlen(dd->d_name);
        if ((len >= 4 && strcmp(s + len - 4, ".bak") == 0)|| strcmp(s + len - 1, "~") == 0) {
            unlink(s);
        }

        if (lstat(s, &st) <  0) {
            return 1;
        }

        if (S_ISDIR(st.st_mode)){
            if (strcmp(dd->d_name, ".") && strcmp(dd->d_name, "..")){
                DIR *n;
                if (!(n = opendir(s))) {
                    return 1;
                }
                struct dirent *nn;
                int cnt = 0;
                while((nn = readdir(n))){
                    if (cnt == 2) {
                        closedir(n);
                        rmdir(n);
                    }
                    if (cnt == 2) {
                        break;
                    }
                }
                closedir(n);
            }
            

        }

    }
    //дописатьж
    return 0;
}