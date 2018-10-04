#include <stdio.h>
#include <stdint.h>

int 
main(void)
{
    int n, w;
    scanf("%o%o", &n, &w);

    int32_t st = 1;
    st <<= n;
    for (int32_t t = 0; t < st; t++) {
        int32_t pr = t % (st / 2);
        if (t > st / 2) {
            pr *= -1;
        }
        printf("|%*o|%*d|%*d|\n", w, t, w, t, w, pr);  
    }
    return 0;
}
