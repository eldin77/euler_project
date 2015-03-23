#include <stdio.h>
#include <math.h>
/* a^2 + b^2 = c^2
 * a + b + c = 1000
 * a = 1000 - b - c 
 * b = 1000 - a - c
 * c = 1000 - a - b
 * x = 1000 -a 치환
 * a^2 + (x - c)^2 = (x - b)^2
 * */

void main(void)
{
    int a,b,c,i,x;
    for(i = 1; i<1000;i++)
    {
        a = i;
        x = 1000 - i;
        c = (a*a + x*x)/(2*x);
        b = 1000 -a - c;
        if(a*a +b*b == c*c)
            break;
        
    }
    printf("%d\n",a*b*c);
}
#endif
