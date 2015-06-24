#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_N 15000 
#define SWAP(x, y ,t) ((t)=(x), (x) = (y), (y) = (t))
int count = 0;
int perm_buf[10];
unsigned char sieve[(MAX_N+7)/8];

inline void set_composite(int value)
{
    sieve[value >> 3] &= ~(1<<(value & 7));
}

inline int is_prime(int value)
{
    return sieve[value >> 3] & (1<<(value & 7));
}

void eratosthenes(int value)
{
    int i,j;
    int sqrt_value = (int)sqrt(value);
    memset(sieve, 0xFF, sizeof(sieve));

    for(i = 2; i<=sqrt_value;i++){
        if(is_prime(i)) {
            for(j = i*i; j<=value; j+=i) {
                set_composite(j);
            }
        }
    }
}


void print_list(char *list)
{
    int i;
    for(i = 0; i<=6;i++){
        printf("%c",list[i]);
    }
    printf("\n");
}

void print_perm(int count)
{
    int i;
    for(i = 0; i<count;i++){
        printf("%d ",perm_buf[i]);
    }
    printf("\n");
}
void perm(char *list, int i, int n, int index)
{
    int j, temp;
    int value;
    int k;
    if (i == n) {
        value = atoi(list);
        if(is_prime(value) && value >= 1000) {
            for(k=0;k<count;k++){
                if(perm_buf[k] == value){
                    return;
                }
            }
            perm_buf[count] = value;
            count++;
        }
    } else {
        for(j=i;j<=n;j++){
            SWAP(list[i], list[j], temp);
            //print_list(list);
            perm(list, i+1,n, index);
            SWAP(list[i],list[j], temp);
            //print_list(list);
        }

    }
}

int search_value(int count, int value)
{
    int i;
    for(i = 0; i < count; i++){
        if(perm_buf[i] == value){
            return true;
        }
    }
    return false;
}

int check_perm(int value, int n,int count)
{
    int a,b,c;
    a = value + n;
    if(!search_value(count ,a)){
       return false; 
    }

    b = a + n; 
    if(!search_value(count ,b)){
       return false; 
    }

    printf("%d:%d:%d%d%d\n",value,n,value,a,b);
    return true;
}

void main(void)
{
    char buf[5];
    int i,j;
    int k; 
    eratosthenes(MAX_N);
    clock_t start_time, end_time;
   
    start_time = clock();
    for(i = 1487; i<=10000; i++){
        sprintf(buf,"%d",i);
        if(is_prime(i)){
            perm(buf, 0, 3, i);
            if(count >= 3 ) {
                for(k = 1;k<=3331;k++){
                    if(check_perm(i, k, count) == true){
                        //print_perm(count);
                    }
                }
            }
        }
        count = 0;
        memset(buf ,0, sizeof(buf));
        memset(perm_buf ,0, sizeof(perm_buf));
    }
    end_time = clock();
    printf("time = %f\n",(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
