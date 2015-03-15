#include <stdio.h>
/*피보나치 수열의 각 항은 바로 앞의 항 두 개를 더한 것이 됩니다. 1과 2로 시작하는 경우 이 수열은 아래와 같습니다.
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 짝수이면서 4백만 이하인 모든 항을 더하면 얼마가 됩니까?
 */

void main(void)
{
    int max_index = 4000000;
    int first_index=1;
    int second_index=2; 
    int sum= 2;
    int result=0;
    while(result <= max_index){
        if((result % 2 == 0) && result <= max_index){
            sum = sum+result;
            printf("%d + %d = sum = %d\n",first_index, second_index, sum);
        }
        result = first_index+second_index;
        first_index = second_index;
        second_index = result;
    }
    printf("sum = %d\n",sum);
}
