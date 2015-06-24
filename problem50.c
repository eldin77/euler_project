/* 41은 소수이면서 다음과 같은 6개의 연속된 소수의 합으로도 나타낼 수 있습니다.
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * 이것은 100 이하에서는 가장 길게 연속된 소수의 합으로 이루어진 소수입니다.
 *
 * 1000 이하에서는 953이 연속된 소수 21개의 합으로 가장 깁니다.
 *
 * 1백만 이하에서는 어떤 소수가 가장 길게 연속되는 소수의 합으로 표현될 수 있습니까?
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_N 1000000 

unsigned char sieve[(MAX_N+7)/8];

static inline void set_composite(int value)
{
    sieve[value >> 3] &= ~(1<<( value & 7));
}

static inline int is_prime(int value)
{
   return sieve[value >> 3] & (1<<( value & 7 ) ); 
}

void eratostheness(int value)
{
    int sqrt_value;
    int i,j;
    sqrt_value = (int)sqrt(value);
    for(i = 2; i<=sqrt_value; i++){
        for(j=i*i; j<=value; j+=i){
            set_composite(j);
        }
    }
}

void main(void)
{
    int i,j;
    unsigned long long result = 0;
    int count = 0;
    int top_count = 0;
    int gap,tmp; 
    unsigned long long sum_buf[8192] = {0};
    int top = 0;
    clock_t start_time, end_time;
    int end_result;

    sieve[0] = 0;
    sieve[1] = 0;
    memset(sieve, 0xFF, sizeof(sieve));
    eratostheness(MAX_N);
    start_time = clock();
    for(i=2;i<=MAX_N;i++){
        if(is_prime(i)){
            result += i;
            if(result > MAX_N) break;
            sum_buf[count] = result;
            count++;
        }
    }
#if 1
    for(i = 0; i<count; i++){
        if(is_prime(sum_buf[i])){
//            printf("%d:%llu\n",i+1,sum_buf[i]);
            top = i;
        }
    }
#endif

    result = 0;
    tmp = top;
    for(i=tmp;i<=count;i++){
        for(j = i; j>=0;j--){
            gap = i-j;
            result = sum_buf[i] - sum_buf[j]; 
            if((gap > top ) && is_prime(result)){
                //                printf("%llu:%d:%llu:%llu\n",result,gap,sum_buf[i],sum_buf[j]);
                top = gap;
                end_result = result;
            }
            result = 0;
        }
    }
    end_time = clock();
    printf("result = %d, time = %f\n",end_result, (double)(end_time-start_time)/CLOCKS_PER_SEC);
}
