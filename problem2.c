#include <stdio.h>
/*피보나치 수열*/
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
