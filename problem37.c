/* 소수 3797에는 왼쪽부터 자리수를 하나씩 없애거나 
 * (3797, 797, 97, 7) 오른쪽부터 없애도 (3797, 379, 37, 3) 모두 소수가 되는 성질이 있습니다.
 *
 * 이런 성질을 가진 소수는 단 11개만이 존재합니다. 이것을 모두 찾아서 합을 구하세요.
 *
 * (참고: 2, 3, 5, 7은 제외합니다)
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int is_prime(unsigned int value)
{
    int sqrt_value;
    int i;
    sqrt_value = (unsigned int)sqrt(value);
    for(i = 2;i<=sqrt_value;i++){
        if(value % i == 0){
            return false;
        }
    }
    if(value == 1) return false;
    return true; 
}

unsigned int change_prime(unsigned int value)
{
    unsigned int swap_left = value/10;
    unsigned int swap_right = value%10;
    unsigned int tmp = value/10;
    unsigned int tmp_value = 10;

    while(1){
        //printf("%d %d %d\n",value,swap_left, swap_right);
        if(is_prime(swap_left)){
            swap_left = swap_left/10;
            if(swap_left == 0) {
                break;
            }
        } else {
            return false;
        }
    }
    while(1){    
        //printf("value %d swap_right =%d %d\n",value,swap_right, tmp_value);
        if(is_prime(swap_right)){
            tmp_value = tmp_value*10;
            swap_right = value%tmp_value;
            tmp = tmp / 10;
            if(tmp == 0) {
                break;
            }
        } else {
            return false;
        }
    }
    return true;
}

void main(void)
{
    unsigned int index = 10;
    unsigned int result = 0;
    int count = 0;
    clock_t start_time, end_time;
    start_time = clock();
    while(1){
        if(is_prime(index)){
            //printf("prime - %d\n",index);
            if(change_prime(index)) {
                printf("%d\n",index);
                count++;
                result += index;
            }
        }
        index++;
        if(count == 11) break;
    }
    end_time = clock();
    printf("result = %d time = %f\n",result,(double)((end_time - start_time))/CLOCKS_PER_SEC);

}
