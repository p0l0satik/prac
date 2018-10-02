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
MAX_COURSE_VALUE - Максимальное значение курса 10000, 
использую константу чтобы курс не привысил это значение после 
персчета/изначально.
MAX_CHANGE_ABSOLUTE - Максимальное изменение курса в процентах по модулю,
использую чтобы отследить случаи, в которых просят изменить курс больше,
чем на эту величину.
TO_PERCENT - константа, чтобы перевести проценты в десятичную дробь. 
ROUND_VALUE - чтобы округлить число, я сначала курс на 10000, 
чтобы перевести 4 цифры после запятой в целую часть. 4 цифры по условию.
После этого использую функцию round(), которая математически округляет
до целого. Поделив на 10000 я сдвигаю десятичную точку на 4 знака влево,
а так как число до этого было округленно получается округление до 4-го 
знака. Таким образом можно округлять до n-ного знака, если потребуется,
заменив значение ROUND_VALUE на 10^n.

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