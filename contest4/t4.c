#include <stdio.h>
#include <math.h>

void 
normalize_path(char *buf)
{
    char * begin = buf;
    char * end = buf;
    int flag = 0;
    while (*end){
        if (!flag){
            if (*end == '/') {
                flag = 1;
            }
            *begin = *end;
            begin++;
            end++; 
        } else if (flag) {
            if (*end == '/'){
                end++;
            } else {
                flag = 0;
                *begin = *end;
                begin++;
                end++;
            }
        }
    }
    *begin = '\0';
}

int 
main(void)
{
    char bug[100];
    scanf("%s", bug);
    normalize_path(bug);
    printf("%s\n", bug);
    return 0;
}