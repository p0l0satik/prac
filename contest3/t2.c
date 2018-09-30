#include <stdio.h>
#include <math.h>
enum
{
    MAX_COURSE_VALUE = 10000, 
    ROUND_VALUE = 10000,
    MAX_CHANGE_ABSOLUTE = 100,
    TO_PERCENT = 100 
};
/* 
I am sorry, but I consider inappropriate to write comments 
in Russian. That is why I decided to change contstants names.
If they are not clear enough, please explain 
what exactly is not OK, for me to fix it.
*/

int 
main(int argc, char const *argv[])
{   
    double course;
    if (argc <= 1 || sscanf(argv[1], "%lf", &course) != 1) {
        return 1;
    }
    if (course <= 0 || course > MAX_COURSE_VALUE) {
        return 1;
    }
    for (int t = 2; t < argc; t++) {
        double j;
        if (sscanf(argv[t], "%lf", &j) != 1) {
            return 1;
        }
        if (j >= MAX_CHANGE_ABSOLUTE || j <= -MAX_CHANGE_ABSOLUTE) {
            return 1;
        }
        course += course * (j / TO_PERCENT);
        course *= ROUND_VALUE;
        course = round(course);
        course /= ROUND_VALUE;

        if (course <= 0 || course > MAX_COURSE_VALUE) {
            return 1;
        }
    }
    printf("%.4lf\n", course);
    return 0;
}