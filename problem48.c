/* 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317 입니다.
 *
 * 1^1 + 2^2 + 3^3 + ... + 1000^1000 의 마지막 10자리 숫자는 무엇입니까?
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define MAX 2048 
#define MAX 1000

void main(void)
{
    int i, j;
    long long s = 0ll;
    long long t = 1ll;

    for ( i =1; i<= MAX; i++ )
    {
        t = (long long)i;
        for ( j=1; j<i; j++ )
        {
            t *= i;
            t %= 10000000000ll;
        }
        printf("%d > %010lld\n", i, t );

        s += t;
        s %= 10000000000ll;
    }
    printf("%010lld\n", s );
}
