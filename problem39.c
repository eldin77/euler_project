/* 세 변의 길이가 모두 자연수 {a, b, c}인 직각삼각형의 둘레를 p 로 둘 때, p = 120 을 만족하는 직각삼각형은 아래와 같이 세 개가 있습니다.
 *
 * {20, 48, 52}, {24, 45, 51}, {30, 40, 50}
 * 1000 이하의 둘레 p에 대해서, 직각삼각형이 가장 많이 만들어지는 p의 값은 얼마입니까?
 *
 *
 * a^2 + b^2 = c^2
 * a + b + c = p 
 * a = p - b - c 
 * b = p - a - c
 * c = p - a - b
 * x = p - a 치환
 * a^2 + (x - c)^2 = (x - b)^2
 */

#include <stdio.h>
#include <math.h>
#include <time.h>

void main(void)
{
    int a,b,c,i,j,p,x;
    int count = 0;
    int top_count = 0;
    int top_index = 0;
    clock_t start_time, end_time;

    start_time = clock();
    //둘레 j = 1000이하
    for(j = 5;j<=1000;j++) {
        for(i = 1;i<j;i++)
        {
            a = i;
            x = j - i;
            c = (a*a + x*x)/(2*x);
            b = j - a - c;
            if(a*a + b*b == c*c && b > 0 ) {
                    printf("%d:%d:%d:%d\n",a,b,c,j);
                    count++;
            }
        }
        if(top_count <= count) {
            top_count = count;
            top_index = j;
        }
        count = 0;
    }
    end_time = clock();
    printf("result : %d:%d time = %f\n",top_count/2,top_index, (double)(end_time-start_time)/CLOCKS_PER_SEC);
}
