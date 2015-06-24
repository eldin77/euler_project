/* 배수판정법 각 자리수를 합이 3의 배수면 소수가 될수 없다.
 * 1~9까지의 합은 45 3의 배수 
 * 1~8까지의 합은 36 3의 배수
 * 1~7까지의 합은 28
 * 1~6까지의 합은 21 3의 배수 
 * 1~5까지의 합은 15 3의 배수
 * 팬디지털 숫자중에 가장큰 소수를 구하므로 1~7까지의 자릿수로 구하면된다.
 * 1~7까지 나열하는 방법은 7!
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 7654321 
#define BUF_MAX 11 

static inline int init_buf(int * pand_buf){
    int i;
    for(i = 0; i <10;i++){
        pand_buf[i] = 0;
    }
}

int is_prime(int value)
{
    int sqrt_value;
    int i;
    sqrt_value = (int)sqrt(value);

    for(i=2;i<=sqrt_value;i++){
        if(value % i ==0){
            return false;
        }
    }
    return true;

} 


int check_buf(int * pand_buf, int count)
{
    int i;
    if(pand_buf[0] >=1 ){
        return false;
    }
    for(i = 1; i<=count; i++){
        //printf("%d count : %d, %d\n",pand_buf[i],count,i);
        if(pand_buf[i] != 1) {
            return false;
        }
    }
    return true;
}
#if 0
void main(void)
{
    int i;
    int tmp;
    int pand_buf[BUF_MAX] = {0};
    int count=0;
    int tmp_i;

    init_buf(pand_buf);
    for( i = 1234567 ; i <= MAX; i++ ) {
        if(is_prime(i)){
            tmp = i;
            while(1){
                tmp_i = tmp%10;
                pand_buf[tmp_i] += 1;
                count++;
                //printf("%d\n",i);
                if(tmp/10 == 0) break; 
                tmp = tmp/10;
            }
            if(check_buf(pand_buf, count)){
                printf("%d:%d\n",count,i);
            }
            count = 0;
            init_buf(pand_buf);
        }
    }
}
#else
#define SWAP(x, y ,t) ((t)=(x), (x) = (y), (y) = (t))

int top =0;
void print_list(char *list)
{
    int i;
    for(i = 0; i<=6;i++){
        printf("%c",list[i]);
    }
    printf("\n");
}
void perm(char *list, int i, int n)
{
    int j, temp;
    int value;
    if (i == n){
        value = atoi(list);
        if(is_prime(value)){
            if(top < value){
                top = value;
            }
        }
                
    } else {
        for(j=i;j<=n;j++){
            SWAP(list[i], list[j], temp);
            printf("setp1\n");
            print_list(list);
            perm(list, i+1,n);
            SWAP(list[i],list[j], temp);
            printf("setp2\n");
            print_list(list);
        }

    }
}

void main(void)
{
    int n, k, i;
    char buf[9] = "1234567";
    perm(buf, 0, 6);
    printf("top : %d\n",top);
}
#endif
