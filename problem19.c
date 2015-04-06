/*다음은 달력에 관한 몇 가지 일반적인 정보입니다 (필요한 경우 좀 더 연구를 해 보셔도 좋습니다).

1900년 1월 1일은 월요일이다.
4월, 6월, 9월, 11월은 30일까지 있고, 1월, 3월, 5월, 7월, 8월, 10월, 12월은 31일까지 있다.
2월은 28일이지만, 윤년에는 29일까지 있다.
윤년은 연도를 4로 나누어 떨어지는 해를 말한다. 하지만 400으로 나누어 떨어지지 않는 매 100년째는 윤년이 아니며, 400으로 나누어 떨어지면 윤년이다
20세기 (1901년 1월 1일 ~ 2000년 12월 31일) 에서, 매월 1일이 일요일인 경우는 총 몇 번입니까?*/

#include <stdio.h>

void main(void)
{
    int year = 1901;
    int mon = 1;//1~12
    int date = 1;//최대 1~31
    int date_max = 30;//최대 1~31
    int one_seven_count = 0;
    int week = 1;//월~금 1~7
    int i;

    while(1){
        if(year == 2001) break;
        if(mon == 4 ||
                mon == 6 ||
                mon == 9 ||
                mon == 11){
            date_max = 30;
        } else if (mon == 2) {
            if((year % 400 == 0) && (year % 4 == 0)){
                date_max = 29;
            } else {
                date_max = 28;
            }
        } else {
            date_max = 31;
        }
        for(date = 1; date <=date_max;date++){
            if(week == 8){ 
                week = 1;
            }
            if(date == 1 && week == 7){
                printf("%d:%d:%d\n",year, mon, week);
                one_seven_count++;

            }
            week++;
        }
        mon++;
        if(mon == 13) {
            mon = 1;
            year++;
        }
    }
    printf("result = %d\n",one_seven_count);

}
/* 맵을 이용한 방법
   int map[2][12] = {
   {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}    };


   int main() 
   {
   int count = 0;
   int day = 366; //1901년 1월 1일은 1900년 1월 1일(이날을 1일이라고 했을 때)로부터 366일째 되는날
   for(int year = 1901 ; year < 2001;  year++) {
        int yoon = ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0 );  //윤달
            for(int month = 0 ; month < 12 ; month++ ) {
                if ( 0 == (day+=map[yoon][month]) % 7 ) ++count ;
            }
   }
   printf("%d", count);
   return 0;
   }
 */
