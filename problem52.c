/*125874를 2배 하면 251748이 되는데, 이 둘은 같은 숫자로 이루어져 있고 순서만 다릅니다.
 *
 * 2배, 3배, 4배, 5배, 6배의 결과도 같은 숫자로 이루어지는 가장 작은 수는 무엇입니까?
 * 142857 은 곱했을때마다 숫자가 순환하는 숫자.
 * http://ko.wikipedia.org/wiki/142857 참고
 *
 * 또다른 솔루션은 index의 숫자의 조합으로 나올수있는수를 찾고 2,3,4,5,6배 한 숫자가 is_perm인지 판단.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

char buf[MAX] = {0,};

void init_buf(void)
{
    memset(buf, 0 , sizeof(buf));
}

unsigned long long check_buf(unsigned long long value)
{
    unsigned long long tmp = value;
    int index, i ;
    while(1){
        index = tmp%10;
        if(!buf[index]){
            buf[index] = 1;
        } else {
            //printf("double index!! %llu\n",value);
            return false;
        }
        if(tmp/10 == 0)  break;
        tmp = tmp / 10;
    }
        return true;
}

unsigned long long compare_buf(unsigned long long value)
{
    unsigned long long tmp = value;
    int index,i;
    while(1){
        index = tmp%10;
        if(buf[index] == 0){
            return false;
        } 
        if(tmp/10 == 0) break;
        tmp = tmp / 10;
    }
    printf("%llu\n",value);
    return true;
}

void main(void)
{
    unsigned long long index = 125874;
    unsigned long long tmp= 0;  
    int i,count = 0;

    while(1){
        if(check_buf(index)){
            for(i = 2; i<=6; i++){
                tmp = index*i;
                if(compare_buf(tmp)){
                    count++;
                } else {
                    count = 0;
                    break;
                }
            }
            if(count == 5) {
                printf("result = %llu\n",index);
                return;
            }
        }
        index++;
        init_buf();
        count = 0;
    }
}
