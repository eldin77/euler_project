/*
 * 한 자리의 수의 모든 문자 = 9
 * 2 자리 수의 모든 문자(10~99) = 90*2
 * n번째 자리 수의 모든 문자 = n*9*10^(n-1)
 */

#include <stdio.h>
unsigned int count = 0;
unsigned int tmp_count = 1;
unsigned int before_value = 0;

int swap(int value)
{
    int tmp = value;
    int result = 0;
    int namo_value;
    int i,count=0;
    while(1){
        count++;
        tmp = tmp/10;
        if(tmp/10 == 0) break;
    }
    tmp = value;
   
    while(1){
        namo_value = tmp%10;
        result += namo_value;
        if(tmp/10 == 0) break;
        tmp = tmp/10;
        result *= 10;
    }
    return result; 
}

int value_cmp(int value)
{
    int tmp = value;
    int count=0;
    while(1){
        count++;
        tmp = tmp/10;
        if(tmp/10 == 0) break;
    }
    return count;
}

void digit_num(int value)
{
    int tmp = (value);
    int div;
    
    while(1){
        div = tmp%10;
        if((tmp / 10) == 0) {
            count++;
            if(count == (tmp_count-1) ){
                before_value = value;
            }
            if(count == tmp_count){
                tmp_count *=10;
                printf("count %d : %d : %d\n",count,div, value);
            }
            break;
        } else {
            count++;
            if(count == (tmp_count-1)){
                before_value = value;
            }

            tmp = tmp/10;
            if(count == tmp_count){
                tmp_count *=10;
                printf("count %d : %d : %d\n",count, div, value);
            }
        }
        if(before_value == value){
            printf("same value %d : %d : %d\n",count, div, value);
        }
    }
}

void main(void)
{
    int index=0;
#if 1
    while(1){
        index++;
        digit_num(index);
        if(tmp_count >= 10000000) break;
    }
#endif
}
