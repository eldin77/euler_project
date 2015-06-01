/*백만 이하인 circular prime 개수 구하기 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000000

int is_prime(int value)
{
    int sqrt_value;
    int i;
    sqrt_value = (int)sqrt(value);
    for(i = 2;i<=sqrt_value;i++) {
        if(value%i == 0){
            return false;
        }
    }
    return true;
}
int swap_value(int value)
{
    int divide_value;
    int namo_value;
    int tmp_value = 0;
    int count = 0;
    int i;
    divide_value = value;
    namo_value = divide_value%10;
    while(1)
    {
        divide_value = divide_value/10;
        if(divide_value == 0) break;
        count++;
    }
    tmp_value = namo_value;
    for(i=0;i<count;i++){
        tmp_value*=10;
    }
    tmp_value += (value/10);
    return tmp_value;
}

void main(void)
{
    int index;
    int tmp_result = 0;
    int circular_prime = 0;
    int count = 0;
    clock_t start_time, end_time;

    start_time = clock();
   
    for(index = 2;index<=MAX;index++){
        if(is_prime(index)){
            tmp_result = index;
            while(1){
                tmp_result = swap_value(tmp_result);
                circular_prime = is_prime(tmp_result);
                if(circular_prime == 0) break;
                if(tmp_result == index) break;
            }
            if(circular_prime){
                //printf("index = %d\n",index);
                count++;
            }
        }
    }
    end_time = clock();
    printf("count = %d time = %f\n",count,(double)(end_time - start_time)/CLOCKS_PER_SEC);
}
