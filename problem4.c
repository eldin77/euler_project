#include <stdio.h>
/*대칭수
 * 대칭수의 특성 123321
 * 11로 나누었을때 나누어떨어진다.
 *
 * 11로 나누어떨어지는것들중에 뒤에 자리수를 swap한후에 비교하였을때 같은값이면 대칭수
 *
 * */
int swap_num(int num_temp)
{
    int num_next = NULL;

    while(num_temp>0){
        num_next*=10;
        num_next+=num_temp%10;
        num_temp/=10;
    }
    return num_next;
}

void main(void)
{
    int x,y;
    int tmp1;
    int tmp2;
    int result;
    int top_num = 0;
    for(x = 100;x <=999;x++) {
        for(y=100;y <999;y++) {
            result = x*y;
            if((result % 11) ==0){
                tmp1= result / 1000;
                tmp2 = swap_num(result % 1000);

                if(tmp1 == tmp2){
                    if(top_num < result){
                        top_num = result;
                    }
                }
            }
        }
    }
    printf("top num = %d\n",top_num);
}
