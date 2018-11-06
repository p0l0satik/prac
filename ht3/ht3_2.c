#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum 
{
    AMOUNT_OF_PERCENTS = 100,
    LOW = 0,
    HIGH = 100
};
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int rand_val[AMOUNT_OF_PERCENTS];
    int t = 0;
    int total = 0;
    while(t < AMOUNT_OF_PERCENTS) {
        int fil ;
        int num;
        scanf("%d%d", &fil, &num);
        total += num;
        while (t < total) {
            rand_val[t] = fil;
            t++;
        }
        
    }

    int m, seed;
    scanf("%d%d", &m, &seed);
    srand(seed);
    for (int i = 0; i < m; i++){
        int a = rand() / (RAND_MAX + 1.0) * (HIGH - LOW);
        printf("%d\n",rand_val[a]);
    }
    return 0;
}