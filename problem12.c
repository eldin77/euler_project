/*
 *1부터 n까지의 자연수를 차례로 더하여 구해진 값을 삼각수라고 합니다.
 예를 들어 7번째 삼각수는 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28이 됩니다.
 이런 식으로 삼각수를 구해 나가면 다음과 같습니다.

 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 이 삼각수들의 약수를 구해봅시다.

  1: 1
   3: 1, 3
    6: 1, 2, 3, 6
10: 1, 2, 5, 10
15: 1, 3, 5, 15
21: 1, 3, 7, 21
28: 1, 2, 4, 7, 14, 28
위에서 보듯이, 5개 이상의 약수를 갖는 첫번째 삼각수는 28입니다.

그러면 500개 이상의 약수를 갖는 가장 작은 삼각수는 얼마입니까?
 */
#include <stdio.h>
#include <time.h>
#include <math.h>
void main(void)
{
    int j=1;
    int count = 0;
    unsigned long result = 0;
    unsigned long sum = 0; 
    int value;
    unsigned long i = 0,index = 0;
    clock_t start_time, end_time;
    start_time = clock(); 
    while(1){
        sum += index;
        index++;
        value = (int)sqrt(sum);
        //printf("%lu:",index);
        for(i = 1; i<=value;i++){
        //for(i = 1; i<=sum;i++){
            if(sum%i == 0){
                //printf("%lu ",i);
                count++;
                //if(i == sum/i) count++;
                //else count+=2;
            }
        }
        //printf(":%d \n",count);
        if(count >= 250){
            break;
        } else {
            count = 0;
        }

    }
    end_time = clock(); 
    printf("sum = %lu time = %f\n",sum,(double)(end_time - start_time)/CLOCKS_PER_SEC);
}
