#include <stdio.h>
/*최소공배수 구하기 문제*/
/*최대공약수 구하기 문제*/
/*
 * 두값의 최대공약수가 있으면, 그 최소값을 최대공약수값으로 나눈후에 나눈값으로 서로 곱하면 최소공배수이다.
 * n1, n2 의 최소공배수는 = n1*n2/n1,n2의 최대공약수
 * 2,20 2가 4번
 * 3,20 3이 두번
 * ...
 */
void main(void)
{
    int i,k,j;
    int result=1;
    int max = 20;

    for(i = 2; i < max; i++)
    {
        for(j = 2; j < i; j++)
        {
            if(i%j == 0){
                break;
            }
        }
        printf("%d:%d\n",i,j);
        if(i == j)
        {
            for(k = j; k < max; k = k*j){
                result = result * j;
                printf("sec insert = %d:%d = %d result : %d\n",i,j,k,result);
            }
        }
    }
    printf("%d\n",result);

}
