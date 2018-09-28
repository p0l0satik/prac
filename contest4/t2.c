#include <stdio.h>
#include <math.h>

int 
main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++) {
        int num;
        sscanf(argv[i], "%d", &num);
        unsigned int arr[3] = {0, 0, 0};

        for (int t = 0; num; t++){
            arr[t] = num % 10;
            num /= 10;
        }
        for (int t = 2; t >= 0; t--){
            int arr2[3] = {0, 0, 0};
            for (int j = 0; arr[t]; j++) {
                arr2[j] = arr[t] & 1;
                arr[t] >>= 1;
            }
            if (arr2[2]){
                printf("r");
            } else {
                printf("-");
            }
            if (arr2[1]){
                printf("w");
            } else {
                printf("-");
            }
            if (arr2[0]){
                printf("x");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    
    return 0;
}
