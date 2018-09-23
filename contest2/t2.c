#include <stdio.h>
enum 
{
    MAX_LENGTH = 24
};
   
int
check(unsigned int inp)
{
    if (inp == 0) {
        return 1;
    }
    while ((inp & 1) == 0) {
        inp >>= 1;       
    }
    int sum = 0;
    while (inp) {
        sum++;
        inp >>= 1;
    }
    return sum <= MAX_LENGTH;
}



int 
main(void)
{
    unsigned int inp;
    while (scanf("%u", &inp) == 1) {
        printf("%u\n", check(inp));
    }
    return 0;
}