#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum 
{
    TOTAL_AMOUNT = 5,
    COUNT = 1,
    LOW = 2,
    HIGH = 3,
    SEED = 4
};
int main(int argc, char const *argv[])
{
    if (argc < TOTAL_AMOUNT) {
        return 1;
    }
    int count, low, high, seed;
    if (sscanf(argv[COUNT], "%d", &count) != 1) {
        return 1;
    }
    if (sscanf(argv[LOW], "%d", &low) != 1) {
        return 1;
    }
    if (sscanf(argv[HIGH], "%d", &high) != 1) {
        return 1;
    }
    if (sscanf(argv[SEED], "%d", &seed) != 1) {
        return 1;
    }
    srand(seed);
    for (int t = 0; t < count; t++) {
        int a = rand() / (RAND_MAX + 1.0) * (high - low);
        a += low;
        
        printf("%d\n", a);
    }
    return 0;
}