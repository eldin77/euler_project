#include <stdio.h>
/* 무한히 순환하는 정수 가온데.
 *
 * 반복되는 순간의 숫자가 순환의 시작점
 *
 * 분자가 1인 분수를 단위분수라고 합니다. 분모가 2에서 10까지의 단위분수는 아래와 같습니다.
 *
 * 숫자 위에 찍힌 점은 순환마디를 나타내는데, 1/6의 경우 순환마디는 "6"으로 0.166666...처럼 6이 무한히 반복됨을 뜻합니다. 
 *
 * 같은 식으로 1/7은 6자리의 순환마디(142857)를 가집니다.
 *
 * d 를 1000 이하의 정수라고 할 때, 단위분수 1/d 의 순환마디가 가장 긴 수는 무엇입니까?
 *
 * */
int search(int remain, int * tmp_buf,int count)
{
    int i;
    for(i = 0;i <= count;i++){
        if(tmp_buf[i] == remain) return i;
    }
    return -1;
}

int check_cycle(int value)
{
    int tmp_buf[1024] = {0};
    int dividend = 1;
    int n = 0;
    int remain;
    int index = 0;
    int search_index;
    while(1){
        remain = dividend % value;//1. 1/3 일때 나머지가 0이 되면 순환 시작 
        search_index = search(remain, tmp_buf, n);
        if(search_index != -1){
            printf("1. %d remain : %d, dividend : %d\n",value,remain, dividend);
            return n - search_index;
        } else {
            tmp_buf[index] = remain;
            dividend = remain * 10;//2. dividend = 10
            printf("2. %d remain : %d, dividend : %d\n",value,remain, dividend);
            index++;
            n++;
        }
    }
}
 
void main(void)
{
    int i= 10;
    int result = 0;
    int remind = 0;
    int n = 0;
    int dividend = 1;
    int top = 0;
    int top_tmp = 0;
    
    for(i=2;i<10;i++){
        result = check_cycle(i);
        //printf("%d:%d\n",i,result);
        if(top < result) {
            top = result;//가장큰 순환소수 갯수 
            top_tmp = i;//순환소수의 개수가 가장 많은 정수 
        }
    }
    printf("top result = %d %d\n",top_tmp,top);
}
