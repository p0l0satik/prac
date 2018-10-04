#include <stdio.h>
#include <linux/limits.h>

enum
{
    TEMP_SIZE = 4096,
    DECIMAL_BASIS = 10
};

void 
prnt(const unsigned long long int *num_arr) 
{
    for (int t = 0; t < DECIMAL_BASIS; t++) {
        printf("%d %llu\n", t, num_arr[t]);
    }
}
int 
main(void)
{   
    unsigned long long int num_arr[DECIMAL_BASIS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char str[PATH_MAX];
    if (!fgets(str, sizeof(str), stdin)) { 
        prnt(num_arr);
        return 0;
    }
    for (int t = 0; str[t]; t++){
        if (str[t] == '\n' || str[t] == '\r') {
            str[t] = '\0';
            break;
        }
    }
    FILE *f = fopen(str, "r");
    if (!f) {
        prnt(num_arr);
        return 0;
    }
    char temp[TEMP_SIZE];
    while (fgets(temp, sizeof(temp), f) != NULL) {
        for (int t = 0; t < TEMP_SIZE && temp[t]; t++){
            if (temp[t] >= '0' && temp[t] <= '9') {
                num_arr[temp[t] - '0']++;
            }
        }
    } 

    prnt(num_arr);
    fclose(f);
    return 0;
}