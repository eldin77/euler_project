/* n! 이라는 표기법은 n × (n − 1) × ... × 3 × 2 × 1을 뜻합니다.
 *
 * 예를 들자면 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800 이 되는데,
 * 여기서 10!의 각 자리수를 더해 보면 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27 입니다.
 *
 * 100! 의 자리수를 모두 더하면 얼마입니까?
 * 
 * 100! 의 자릿수를 모두 더하면
 * 무식한 방법으로 계산하다보면 c에서 할수있는 자료형의 숫자를 넘어간다
 * 더하기나 곱하기를 하였을때 발생하는 캐리를 이용하여 계산
 * 자릴수마다 곱하거나 더했을때
 * 더하면 다음자릿수에 발생한 케리만큼 더하기
 * 곱하면 발생한 케리를 다음자릿수에 더해주고 곱하기 해당값
 * ex1) 2 * 8 했을경우 케리가 1이 발생
 * 다음자리수에 1을 더해주고 6을 써주면 16
 * ex2) 16 * 2 했을경우
 * 2*6 = 12 케리 1 발생
 * 1*2 = 발생하지 않음
 * 10의자리는2 일의자리는2 일의자리에서 발생한 케리 1을 십의자리에 더해준다.
 * 결과는 32
 * */


#include <stdio.h>
#include <string.h>
#define MAX 2048 

void main(void)
{
    int value_buf[MAX] = {1};
    int carry_buf[MAX] = {0};
    int i,j;
    int result = 0;
    int carry_count=0;
    int signal_to_extend;
    int value;
    //memset(buf, 0, MAX);
    for(i = 0;i<100;i++){
        for(j=0;j<=carry_count;j++){
            if((value_buf[j]*(i+1)) < 99999) {
                value_buf[j] *= (i+1);
            } else {
                carry_buf[j+1] = value_buf[j]*(i+1) / 100000;
                value_buf[j] = value_buf[j]*(i+1) % 100000;
                if(carry_count == j) carry_count++;
            }
        }
        for(j = 0;j<=carry_count;j++){
            value_buf[j] += carry_buf[j];
            //printf("%d = %d\n",j, carry_buf[j]);
            carry_buf[j] = 0;
        }
    }
    for(i = carry_count; i>=0;i--){
        value = value_buf[i];
        while(1){
            if(value == 0) break; 
            //printf("value = %d\n",value);
            result += value%10;
            value /= 10;
        }
        printf("%05d",value_buf[i]);
    }
    printf("\nresult :%d\n",result);

}
