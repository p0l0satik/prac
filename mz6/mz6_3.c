#include <string.h>
#include <stdio.h>

int
parse_rwx_permissions(const char *str) {
    if (str == NULL) {
        return -1;
    }
    int len = strlen(str);
    char s[] = "rwxrwxrwx";
    
    if (len != sizeof(s) - 1) {
        return -1;
    }
    int right = 0;
    for (int t = 0; t < len; t++){
        if (str[t] == '-'|| str[t] == 'r' || str[t] == 'w' || str[t] == 'x'){
            if (str[t] == s[t]){
                right += 1;
                right <<= 1;
            }else {
                if (str[t] != '-') {
                    return -1;
                }
                right <<= 1;
            }
        } else {
            return -1;
        }
    }
    right >>= 1;
    return right;

}

