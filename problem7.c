#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/* 소수 2,3,5,7,11,13 .... 10001 번째 소수
 * 1. 소수인지 판번할때 해당 value값의 root(value) 값까지 loop돈다
 * 2. 이때 value값을 root(value)값까지 순차적으로 나누었을때 0으로 나누어떨어지면 소수가 아님 return false
 * 3. 그렇지 않으면 않고 retrun하면 소수 return ture
 * 4. 소수일경우 count 값증가.
 * 5. 10001번째의 카운팅시 loop 종료.
 *  * */
int is_prime(unsigned long value)
{
    unsigned long tmp_value, i;
    tmp_value = (unsigned long)sqrt(value);
    for(i=2;i<=tmp_value;i++){
        if(value%i == 0 ){
            return false;
        }
    }
    return true;
}
void main(void)
{
    int count = 0;
    clock_t start_time, end_time;
    unsigned long index=2;
    start_time = clock();
    while(count <= 10001){
        if(is_prime(index)){
            count++;
            if(count == 10001){
                break;
            }
        }
        index++;
    }
    end_time = clock();
    printf("%d:%lu time = %f\n",count,index,(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
