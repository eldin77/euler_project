#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2048
/* 20x20 격자의 경로 
 * 단, 거슬러 가지는 않기로
 *
 * 20x20에서 일렬로 갈수있는건 40
 * 수열과 조합의 이해가 필요.
 * 조합(combination) nCr 공식
 * n = 40 (20x20 격자를 일렬로 늘어트린 길이)
 * r = 20
 * nCr = n!/(n-r)!r!
 *
 * result = 40!/(40-20)!20!
 *
 */
int pact(int * value_buf,int value)
{
    int carry_buf[MAX] = {0};
    
    int i,j;
    int result;
    int carry_count=0;

    for(i = 0;i<value;i++){
        for(j=0;j<=carry_count;j++){
            if((value_buf[j]*(i+1)) < 99999) {
                value_buf[j] *= (i+1);
            } else {
                carry_buf[j+1] = value_buf[j]*(i+1) / 100000;
                value_buf[j] = value_buf[j]*(i+1) % 100000;
                carry_count++;
            }
        }
        for(j = 0;j<=carry_count;j++){
            value_buf[j] += carry_buf[j];
            //printf("%d = %d\n",j, carry_buf[j]);
            carry_buf[j] = 0;
        }
    }

    return true;
}

void main(void)
{
    int value_buf1[MAX] =  {1};
    int value_buf2[MAX] =  {1};
    int i;
    pact(value_buf1,40);
    for(i = 10; i>=0;i--){
        printf("%05d",value_buf1[i]);
    }
    printf("\n");
    
    pact(value_buf2,20);
    for(i = 10; i>=0;i--){
        printf("%05d",value_buf2[i]);
    }
    printf("\n");
    /*계산하면 완료.*/
    //result = 40!/(40-20)!20!
}
