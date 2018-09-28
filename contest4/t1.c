#include <stdio.h>
#include <math.h>

int 
main(void)
{
    int n, w;
    scanf("%o%o", &n, &w);
    int st = pow(2, n);
    for (int t = 0; t < st; t++) {
        int pr = t % (st / 2);
        if (t > st / 2) {
            pr*= -1;
        }
        printf("|");
        printf("%*o", w, t);
        printf("|");
        printf("%*d", w, t);
        printf("|");
        printf("%*d", w, pr);
        printf("|");
        printf("\n");
        
    }
    return 0;
}
