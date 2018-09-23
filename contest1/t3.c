#include <stdio.h>
#include <stdlib.h>
enum
{
    MAXN = 2000,
    SEC_LN = 2
};

int
main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n > 2000) {
        return 1;
    }
    int *arr = (int *) calloc(MAXN * MAXN, sizeof(*arr));
    if (!arr) {
        return 1;
    }
    for (int t = 0; t < n; t++ ) {
        int x = 1;
        for (; x < n && (x * (t + 1)) % n != 1; x++) {
            
        }
        arr[n + t] = x;
    }
    for (int t = SEC_LN; t < n; t++) {
        for (int i = 0; i < n - 1; i++) {
            arr[n * t + i] = (arr[n * (t - 1) + i] + arr[n + i]) % n;
        }
        
    }
    for (int t = 0; t < n; t++) {
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", arr[n * t + i]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}