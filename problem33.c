/*
 * 이상한 방법으로 약분할 수 있는 분수 찾기
 * 분수 49/98에는 재미있는 성질이 있습니다. 수학을 잘 모르는 사람이 분모와 분자에서 9를 각각 지워서 간단히 하려고 49/98 = 4/8 처럼 계산해도 올바른 결과가 됩니다.
 *
 * 이에 비해 30/50 = 3/5 같은 경우는 다소 진부한 예라고 볼 수 있습니다.
 *
 * 위와 같은 성질을 가지면서 '진부하지 않은' 분수는, 값이 1보다 작고 분자와 분모가 2자리 정수인 경우 모두 4개가 있습니다.
 *
 * 이 4개의 분수를 곱해서 약분했을 때 분모는 얼마입니까?
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10
/* 분자와 분모의 최대공약수를 가지고 서로 나누어 주는게 약분
 */

int bunja[MAX] = {0};
int bunmo[MAX] = {0};
int count = 0;
int compare_value(int i, int j)
{
    double result_one;
    double result_two;
    int index;
    int tmp_one;
    int tmp_two;
    int result = 1;
    tmp_one = j/10;
    tmp_two = i%10;
    result_one = (double)j/(double)i;
    result_two = (double)tmp_one/(double)tmp_two;
    if(result_one == result_two){
        printf("one %d / %d = %f\n",j,i,(double)j/(double)i);
        printf("two %d / %d = %f\n",tmp_one,tmp_two,(double)tmp_one/(double)tmp_two);
        bunja[count] = j;
        bunmo[count] = i;
        count++;
    }
    return result;
}

int is_prime(unsigned long long value)
{
    unsigned long long sqrt_value;
    unsigned long long int i;
    sqrt_value = (unsigned long long)sqrt(value);
    for(i = 2; i<=sqrt_value;i++){
        if(value % i == 0){ //약수 구하기
            printf("%llu %llu sqrt_value = %llu\n",i, value/i,sqrt_value);
        }
    }
    return true;
}

void main(void)
{
    int i,j;
    int one_result, two_result;
    int result_bunsu;
    int twice_bunja = 1;
    int twice_bunmo = 1;
    int tmp;
    for(i = 10;i<100;i++) {
        for( j = 10; j < i; j++) {
            if((j%10) == (i/10)) {
                //printf("%d %d\n",j,i);
                result_bunsu = compare_value(i,j);
                //printf("%s:bunja:%d bunmo:%d\n",__FUNCTION__,result_bunsu.bunja,result_bunsu.bunmo);
            }
        }
    }
    for(i = 0; i < count; i++){
        twice_bunja *= bunja[i];
        twice_bunmo *= bunmo[i];
    }
    if((twice_bunmo % twice_bunja) == 0){
        tmp = twice_bunja;
        printf("twice_bunja = %d\n",tmp);
    }
    //is_prime(100);

    printf("%d/%d = %d / %d %d\n",twice_bunja, twice_bunmo, twice_bunja/tmp, twice_bunmo/tmp, twice_bunja%twice_bunmo);
}
