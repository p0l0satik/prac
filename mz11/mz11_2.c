#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
volatile int flag = 0;
void plus_two(int par) {
    signal(SIGINT, plus_two);
    flag = 0;
}
void minus_two(int par) {
    signal(SIGQUIT, minus_two);
    flag = 1;
}
int main()
{
    signal(SIGINT, plus_two);
    signal(SIGQUIT, minus_two);
    printf("%d\n", getpid());
    fflush(stdout);
    int sum = 0;
    int get;
    while(scanf("%d", &get) == 1) {
        
        if (!flag) {
            sum += (long long) get;
        } else {
            sum *= (long long) get;
        }
        printf("%d\n", sum);
        fflush(stdout);
    }
    return 0;
}