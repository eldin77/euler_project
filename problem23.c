/* 자신을 제외한 약수(진약수)를 모두 더하면 자기 자신이 되는 수를 완전수라고 합니다.
 * 예를 들어 28은 1 + 2 + 4 + 7 + 14 = 28 이므로 완전수입니다.
 * 또, 진약수의 합이 자신보다 작으면 부족수, 자신보다 클 때는 초과수라고 합니다.
 *
 * 12는 1 + 2 + 3 + 4 + 6 = 16 > 12 로서 초과수 중에서는 가장 작습니다.
 * 따라서 초과수 두 개의 합으로 나타낼 수 있는 수 중 가장 작은 수는 24 (= 12 + 12) 입니다.
 *
 * 해석학적인 방법을 사용하면, 28123을 넘는 모든 정수는 두 초과수의 합으로 표현 가능함을 보일 수가 있습니다.
 * 두 초과수의 합으로 나타낼 수 없는 가장 큰 수는 실제로는 이 한계값보다 작지만, 해석학적인 방법으로는 더 이상 이 한계값을 낮출 수 없다고 합니다.
 *
 * 그렇다면, 초과수 두 개의 합으로 나타낼 수 없는 모든 양의 정수의 합은 얼마입니까?
 *
 *
 * 위의 문제가 잘 이해가 안되었지만, 1~28123 까지의 초과수를 구한다음에
 * 구해져 나온 초과수들을 두개를 조합하여 합에서 양의정수 1~28123까지의 정수중에서 만들수 없는수 구하기.
 * 예를 들어 최소 
 * 초과수 12+12 = 24
 * 12 + 18 = 30 이러한식으로 하여 만들수 없는 양의 정수의합.
 * 
 */


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX 28124 
int is_prime(value)
{
    int sqrt_value;
    int i, result = 0;
    int divied_value = 0;
    sqrt_value = (int)sqrt(value);
    for(i = 1; i<= sqrt_value;i++){
        if(value % i == 0){
            divied_value = value/i;
            if(divied_value == i ){
                result = result+(i);
            } else {
                result = result+(i+divied_value);
            }
            //printf("%d ",i);
        }
    }
    //printf("\n");
    return result;
}

void main(void)
{
    int value = 0;
    int result = 0;
    int last_result = 0;
    int total_value=0;
    int up_buf[MAX] = {0};
    int sum_buf[MAX] = {0};
    int tmp_value;
    int count = 0;
    int i,j,tmp_result;
    
    clock_t start_time, end_time;

    start_time = clock();
    for(value = 1; value < MAX; value++){
        total_value += value;
        result = is_prime(value)-value;
        if(value < result){
            //printf(" up %d\n",value, result);
            up_buf[count] = value;
            count++;
        } 
    }
    for(i = 0; i< count; i++){
        for(j=0;j< count;j++){
            tmp_value = up_buf[i]+up_buf[j];
            if(tmp_value > MAX) {
                break;
            } else {
                sum_buf[tmp_value] = 1;
            }
        }
    }
    for(i=0;i<MAX;i++){
        if(sum_buf[i] == 0){
            //printf("%d\n",sum_buf[i]);
            last_result += i;
        }
    }
    end_time = clock();
    printf("result = %d time = %f\n",last_result,(double)((end_time-start_time)/CLOCKS_PER_SEC));
}
