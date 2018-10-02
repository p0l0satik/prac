#include <stdio.h>

int
main(void)
{
    double p_x, p_y;
    int inp = scanf("%lf%lf", &p_x, &p_y);
    printf("%d\n",  inp == 2 && p_y <= p_x * -1.0 + 10.0 && 
        p_y >= 2.0 && p_y <= 5.0 && p_x >= 1.0 && p_x <= 7.0);
    return 0;
}