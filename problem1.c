#include <stdio.h>
/*3과 5의 배수 구하기*/
/*10보다 작은 자연수 중에서 3 또는 5의 배수는 3, 5, 6, 9 이고, 이것을 모두 더하면 23입니다.
 *1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면 얼마일까요?
 * */
void main(void)
{
    int max_count = 1000;
    int index, result;

    for(index = 0; index < max_count; index++){
        if((index % 3 == 0 || index % 5 ==0)){
            result += index;
        }
    }
    printf("result = %d\n",result);
}
