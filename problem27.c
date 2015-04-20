/* 오일러는 다음과 같은 멋진 2차식을 제시했습니다.
 *
 * n2 + n + 41
 * 이 식의 n에다 0부터 39 사이의 숫자를 넣으면, 그 결과는 모두 소수가 됩니다.
 * 하지만 n = 40일 때의 값 402 + 40 + 41 은 40×(40 + 1) + 41 이므로 41로 나누어지고, n = 41일 때 역시 412 + 41 + 41 이므로 소수가 아닙니다.
 *
 * 컴퓨터의 발전에 힘입어 n2 − 79n + 1601 이라는 엄청난 2차식이 발견되었는데, 이것은 n이 0에서 79 사이일 때 모두 80개의 소수를 만들어냅니다. 이 식의 계수의 곱은 -79 × 1601 = -126479가 됩니다.
 *
 * 아래와 같은 모양의 2차식이 있다고 가정했을 때,
 *
 * n2 + an + b   (단 | a | < 1000, | b | < 1000)
 * 0부터 시작하는 연속된 n에 대해 가장 많은 소수를 만들어내는 2차식을 찾아서, 그 계수 a와 b의 곱을 구하세요.
 * 
 * 문제의 힌트
 * 오일러의 소수 생성 다항식 x^2 + x + 41 -40 <= x <= 39 에대하여 모두 소수가 된다. 
 * n^2 + an + b 
 * b 는 -999 ~ 999 사이의 소수
 * a+b+1 이 소수
 * value 가 - 인값에대헤서는 절대값 |a|를 해주고 root를 계산해준다.
 * 0부터 시작하는 연속된n에 대해서 위의 2차식으로 소수가 아닌수가 나오면 break;
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define LIMIT 1000 
int is_prime(int value)
{
    int sqrt_value;
    int i;
    int count;
    if(value < 0) {// -(마이너스) 값에 대해서 절대값 계산
        value = value *(-1);
    }
    sqrt_value = (int)sqrt(value);
    for(i=2;i<=sqrt_value;i++){
        if(value%i == 0){
            return false;
        }
    }
    return true;
}


void main(void)
{
    int a,b,n,i,j,value;
    int top_count =0;
    int prime_count = 0;
    int result;
    for(a= -LIMIT+1;a<LIMIT;a++){
        for(b = -LIMIT+1; b<LIMIT;b++) {
            if(!is_prime(b)) continue; 
            for(i = 1; ;i++) {
                value = (i*i)+(a*i)+b;
                if(is_prime(value)) {
                    prime_count++;
                //    printf("a:%d b:%d n:%d value:%d prime_count:%d\n",a, b,i,value, prime_count);
                } else {
                    break;
                }
            }
            if(top_count < prime_count) {
                top_count = prime_count;
                printf("a:%d b:%d prime_count:%d result = %d\n",a,b,prime_count,a*b);
            }
            prime_count=0;
        }

    }
}

