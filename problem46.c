/* 크리스티안 골드바흐는 모든 홀수인 합성수를 (소수 + 2×제곱수)로 나타낼 수 있다고 주장했습니다.
 *
 * 9 = 7 + 2×12
 * 15 = 7 + 2×22
 * 21 = 3 + 2×32
 * 25 = 7 + 2×32
 * 27 = 19 + 2×22
 * 33 = 31 + 2×12
 *
 * 이 추측은 잘못되었음이 밝혀졌습니다.
 *
 * 위와 같은 방법으로 나타낼 수 없는 가장 작은 홀수 합성수는 얼마입니까?
 *
 * x = a+2*n^2
 * a = 소수
 * n = sqrt(x) 보다 작은범위
 * x = 5부터 시작하는 홀수
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1024

int is_prime(int value)
{
    int i, sqrt_value;
    sqrt_value = (int)sqrt(value);

    for(i = 2; i<=sqrt_value; i++){
        if(value % i == 0){
            return false;
        }
    }
    return true;
}

void main(void)
{
    int prime_buf[MAX] = {0};
    int i,j=0;
    int x,z;
    int value;
    int tmp;
    int limit, flag=0;
    for(value = 5; value<=10000; value=value+2){
        if(is_prime(value)){
            continue;
        }
        //printf("%d\n",value);
        memset(prime_buf, 0, sizeof(int)*MAX);
        for(i = 2; i <= value; i++){
            if(is_prime(i)){
                prime_buf[j] = i;
                j++;
              }
        }
        for(x = 0; x < j ; x++){
            limit = (int)sqrt(value);
            for(z=1;z<=limit;z++) {
                tmp = prime_buf[x] + 2*(z*z);
                //printf("%d=%d+%d*%d^%d\n",value, prime_buf[x],2,z,z);
                    if(value == tmp) {
                        flag = 1;
                        break;
                    }
            }
            if(flag == 1){
                break;
            } 
        }
        if(flag == 0 ){
            printf("%d\n",value);
            break;
        }
        j = 0;
        flag = 0;
    }
}
