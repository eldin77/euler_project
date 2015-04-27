/*
 * 각 자리의 숫자를 4제곱해서 더했을 때 자기 자신이 되는 수는 놀랍게도 단 세 개밖에 없습니다.
 *
 * 1634 = 14 + 64 + 34 + 44
 * 8208 = 84 + 24 + 04 + 84
 * 9474 = 94 + 44 + 74 + 44
 * (1 = 14의 경우는 엄밀히 말해 합이 아니므로 제외합니다)
 *
 * 위의 세 숫자를 모두 더하면 1634 + 8208 + 9474 = 19316 입니다.
 *
 * 그렇다면, 각 자리 숫자를 5제곱해서 더했을 때 자기 자신이 되는 수들의 합은 얼마입니까?
 *
 * 9^5의 의 자릿수를 증가해가면서  9^5들의 자리 수들의 합의 자릿수가 증가되는 자릿수보다 작아질때가 i의 limit값
 */

#include <stdio.h>

void main(void)
{
    int tmp = 0;
    int sum = 0;
    int namo_tmp = 0;
    int result = 0;
    int i;
    int total_value = 0;
    int index=1;
    int tmp_limit,limit_index,limit;
    int max_value=0;
    /* loop의 limit 찾아내는 부분*/ 
    while(1){
        limit = 1;
        limit_index = 2;
        for(i=1;i<=5;i++){
            limit = limit*9; 
        }
        tmp_limit = limit*index;
        while(1) {
            tmp_limit = tmp_limit/10;
            if(tmp_limit == 0) break;
            limit_index++;
        }
        if(index > limit_index){
            limit = limit*index;
            break;
        }
        index++;
    }

    for(i=2;i<=limit;i++){
        tmp = i;
        while(1){
            namo_tmp = tmp%10;
            result += (namo_tmp * namo_tmp * namo_tmp * namo_tmp * namo_tmp);
            tmp = tmp/10;
            if(tmp == 0) break;
        }
        if(i == result){
            printf("result = %d\n",result);
            total_value += result;
        }
        result = 0;
    }
    printf("total value =%d\n",total_value);
}
