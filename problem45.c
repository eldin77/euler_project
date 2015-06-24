/* 삼각수, 오각수, 육각수는 아래 식으로 구할 수 있습니다.
 *
 * 삼각수       Tn = n (n + 1) / 2      1, 3, 6, 10, 15, ...
 * 오각수       Pn = n (3n − 1) / 2     1, 5, 12, 22, 35, ...
 * 육각수       Hn = n (2n − 1)     1, 6, 15, 28, 45, ...
 * 여기서 T285 = P165 = H143 = 40755 가 됩니다.
 *
 * 오각수와 육각수도 되는, 그 다음으로 큰 삼각수를 구하세요.
 *
 * H(n) = T(2n - 1)
 * H(n) = n (n - 1) = 2n (n - 1)/2 = (2n - 1)((2n - 1) + 1)/2 = T(2n - 1)
 * 
 * P = H 가 같은 경우만 찾으면 됨.
 * 
 * P(p) = H(h) 이면..
 * 
 * p(3p-1)/2 = h(2h-1)
 * p(3p-1) = 2h(2h-1)
 * 3p²- p = 4h²- 2h
 * 36p²- 12p = 48h²- 24h
 * 36p²- 12p + 1 = 48h²- 24h + 1
 * (6p-1)²= 48h²- 24h + 1
 * 6p - 1 = √(48h²- 24h + 1)
 * 6p = √(48h²- 24h + 1) + 1
 * p = (√(48h²- 24h + 1) + 1)/6
 * 
 * 위의 p값이 정수값이 되는 h를 구하면 됨.
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int is_prod(unsigned long long value)
{
    long double n;
    n = (long double)((long double)sqrt(24*value+1)+1)/6;
    if( n/1.00 == (long long)n ){ 
        //printf("2 %llu\n",(long long)n);
        return true;
    }
    
    return false;
}

int is_hexd(unsigned long long value)
{
    long double n;
    n = (long double)((long double)sqrt(8*value+1)+1)/4;
    if( n/1.00 == (long long)n ){ 
        //printf("1 %llu\n",(long long )n);
        return true;
    }
    
    return false;

}

int is_tri(unsigned long long value)
{
    long double n;
    n = (long double)((long double)sqrt(8*value+1)-1)/2;
    //printf("%llu\n",(long long)n);
    if( n/1.00 == (long long)n ){
        return true;
    }
    
    return false;
}

void main(void)
{
    //unsigned long long index = 500000000;
    unsigned long long index = 40756; 
    while(1){
            if(is_hexd(index) && is_prod(index)){
            //if(is_tri(index) && is_prod(index)){
                printf("%llu\n",index);
                break;
            }
        index++;
    }
}
