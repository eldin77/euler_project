/*50자리 숫자가 100개 있습니다. 이것을 모두 더한 값의 첫 10자리는 얼마입니까?
 * 13.txt file에 50자리 숫자가 있다.
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8192 
#define DEVIDE 10000000000
/* 50자리수 100개를 더해서 나오는 맨앞자리 10자리수
 * 
 */
void main(void)
{
    int fd;
    char buf[MAX];
    char tmp_buf[11];
    char *token, *ptr;
    unsigned long cut_buf1[5];
    unsigned long cut_buf2[5];
    unsigned long sum_buf[5];
    unsigned long long result; 
    int i,j=0;
    unsigned long value;
    unsigned long sum_value = 0;
    char delim[] = "\n";
    clock_t start_time, end_time;
    
    if((fd = open("13.txt",O_RDONLY)) == -1){
        perror("open error\n");

    }
    memset(buf, 0 ,MAX);
    memset(tmp_buf, 0 ,11);

    read(fd, buf, MAX);
    printf("%s\n",buf);
    start_time = clock();
    token = strtok(buf, "\n");
    for(i = 0; i < 5; i++){
        strncpy(tmp_buf, token+j, 10);
        value = strtoul(tmp_buf, &ptr, 10);
        cut_buf1[i] = value;
        //printf("cut buf 1: %lu\n",cut_buf1[i]);
        j += 10;
    }
    
    while(token = strtok(NULL,"\n")){
        //printf("token = %s\n",token);
        j = 0;
        for(i = 0; i < 5; i++){
            strncpy(tmp_buf, token+j, 10);
            value = strtoul(tmp_buf, &ptr, 10);
            cut_buf2[i] = value;
         //   printf("cut buf 2: %lu\n",cut_buf2[i]);
            j += 10;
        }
        for(i = 4;i >= 0; i--){
            if(i == 0){
                sum_buf[i] = ((cut_buf1[i] + cut_buf2[i]+sum_value));
            } else {
                sum_buf[i] = ((cut_buf1[i] + cut_buf2[i]+sum_value)%DEVIDE);
            }
            sum_value = ((sum_buf[i])/DEVIDE);
        }
        for(i = 4;i >= 0; i--){
            cut_buf1[i] = sum_buf[i];
        }
        sum_buf[0] += sum_value;
        
        //printf("sum = %lu%lu%lu%lu%lu\n",sum_buf[0], sum_buf[1], sum_buf[2], sum_buf[3], sum_buf[4]);
    }
    end_time = clock();
    printf("sum_buf %lu time = %f\n",sum_buf[0],(double)(end_time - start_time)/CLOCKS_PER_SEC);
}
