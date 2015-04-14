/*
 * n 개의 숫자가 조합될 수 있는 가지수 = (n-1)!
 *
 * 처음부터 999999개를 세고 그 다음 것이 1000000번째 이므로
 *
 * 999999 = 2*9! + 6*8! + 6*7! + 2*6! + 5*5! + 1*4! + 2*3! + 1*2! + 1*1! + 0*0!
 * 로부터 차례로 숫자를 결정할 수 있다.
 * 
 *
 * 즉, 0123456789 에서 2,6,6,2,5,1,2,1,1,0 번째 숫자들을 차례로 뽑아내면 된다. (0부터 카운트)
 */
#include <stdio.h>
#define USED 0

void main(void)
{
    char CARDS[11] = "0123456789";

    int FACTORIAL[10] = {1,1,};
    int N = 999999;
    int i;

    for (i = 2; i <= 9; ++i){ //1~9까지의 펙토리알을 각각 배열에 넣어준다 1*2*3*4*5*6*7*8*9
        FACTORIAL[i] = i * FACTORIAL[i-1];
        printf("%d : %d\n",i,FACTORIAL[i]);
    }

    for (i = 9; i >= 0; --i)
    {
        int order = 0;
        int count = 0;
        int index;
        if (FACTORIAL[i] <= N)
        {
            order = N / FACTORIAL[i];//1!~9!의 자릿수 구하기.ex) 맨앞자리 999999 / 9! = 2 
            printf("order : %d= %d/%d\n",order, N, FACTORIAL[i]);
            N -= order * FACTORIAL[i];//최초 999999 - 2*9!
            printf("N:%d\n",N);
        }
        for (index = 0; index < 10; ++index)
        {
            if (CARDS[index] != USED){//중복체크
                printf("index = %d\n",index);
                if (count++ == order)
                    break;
            }
        }
            printf ("%c\n", CARDS[index]);
        CARDS[index] = USED;//중복을 허용하지 않으므로 사용된 배열에대해서는 0으로 셋팅
    }
    printf ("\n");
}
