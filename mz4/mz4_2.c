#include <stdio.h>
#include <math.h>
enum 
{
    STRL = 9
};
int 
main(int argc, char const *argv[])
{
    const char str[9] = "rwxrwxrwx";
    for (int i = 1; i < argc; i++) {
        unsigned num;
        int arr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        sscanf(argv[i], "%o", &num);
        for(int t = 0; t < STRL; t++) {
            arr[STRL - 1 - t] = num & 1;
            num >>=1;
        }
        for (int t = 0; t < STRL; t++){
            if (arr[t]) {
                printf("%c", str[t]);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    
 
    return 0;
}
