#include <stdio.h>
#include <limits.h>
enum 
{
    REVERSE_PRINT_NUM = CHAR_BIT - 1
};
int 
main(void) {
    unsigned char a, arr[CHAR_BIT][CHAR_BIT];

    while (scanf("%hhx", &a) == 1) {

        for (int t = 0; t < CHAR_BIT; t++) {
            if (t > 0) {
                if (scanf("%hhx", &a) != 1){
                    return 1;
                }
            }
            for (int i = 0; i < CHAR_BIT; i++){
                arr[t][i] = a & 1;
                a >>= 1;
            }
        }

        for (int t = 0; t < CHAR_BIT; t++) {
            a = 0;
            for (int i = 0; i < CHAR_BIT; i++){
                a += arr[REVERSE_PRINT_NUM - i][t];
                if (i < REVERSE_PRINT_NUM) {
                    a <<= 1;
                }
            }
            printf("%hhx ", a);
        }
    }
    printf("\n");
    return 0;
}
