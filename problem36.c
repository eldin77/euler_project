/* 대칭수(palindrome)인 585는 2진수로 나타내도 10010010012가 되어 여전히 대칭수입니다.
 *
 * 10진법과 2진법으로 모두 대칭수인 1,000,000 이하 숫자의 합을 구하세요.
 *
 * (주의: 첫번째 자리가 0이면 대칭수가 아님)
 */
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define MAX_NUM 1000000 

unsigned long long swap_num(unsigned long long num_temp, int unsigned long long digit)
{
    unsigned long long num_next = 0;
    int i;
    for(i = 0; i<digit;i++){
        num_next*=10;
        num_next+=num_temp%10;
        num_temp/=10;
    }
    return num_next;
}

unsigned long long digit_num(unsigned long long index)
{
    unsigned long long digit = 0;
    while(1){
        digit++;
        if(index/10 ==0) break;
        index = index/10;
    }
    return digit;
}

unsigned long long dectobin(unsigned long long value)
{
    unsigned long long tmp = 0;
    unsigned long long sum = 0;
    unsigned long long i = 1;
    while(1){
        tmp = value%2;
        sum+= tmp*i;
        value = value/2;
        if(value == 0) break;
        i *= 10;
    }
    //printf("tmp = %llu\n",sum);
    return sum;
}

int compare_value(unsigned long long bin, unsigned long long digit)
{
    int i;
    unsigned long long tmp = 1;
    unsigned long long right,left; 
    unsigned long long div;
    div = digit/2;
    if(digit%2 == 0){
        for(i = 0; i<div;i++){
            tmp = tmp*10;
        }
        right = swap_num(bin%tmp, div);
        left = bin/tmp;
    } else {
        for(i = 0; i<div;i++){
            tmp = tmp*10;
        }
        right = swap_num((bin%(tmp*10)), div);
        left = bin/(tmp*10);
    }
    //printf("%llu:%llu : %llu\n",bin,left,right);
    if(right == left) {
        return true;
    } else {
        return false;
    }
}

void main(void)
{
    int index = 0;
    unsigned long long digit;
    int div;
    unsigned long long tmp;
    unsigned long long result = 0;
    clock_t start_time, end_time;

    start_time = clock();

    while(index < MAX_NUM) {
        digit = digit_num(index);
        if(compare_value(index, digit)){
            tmp = dectobin((unsigned long long)index);
            digit = digit_num(tmp);
            if( tmp%10 != 0 ){
                if(compare_value(tmp, digit)){
                    printf("%llu,%d:%llu\n",digit,index,tmp);
                    result += index;
                }
            }
        }
        index++;
    }
    end_time = clock();
    printf("result = %llu time = %f\n",result,(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
