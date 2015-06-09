/*숫자 192에 1, 2, 3을 각각 곱합니다.
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * 곱한 결과를 모두 이어보면 192384576 이고, 이것은 1 ~ 9 팬디지털(pandigital)인 숫자입니다. 이런 과정을 편의상 '곱해서 이어붙이기'라고 부르기로 합니다.
 *
 * 같은 식으로 9와 (1, 2, 3, 4, 5)를 곱해서 이어붙이면 918273645 라는 1 ~ 9 팬디지털 숫자를 얻습니다.
 *
 * 어떤 정수와 (1, 2, ... , n)을 곱해서 이어붙였을 때 얻을 수 있는 가장 큰 아홉자리의 1 ~ 9 팬디지털 숫자는 무엇입니까? (단 n > 1)
 *
 * i = 1~9999
 * n = 1~n 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 11
int check_pand_buf(int * pand_buf)
{
    int i;
    for(i = 1; i<=9;i++) {
        if(pand_buf[i] == 0 || pand_buf[i] > 1) {
            return false;
        } 
    }
    return true;
}
void main(void)
{
    int index,i,j, n = 0;
    int digit_count = 0;
    int pand_buf[MAX] = {0};
    int result = 1; 
    int tmp;
    int tmp_index;
    int flag = 0; 
    for(index = 1; index<10000;index++) {
        n = 1;
        while(1) {
            tmp = index*n;
            while(1){
                tmp_index = tmp%10;
                pand_buf[tmp_index] += 1;
                digit_count++;
                if(tmp/10 == 0) break;
                tmp = tmp/10;
            }

            if(digit_count >= 9) {
                //pand_buf check
                if(digit_count == 9){
                    if(pand_buf[0] == 0){
                        if(check_pand_buf(pand_buf)) {
                            for(j=1;j<=n;j++){
                                printf("%d",index*j);
                            }
                            printf("\n");
                        }
                    }
                }
                digit_count = 0;
                memset(pand_buf, 0, sizeof(int)*MAX);
                break;
            }
            n++;
        }
    }
}
