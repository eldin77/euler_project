#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX  4096 
int is_prod(int value)
{
    double n;
    n = (double)((double)sqrt(24*value+1)+1)/6;
    //printf("%f\n",n);
    if( n/1.00 == (int)n ){ 
        return true;
    }
    
    return false;
}

int set_prod(int value)
{
    int result;
    result = (value*((3*value) -1))/2;
    return result;
}

void main(void)
{
    int index = 1;
    int result;
    int buf[MAX] = {0};
    int buf_count = 0; 
    int i;
    int tmp; 
    while(1) {
        result = set_prod(index);
        buf[buf_count] = result;
        
        //printf("result = %d\n",result);
        for(i = buf_count; i > 0; i--){
            tmp = buf[buf_count] - buf[i-1];
            //printf("tmp = %d:%d:%d:%d\n",index,tmp,buf[buf_count],buf[i-1]);
            if(is_prod(tmp)) {
                tmp = buf[buf_count] + buf[i-1];
                if(is_prod(tmp)){
                printf("index = %d: tmp = %d:couont= %d:%d-%d = %d\n",index,tmp,buf_count,buf[buf_count],buf[i-1],buf[buf_count]-buf[i-1]);
                return;
                }
            }
        }
        buf_count++;
        if(index == MAX) break;
        index++;
    }
}
