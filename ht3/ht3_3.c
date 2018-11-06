#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum
{
    MULT = 1103515245,
    INC = 12345,
    MOD = 2147483648
};

struct RandomGenerator;
int next(struct RandomGenerator *rr);
void destroy(struct RandomGenerator *rr);

typedef struct RandomOperations
{
    int (*next)(struct RandomGenerator *rr);
    void (*destroy)(struct RandomGenerator *rr);
} RandomOperations;

RandomOperations ops;
typedef struct RandomGenerator
{
    unsigned int prev;
    RandomOperations * ops;
} RandomGenerator;

int next(struct RandomGenerator *rr) 
{   
    rr -> prev = ((rr -> prev) * MULT + INC) % MOD;
    return rr -> prev;
}

void destroy(struct RandomGenerator *rr) 
{   
    free(rr);
}

RandomGenerator *random_create(int seed) 
{
    RandomGenerator * rg = (RandomGenerator *) calloc(1, sizeof(* rg));
    rg -> ops = &ops;
    rg -> ops -> next = next;
    rg -> ops -> destroy = destroy;
    rg -> prev = seed;

    return rg;
}
