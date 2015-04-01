/* 1부터 5까지의 숫자를 영어로 쓰면 one, two, three, four, five 이고,
 * 각 단어의 길이를 더하면 3 + 3 + 5 + 4 + 4 = 19 이므로 사용된 글자는 모두 19개입니다.
 *
 * 1부터 1,000까지 영어로 썼을 때는 모두 몇 개의 글자를 사용해야 할까요?
 *
 * 참고: 빈 칸이나 하이픈('-')은 셈에서 제외하며, 단어 사이의 and 는 셈에 넣습니다.
 *   예를 들어 342를 영어로 쓰면 three hundred and forty-two 가 되어서 23 글자,
 *     115 = one hundred and fifteen 의 경우에는 20 글자가 됩니다.
 */

#include <stdio.h>
#include <string.h>
#define MAX 2048
void main(void)
{
    char number[MAX] =  {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
    char position[MAX] =  {0,4,6,6,5,5,5,7,6,6};
    char *thousand = "onethousand";

    int count = 0;
    int i,j;
    int sub_total = 0;
    int sec_total = 0;
    int total = 0;
    int result = 0;
    int value;
    for(i=1;i<1000;i++){ 
        sub_total = i/100;
        if(sub_total != 0){
            result += 10+number[sub_total];
        }
        sub_total = i%100;
        value = i%100;

        if(value == 0) {
            result -= 3;
            continue;
        }
         
        //printf("i:j:num:result = %d:%d: %d:%d\n",i,sub_total, number[sub_total],result);
        if(sub_total < 20){
            result += number[sub_total];
            continue;
        }
        for(j= 0;j<=count;j++){
            sec_total = value%10;
            if(count == 0){
                result +=number[sec_total];
            }else{
                result +=position[sec_total];
            }
            value = value/10;
            if(value == 0) break;
            count++;
        }
        count = 0;
    }
    printf("result = %ld\n",result+strlen(thousand));
}
