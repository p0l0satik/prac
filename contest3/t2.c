#include <stdio.h>
#include <math.h>
enum
{
    MAX_COURSE = 10000, 
    ROUND_VAL = 10000,
    MAX_CHANGE_ABS = 100,
    TO_PERCENT = 100 
};
    /*
    MAX_COURSE:
    The task says that course can not be greater then 10000. 
    I use this constant to check if current course is less 
    than the mentioned value.

    ROUND_VAL:
    According to the task the course must be rounded after each 
    calculation according to the rules of math up to the 
    fourth sign. To do this I multiply the course by 10000 then
    round it up to the integer than divide it by 10000.

    MAX_CHANGE_ABS:
    The course can not be changed more that 100% of its value
    this constant helps to check it.

    TO_PERCENT:
    While apllying changes to the course, I use this constant 
    to divide the course change.
    */

int 
main(int argc, char const *argv[])
{   
    double course;
    if (argc <= 1 || sscanf(argv[1], "%lf", &course) != 1) {
        return 1;
    }
    if (course <= 0 || course > MAX_COURSE) {
        return 1;
    }
    for (int t = 2; t < argc; t++) {
        double j;
        if (sscanf(argv[t], "%lf", &j) != 1) {
            return 1;
        }
        if (j >= MAX_CHANGE_ABS || j <= -MAX_CHANGE_ABS) {
            return 1;
        }
        course += course * (j / TO_PERCENT);
        course *= ROUND_VAL;
        course = round(course);
        course /= ROUND_VAL;

        if (course <= 0 || course > MAX_COURSE) {
            return 1;
        }
    }
    printf("%.4lf\n", course);
    return 0;
}