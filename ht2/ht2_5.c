#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
enum 
{
    BUFSIZE = 16
};
int main(void) {
    char buf[BUFSIZE];
    unsigned long long sum = 0;
    long long int a;
    int flag = 0;
    int r = 0;
    while((r = read(1, buf, BUFSIZE)) > 0) {
        int t = 0;
        int flotr = 0;
        while (t < BUFSIZE){
            if (flag == 0) {
                a = 0; 
            }
            if (!isspace(buf[t])){

                long long int c;
                if (a) {
                    long long int b;
                    if (a < 0) {
                        a = -a;
                        flotr = 1;
                    }
                    b = a;
                    sscanf(buf + t,"%lld", &a);
                    int i = 0;
                    c = a;

                    while (c) {
                        i++;
                        c /= 10;
                    }
                    for (int j = 0; j < i; j++) {
                        
                        b = b * 10;
                    }

                    
                    b += a;
                    t += i;
                    a = b;
                    if (flotr) {
                        flotr = 0;
                        a = -a;
                    }
                    continue;
                }
                
                flag = 1;
                sscanf(buf + t,"%lld", &a);
                if (buf[t] == '+' || buf[t] == '-'){
                    t++;
                }
                if (a) {
                    c = a;
                    while (c) {
                        t++;
                        c /= 10;
                    }
                    t--; 

                }

            } else  {
                sum += a;
                flag = 0;
            
            }
            t++;
        }
        memset(buf, 0, BUFSIZE);

    }
    printf("%lld\n", sum);
    return 0;
}