#include <stdio.h>
#include <time.h>
#include <string.h>
enum 
{
    SEC = 60,
    MINUT = 60,
    HRS = 24,
    DAYS = 30, 
    MONTHS = 12,
    COUNT_FROM = 1900,
    SH_B_YR = 1925,
    SH_B_MN = 10,
    SH_B_D = 7
};

int main(int argc, char const *argv[])
{
    struct tm date;
    memset(&date, 0, sizeof(date));

    date.tm_isdst = -1;
    date.tm_year = SH_B_YR - COUNT_FROM;
    date.tm_mon = SH_B_MN - 1;
    date.tm_mday = SH_B_D;
    long long grg, emp = mktime(&date);
    int year, month, day;
    while (scanf("%d%d%d", &year, &month, &day) == 3){
        memset(&date, 0, sizeof(date));
        date.tm_isdst = -1;
        date.tm_year = year - COUNT_FROM;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        grg = mktime(&date) - emp;
        printf("%lld %lld %lld\n", grg / (SEC * MINUT * HRS * DAYS * MONTHS) + 1, 
            (grg / (SEC * MINUT * HRS * DAYS)) % MONTHS + 1, (grg / (SEC * MINUT * HRS)) % DAYS + 1);

    }
}