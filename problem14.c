#include <stdio.h>
#include <time.h>
#define MAX_VALUE 1000000 
/* 양의 정소 n에 대하여, 다음과 같은 계산 과정을 반복하면
 * n -> n/2(n이 짝수)
 * n->3n+1(n이 홀수)
 *
 * 13에 대하여 규칙을 적용시 10번 과정을 통해 1일됩니다
 *
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * 아직 증명은 되지 않았지만, 이런과정을 거치면 어떤수로 시작해도 1로 끝나리라 생각됨
 * 이것이 콜라츠 추측
 *
 * 백만(1000000) 이하의 수로 시작하였을때 1까지 도달하는데 가장 긴과정을 거치는 숫자는?
 * 문제에 힌트가 나와있음. 
 * */

void main(void)
{
    unsigned long index = 0;
    unsigned long i = 0,j = 0; 
    unsigned long count = 0; 
    unsigned long top_count = 0; 
    unsigned long top_index = 0; 
    clock_t start_time, end_time;

    start_time = clock();
    for(index = MAX_VALUE; index >= 1; index--){
        j = index;
        while(1){
            if(j%2 == 0){
                j = j/2;
                count++;
                //printf("2j = %lu\n",j);
            } else {
                //printf("3j = %lu\n",j);
                j = (3*j)+1;
                count++;
                //printf("3j = %lu\n",j);
            }
            if(j == 1) break;
        }
        if(count > top_count){
            top_count = count+1;
            top_index = index;
            printf("top count = %lu:%lu\n",top_index,top_count);
        }
        count = 0;
    }
    end_time = clock();
    printf("top count = %lu:%lu time = %f\n",index,top_index,(double)(end_time - start_time)/CLOCKS_PER_SEC);
        
}
