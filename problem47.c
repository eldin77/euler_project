#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5 
void print_buf(int * buf,int count, unsigned long tmp)
{
    int i;
    printf("%lu : ",tmp);
    for(i = 0; i<count; i++){
        printf("%d ",buf[i]);
    }
    printf("\n");
}

int search_buf(int * buf, int count)
{
    int i,j;
    for(i=0;i<count;i++){
        for(j=i+1;j<count;j++){
            if(buf[i] == buf[j]){
                buf[i] = buf[i]*buf[j];
                buf[j] = 0;
                count--;
            }
        }
    }
    return count;
}
void main(void)
{
    clock_t start_time, end_time;
    unsigned long index;
    unsigned long min;
    unsigned long tmp;
    int count = 0;
    int *value_buf;
    int line = 0;
    int line_value = 0;
    int glo_count = 1; 
    int tmp_value = 0;
    value_buf = malloc(sizeof(int)*MAX);

    start_time = clock();
    for(tmp = 120000; tmp < 140000; tmp++){
        memset(value_buf, 0 ,sizeof(int)*MAX);
        index = tmp;
        for(min = 2;min < tmp; min++){
            if(index % min ==0){
                index = index / min;
                //printf("%lu %lu\n",min, index);
                //printf("%lu ",min);
                value_buf[count] = min;
                count++;
            }
        }
        if(index != 1){
            value_buf[count] = index;
            count++;
        }
        count = search_buf(value_buf, count);
        
        if(count == 4) {
            line_value += 1;
            tmp_value = tmp;
           
            if(tmp_value == line_value) {
                glo_count++;
                if(glo_count == 4){
                printf("glo:%d ",glo_count);
                print_buf(value_buf, count, tmp);
                printf("\n");
                }
            } else {
                glo_count = 1;
                line_value = tmp_value; 
            }
        }
        
        count = 0;
    }
    end_time = clock();
    printf("index:%lu time:%f\n",index,(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
