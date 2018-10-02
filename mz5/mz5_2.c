#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    struct tm date;
    memset(&date, 0, sizeof(date));
    time_t year;
    if(sscanf(argv[1], "%ld", &year) != 1) {
        return 1;
    }
    time_t day; 
    if(sscanf(argv[2], "%ld", &day) != 1) {
        return 1;
    }
    date.tm_year = year - 1900;
    date.tm_isdst = -1;
    time_t sec = mktime(&date) + 60 * 60 * 24 * day;
    localtime_r(&sec, &date);
    int wd = date.tm_wday;
    if (!wd){
        wd = 7;
    }
    printf("%d %d %d %d\n", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, wd);

    return 0;
}