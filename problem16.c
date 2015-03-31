/*  2^15 = 32768 의 각 자리수를 더하면 3 + 2 + 7 + 6 + 8 = 26 입니다.
 *
 *  2^%1000의 각 자리수를 모두 더하면 얼마입니까?
 * 2^1000 = ? 자리수의 합
 * c에서는 2^1000의 자리수가 넘어가기 때문에 carry bit를 이용해 carry가 발생하면 증가되는 모든 배열에 * 2
 * carry비트가 발생하면 +1을 해준다.
 *
 * */

#include <stdio.h>

void main(void)
{
    int arys[1000] = { 1 };
    int buf_arys[1000] = { 0 };
    int axis = 0;
    int i, j;
    int result=0;
    int base = 2;
    for (i = 1; i <= 1000; i++)
    {
        int signal_to_expand = 0;
        for (j = 0; j <= axis; j++)
        {
            if (arys[j] * base<99999) arys[j] *= base;
            else
            {
                buf_arys[j + 1] += (arys[j] * base) / 100000;
                arys[j] = (arys[j] * base) % 100000;
                if (j == axis) signal_to_expand = 1;
            }
            //printf("arys[j] = %d\n",arys[j]);
        }
        if (signal_to_expand)
        {
            axis++;
        }
        for (j = 0; j <= axis; j++)
        {
            arys[j] += buf_arys[j];
            buf_arys[j] = 0;
        }
    }
    for (i = 0; i <= axis; i++)
    {
        result += arys[i] / 10000 + arys[i] % 10000 / 1000 + arys[i] % 1000 / 100 + arys[i] % 100 / 10 + arys[i] % 10;
    }
    printf("%d\n",result);
}
