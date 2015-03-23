/* 10 이하의 소수를 모두 더하면 2 + 3 + 5 + 7 = 17 이 됩니다.
 * 이백만(2,000,000) 이하 소수의 합은 얼마입니까?
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int is_prime(int value)
{
    if((value % 2) == 0)
        return false;
    int i;
    int sqrt_value;
    int ret = 0;
    /* value의 root값의 까지의 소수만 찾으면됨
     * 최다 value의 root값까지만 loop을 돌면됨.
     * 3부터 홀수 value 의 root값으로 나누어 떨어지면 소수가 아님
     * 나누어 떨어지지 않으면 소수에 해당.
     * */
    sqrt_value = (int)sqrt(value);
    //printf("sqrt_vaule = %d:%d\n",sqrt_value,value);
    for(i = 3; i<=sqrt_value; i+=2){
        if(value % i == 0){
            return false;
            
        }
    }
    
    return true;
}

void main(void)
{
    int x=2,y;
    int max_count =2000000; 
    int tmp_count= 0;
    /* 소수 2부터 시작 */
    unsigned long result = 2;
    clock_t start_time, end_time;

    /*홀수이용.
     * 2로 나누어 떨어지지 않는경우 1/3이상의 수로 나누는것은 무의미
     * 2 이후에 3으로도 나누어떨어지지 않을경우 1/3이상으로 나누는건 무의미
     * .*/
    start_time = clock();
    for(x = 3; x <= max_count; x+=2){
        if(is_prime(x)){
            //printf("%d\n",x);
            result += x;
        }

    }
    end_time = clock();
    printf("result = %lu time = %f\n",result,((double)end_time-start_time)/CLOCKS_PER_SEC);

}
