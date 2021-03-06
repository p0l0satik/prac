#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    READ_SIZE = 128
};

 
char *getline2(FILE *f) 
{   
    size_t size = READ_SIZE;
    size_t now_s = 0;
    char *s = calloc(size, sizeof(*s));
    if (!s) {
        return NULL;
    }
    int flag = 0;
    while (fgets(s + now_s, size - now_s, f)) {
        flag = 1;
        now_s = strlen(s);
        if (s[now_s - 1] == '\n') {
            break;
        }
        size *= 2;
        char *p = realloc(s, size);
        if (!p){
            free(s);
            return NULL;
        }
        s = p;
    }
    if (flag) {
        return s;
    }
    free(s);
    return NULL;
}

