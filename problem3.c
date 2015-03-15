/* 어떤 수를 소수의 곱으로만 나타내는 것을 소인수분해라 하고, 이 소수들을 그 수의 소인수라고 합니다.
 * 예를 들면 13195의 소인수는 5, 7, 13, 29 입니다.
 * 600851475143의 소인수 중에서 가장 큰 수를 구하세요.
 */
#include <stdio.h>
#include <math.h>
#include <time.h>

void main(void)
{
    unsigned long index = 600851475143; 
    unsigned long count=index, tmp=0;
    unsigned long min, result;
    unsigned long value;

    /* 소인수분해
     * 2에서 index까지 loop을 돌면서 index를 min으로 나눈 나머지가
     * 0인 min으로 index를 나누어서 index를 줄여나간다.
     */
    clock_t start_time, end_time;
    start_time = clock();
    for(min = 2;min < index; min++){
        if(index % min ==0){
            index = index / min;
            //printf("%lu %lu\n",min, index);
            printf("min : %lu index : %lu\n",min,index);
        }
    }
    end_time = clock();
    printf("index:%lu time:%f\n",index,(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
