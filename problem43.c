#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX 8

int map[MAX] = { 17, 13, 11, 7, 5, 3, 2};
unsigned long result = 0;

void print_list(char *list)
{
    int i;
    for(i = 0; i<=9;i++){
        printf("%c",list[i]);
    }
    printf("\n");
}

int check_prime(unsigned long value)
{
    unsigned long i, tmp, div_value;
    tmp = value;
    for(i = 0; i < MAX-1; i++){
        div_value = tmp%1000;
        if(div_value%map[i] != 0){
            return false;
        }
        if(tmp / 10 == 0) break;
        tmp = tmp/10;
    }
    return true;
}

void perm(char *list, int i, int n)
{
    int j, temp;
    unsigned long value;
    if(i == n){
        value = atoll(list);
        if(check_prime(value)) {
            printf("value = %lu\n",value);
            result += value;
        }
    } else {
        for(j=i;j<=n;j++){
            SWAP(list[i], list[j], temp);
            //print_list(list);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
            //print_list(list);
        }
    }
}

void main(void)
{
    int n, k , i;
    char buf[11] = "1234567890";
    clock_t start_time, end_time;
    start_time = clock();
    perm(buf, 0, 9);
    end_time = clock();
    printf("result = %lu time = %f\n",result,(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
