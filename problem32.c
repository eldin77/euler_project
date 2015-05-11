/* 1부터 n까지의 각 숫자를 한번씩만 써서 만들 수 있는 숫자를 팬디지털(pandigital)이라고 합니다.
 * 예를 들면 15234는 1부터 5의 숫자가 한번씩만 쓰였으므로 1 ~ 5 팬디지털입니다.
 *
 * 7254라는 숫자는 그런 면에서 특이한데, 39 × 186 = 7254 라는 곱셈식을 만들 때 이것이 1 ~ 9 팬디지털이 되기 때문입니다.
 *
 * 이런 식으로 a × b = c 가 1 ~ 9 팬디지털이 되는 모든 c의 합은 얼마입니까?
 *
 * (참고: 어떤 c는 두 개 이상의 (a, b)쌍에 대응될 수도 있는데, 이런 경우는 하나로 칩니다)
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 11

int num[MAX] = {0};
int set_num(int value)
{
    int tmp, index;

    tmp = value;
    while(1){
        index = tmp%10;
        num[index] = num[index]+1;
        //printf("value= %d index = %d\n",value, index);
        tmp = tmp/10;
        if(tmp == 0) break;
    }
 
}

int check_num(int a, int b, int twice)
{
    int i;
    int tmp,index;

    memset(num, 0, sizeof(int)*10);
    set_num(a);
    set_num(b);
    set_num(twice);
    
    for(i = 1; i<=9;i++){
        if(num[i] == 1){
        } else {
            memset(num, 0, sizeof(int)*10);
            return false;
        }
    }
    return true;
}

void main(void)
{
    int a,b;
    int twice;
    int result = 0;
    int result_buf[20] = {0};
    int count = 0;
    int i, same = 0;

    memset(num, 0, sizeof(int)*10);
    memset(result_buf, 0, sizeof(int)*20);
    for(a = 1; a<=2000; a++){
        for(b = 1;b<=2000;b++){
            twice = a*b;
            if(check_num(a,b,twice)){
                if(num[0]>=1) continue;
                printf("%d * %d = %d\n",a,b,twice);
                for(i=0;i<=20;i++){
                    if(twice == result_buf[i]){
                        result_buf[i] = twice;
                        same = 1;
                        break;
                    }
                }
                if(same !=1){
                    result_buf[count] = twice;
                }
                count++;
                same = 0;
                //result += twice;
            }
        }
    }
    for(i = 0; i<=20;i++){
        result += result_buf[i];
    }

    printf("result = %d\n",result);
}
