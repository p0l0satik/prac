#include <stdio.h>
enum 
{
    OFF_NUM = 47,
    OFF_CAP = 28,
    OFF_SM = 86,
    MASK_THREE = 8,
    MASK_TWO = 59,
    CD_MONKEY = 0,
    CD_SHARP = 63,
    SML_NUM = 1,
    BIG_NUM = 10,
    SML_LCASE = 11,
    BIG_LCASE = 36
};

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            c -= OFF_NUM;
        } else if (c >= 'A' && c <= 'Z') {
            c -= OFF_CAP;
        } else if (c >= 'a' && c <= 'z') {
            c -= OFF_SM;
        } else{
            continue;
        }

        c = (c ^ MASK_THREE) & MASK_TWO;
        if (c == CD_MONKEY){
            putchar('@');
        } else if (c == CD_SHARP) {
            putchar('#');
        } else if (c >= SML_NUM && c <= BIG_NUM) {
            putchar(c + OFF_NUM);
        } else if (c >= SML_LCASE && c <= BIG_LCASE) {
            putchar(c + OFF_SM);
        } else {
            putchar(c + OFF_CAP);
        }

    }
    return 0;
}