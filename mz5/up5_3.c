#include <stdio.h>
#include <time.h>
#include <string.h>
int 
main(int argc, char const *argv[])
{
    FILE *f = fopen(argv[1], "r");
    time_t now, next;
    int year, month, day, hour, minut, sec;
    struct tm date;
    char flag = 0;
    while(fscanf(f, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minut, &sec) == 6) {
        memset(&date, 0, sizeof(date));
        date.tm_isdst = -1;
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        date.tm_hour = hour;
        date.tm_min = minut;
        date.tm_sec = sec;
        next = mktime(&date);
        if (flag){
            printf("%ld\n", (long) next - now);
        } else {
            flag = 1;
        }
        
        now = next;
    }
    return 0;   
}