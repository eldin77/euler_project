/*피보나치 수열은 아래와 같은 점화식으로 정의됩니다.

Fn = Fn-1 + Fn-2  (단, F1 = 1, F2 = 1).
이에 따라 수열을 12번째 항까지 차례대로 계산하면 다음과 같습니다.

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
수열의 값은 F12에서 처음으로 3자리가 됩니다.

피보나치 수열에서 값이 처음으로 1000자리가 되는 것은 몇번째 항입니까?*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEVIDE 10000000000
void main(void)
{
    unsigned long long one_result[102] = {0}; 
    unsigned long long two_result[102]={0}; 
    unsigned long long tmp_result[102]={0}; 
    int count = 0;
    int tmp_count = 0;
    int index = 5;
    unsigned long long sum_devide = 0;
    unsigned long long sum_namo;
    unsigned long long tmp_value_one;

    one_result[count] = 2;
    two_result[count] = 3;
    int i,j,x;
    clock_t start_time, end_time;
    start_time = clock();
    while(1){
        for(i = 0;i <= count;i++) {
        tmp_result[i] = one_result[i] + two_result[i] + sum_devide;//발생된 케리부분을 더해주는 부분
            //printf("%d %010llu = %010llu + %010llu\n",i,tmp_result[i], one_result[i], two_result[i]);
            if(tmp_result[i]/DEVIDE != 0){
                /*
                 *  + 연산에서 자릿수가 올라가는 케리가 발생하면 발생한 만큼의 수를 상위 배열에 더해준다
                 */
                sum_devide = tmp_result[i]/DEVIDE;//10자리씩 끊어서 배열에 넣어준다. 10자리가 넘어가면 상위 배열로 자리수를 채움
                sum_namo = tmp_result[i]%DEVIDE;
                tmp_result[i] = sum_namo;//10자리씩 끊어서 배열에 넣어줌.
                if(i == count){
                    tmp_result[i+1] = sum_devide;//최상위 배열에 더해주는부분
                    count++;
                    if(count==100){
                        printf("index = %d\n",index);
                    }
                    break; 
                }
            } else {
                /*
                 * +연산에서 자릿수가 올라가는 케리가 발생하지 않으면 결과값에 0을 더해준다.
                 */
                tmp_result[i] = tmp_result[i];
                sum_devide = 0;
            }
        }
 #if 0
            for(j = count;j>=0;j--){
                printf("%010llu ",tmp_result[j]);
            }
            printf("\n");
        }
#endif
        /*
         * 99번째배열의 숫자들이 다채워지면 1000자리숫자가된다.
         * 해당 배열의 자릿수가 최초로 10인 자릿수를 리턴 받으면 처음으로 1000자리가 되는 항
         * 
         */
        if(count == 99){
            int total_count = 1;
            unsigned int tmp_value = 0;
            tmp_value = tmp_result[count];

            while(1){
              //  printf("result = %d %d %010llu %d\n",index, total_count,tmp_result[count],tmp_value);
                if(tmp_value/10 == 0){
                    break;
                } else{
                    total_count++;
                }
                if(total_count == 10){
                    end_time = clock();
                    printf("result = %dtime = %f\n",index,(double)((end_time-start_time)/CLOCKS_PER_SEC));
                    return;
                }
                tmp_value = tmp_value/10;
            }
        }
       
        for(x = 0; x<=count;x++){
            one_result[x] = two_result[x];
            two_result[x] = tmp_result[x];
        }
        index++;
        if(count == 100) break;
    }
}
#else

#include <stdio.h>
#define LENGTH 1000

typedef unsigned char UINT8;
typedef unsigned short int UINT16;
typedef unsigned long int UINT32;

void main(void)
{
    UINT16 F[2][LENGTH] = {{1, 0}, {1, 0}}; 
    UINT16 num_of_digits = 1;
    UINT16 n = 2;

    while (num_of_digits < LENGTH)
    {
        UINT16 current  = (++n) % 2;
        UINT16 previous = (n-1) % 2;
        UINT16 count = 0;
        UINT16 carry = 0;
        while (count < num_of_digits || carry != 0)
        {
            F[current][count] += F[previous][count] + carry;
            carry = F[current][count] / 10;         
            F[current][count] %= 10;
            ++count;
        }
        num_of_digits = count;
    }
    printf ("%u", n);
}
#endif
