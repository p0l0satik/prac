#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long int sump = 0;
    long long int sumn = 0;
    
    for (int t = 1; t < argc; t++) {
        int j;
        sscanf(argv[t], "%d", &j);
        if (j > 0) {
            sump += j;
        } else {
            sumn += j;
        }

    }
    printf("%lld\n%lld\n", sump, sumn);
    return 0;
}