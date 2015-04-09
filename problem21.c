/*
 * n의 약수들 중에서 자신을 제외한 것의 합을 d(n)으로 정의했을 때, 서로 다른 두 정수 a, b에 대하여 d(a) = b 이고
 * d(b)= a 이면 a, b는 친화쌍이라 하고 a와 b를 각각 친화수(우애수)라고 합니다. 예를 들어 220의 약수는 자신을 제외하면 1,
 * 2, 4, 5, 10, 11, 20, 22, 44, 55, 110 이므로 그 합은 d(220) = 284 입니다. 또 284의 약수는
 * 자신을 제외하면 1, 2, 4, 71, 142 이므로 d(284) = 220 입니다. 따라서 220과 284는 친화쌍이 됩니다.
 * 
 * 10000 이하의 친화수들을 모두 찾아서 그 합을 구하세요.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 10000

int is_prime(int value)
{
    int i,j;
    int sqrt_value;
    int result = 0;
    int divied_value = 0;
    sqrt_value = (int)sqrt(value);
    //printf("sqrt_value = %d\n",sqrt_value);
    for(i = 1;i <= sqrt_value;i++) {
        if(value % i == 0){
            divied_value = value/i;
    //       printf("i= %d\n",i);
    //       printf("devied_value= %d\n",value/i);
            if(i == divied_value) {
                result = result+i;
            } else {
                result = result+(i+divied_value);
            }
        }
    }
    result -= value;
    return result;

}

void main(void)
{
    int value = 0;
    int prime_sum;
    int tmp_sum;
    int result=0;
    for(value = 1; value <= MAX; value++){
        prime_sum = is_prime(value);
        tmp_sum = is_prime(prime_sum);
        if(prime_sum == tmp_sum) continue; //서로다른 두 정수 a,b니까 같으면 pass
        if(value == tmp_sum){ //친화수의 합
            result += value;
            printf("pri %d : tmp %d : value %d: result %d\n",prime_sum, tmp_sum,value,result);
        }
    }
}
