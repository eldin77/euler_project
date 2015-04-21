#include <stdio.h>
/*
 * 숫자 1부터 시작해서 우측으로부터 시계방향으로 감아 5×5 행렬을 만들면 아래와 같이 됩니다.
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * 여기서 대각선상의 숫자를 모두 더한 값은 101 입니다.
 *
 * 같은 방식으로 1001×1001 행렬을 만들었을 때, 대각선상의 숫자를 더하면 얼마가 됩니까?
 *
 * 계차수열을 묻는문제...
 * 계차 수열이란 : 인접하는 두항의 차로 이루어지는 수열로,
 * 수열 an에 다하여
 *
 * an = a1 + sum(k=1 to n-1)
 * 를 이용하여 하여 응용하면, 증가하는 인덱스가 +2씩 증가하고 1001 까지 증가한다.
 * 증가하기 전에 1~n까지 4번씩 증가해서 더해주고 인덱스가 1001이 되면 break
 * 
 */
void main(void)
{
    int hang = 1001;
    int value;
    int sum_value = 0;
    int tmp_value = 0;
    int index_value = 0;
    int i;

    value = 1001*1001;
    index_value = hang-1;
    tmp_value = value;
    sum_value = tmp_value;
    while(1){
        for(i = 0;i < 4;i++){ //사각형 대각선 배열의 합이므로 대각선의 값들은 4개씩
            if(tmp_value == 1) break;
            tmp_value = tmp_value - (index_value);
            sum_value += tmp_value; //대각선의 배열을 더해주는 값
            printf("tmp_value = %d sum_value = %d index_value = %d\n",tmp_value,sum_value,index_value);
            
        }
        index_value = index_value-2; //한번 4번씩 돌면 index를 2씩 줄여준다. 다른방법으로 늘려가면서 계산해도 된다.
        if(index_value < 0) {
            break;
        }
    }
}
