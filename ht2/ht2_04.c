#include <stdio.h>
int 
main(void) {
    unsigned int a, arr[8][8];
    
    while (scanf("%x", &a)) {
        for (int t = 1; t < 8; t++) {
            for (int i = 0; i < 8; i++){
                arr[t][i] = a & 1;
                a >>= 1;
            }
        }
        for (int i = 0; i < 4; i++){
            for (int j = i; j < 4; j++){
                int a = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = a;
            }
        }

        for (int t = 1; t < 8; t++) {
            a = 0;
            for (int i = 0; i < 8; i++){
                a += arr[t][i];
                a <<= 1;
            }
            printf("%xs", a);
        }
    }
    return 0;
}