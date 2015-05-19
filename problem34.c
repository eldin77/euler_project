/* 숫자 145에는 신기한 성질이 있습니다. 
 * 각 자릿수의 팩토리얼(계승)을 더하면  1! + 4! + 5! = 1 + 24 + 120 = 145 처럼 자기 자신이 됩니다.
 *
 * 이렇게 각 자릿수의 팩토리얼을 더하면 자기 자신이 되는 모든 수의 합을 구하세요.
 *
 * 단, 1! = 1 과 2! = 2 의 경우는 덧셈이 아니므로 제외합니다.
 *
 * 0! = 1 이고 
 * 9!을 자릿수를 높여가면서 더하면
 * 7째자리가넘어가게되면 자릿수값이 더한 값을 넘어가게된다 그래서 범위는 999999 까지
 */
#include <stdio.h>
#define MAX 10
#define MAX_VALUE 1000000 
unsigned int pact_buf[MAX] = {1};

unsigned int pact(unsigned int value)
{
    unsigned int result = 1;
    int i;
    for(i=1;i<=value;i++){
        result = result*i;
    }
    return result;
}

unsigned int digit_sum(unsigned int value)
{
    unsigned int tmp = value;
    unsigned int digit_value;
    unsigned int total_sum = 0;  
    
    while(1){
        digit_value = tmp % 10;
        total_sum = total_sum + pact_buf[digit_value];
        tmp = tmp / 10;
        if(tmp == 0) break;
    }
    
    return total_sum;
}

void main(void)
{
    unsigned int i;
    unsigned int result = 0; 
    for(i = 1; i<MAX;i++){
        pact_buf[i] = pact(i);
        printf("%d ",pact_buf[i]);
    }
    printf("\n");
    for(i = 3; i<=MAX_VALUE; i++){
        if(i == digit_sum(i)){
            printf("%d\n",i);
            result = result+i;
        }
    }
    printf("result = %d\n",result);
}

