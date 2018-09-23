#include <stdio.h>
#include <stdlib.h>

enum
{
    MAXN = 16384
};

struct Triple
{
    double fr;
    int sc;
    int numb;
};

int
cmp(const void *x1, const void *x2)
{
    struct Triple * c1 = (struct Triple *) x1;
    struct Triple * c2 = (struct Triple *) x2;

    if (c1->fr > c2->fr) {
        return 1;
    } 
    if (c1->fr < c2->fr) {
        return -1;
    } 
    if (c1->numb > c2->numb){
        return 1;
    }
    if (c1->numb < c2->numb){
        return -1;
    }
    return 0;
}

int
main(void)
{
    struct Triple *array = (struct Triple *) calloc(MAXN, sizeof(*array));
    if (!array) {
        return 0;
    }
    int t = 0;
    while (t < MAXN && scanf("%lf%d", &array[t].fr, &array[t].sc) == 2) {
        array[t].numb = t;
        t++;
    }
    qsort(array, t, sizeof(*array), cmp);
    for (int i = 0; i < t; i++) {
        printf("%.10g %d\n", array[i].fr, array[i].sc);
    }
    free(array);
    return 0;
}