void 
normalize_path(char *buf)
{
    char * begin = buf;
    char * end = buf;
    int flag = 0;
    while (*end) {
        if (!flag) {
            if (*end == '/') {
                flag = 1;
            }
            *begin = *end;
            begin++;
            end++; 
        } else if (flag) {
            if (*end == '/') {
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


