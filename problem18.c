/*
 * Dynamic Programming – The Algorithm
 * We can make a short-cut with the algorithm, as we don’t have to break the problem into sub-problems, but can start from the bottom and work the way up through the triangle until we reach the top and the algorithm spits out a number.
 *
 * We start with a triangle that looks like
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * Applying the algorithm to the small problem we will need three iterations. The first iteration we apply the rule a + max(b,c) which creates a new triangle which looks as
 *
 *    3
 *   7 4
 * 10 13 15
 *
 * Making the second iteration of the algorithm makes the triangle look
 *
 *   3
 * 20 19
 * 18번문제의 알고리즘 위의 설명대로 풀면된다.
 * 문제는 삼각 배열의 값을 넣고
 * 맨 아래쪽 배열부터 차례대로 더해서 상위 배열에 더한값을 써주면 가장 큰값이 결국에 남는다.
 * 근접된 경로에서 찾는것이므로 2^14  16384 개의 경로가 있지만. 경로를 전부 찾아서 더해주면 loop를
 * 16384번 돌게된다.
 *
 * 위의 알고리즘을 이용하여 합이 최대가되는 경로의 합을 구할수있다.
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024 

void main(void)
{

    int fd;
    char buf[MAX]; 
    char *token,*token2, *saveptr2, *saveptr;
    int top_value = 0;
    int first_value = 75;
    int second_value = 75;
    int map[MAX][MAX] = {0};
    int i =1,j=1;
    /*buf init*/
    memset(buf,0,MAX);

    /*file open*/
    if((fd = open("18.txt",O_RDONLY))== -1){
        perror("open error");
    }
    /*buf save*/
    read(fd, buf, MAX);
    /*\n 단위로 token*/
    token = strtok_r(buf, "\n",&saveptr2);
    //printf("%s\n",token);
    /*string를 정수형으로 변환 하여 각 배열에 채우기*/
    map[0][0] = strtoul(token, &saveptr, 10); 
    while(token = strtok_r(NULL, "\n", &saveptr2)){
        //printf("%s\n",token);
        map[i][0] = strtoul(token, &saveptr, 10);
        token2=strtok(token," ");
        //printf("map[%d][0] = %d\n",i,map[i][0]);
        while(token2 = strtok(NULL, " ")){
            map[i][j] = strtoul(token2, &saveptr, 10);
         //   printf("map[%d][%d] = %d\n",i,j,map[i][j]);
            j++;
        }
        j = 1;
        i++;
    }
    //i 세로, j는 가로
    //역으로 돌면서 두개의값중 비교하여 큰값을 상위 배열에 덮어씌워준다.
    j = 0;
    int count = 15;
    for(i = 14; i>=0; i--){
        for(j = 0 ; j < count; j++){
            first_value = map[i-1][j] + map[i][j];
            second_value = map[i-1][j] + map[i][j+1];
            if(first_value > second_value){
                map[i-1][j] = first_value;
            } else{
                map[i-1][j] = second_value;
            }
            printf("%d ",map[i-1][j]);
        }
        printf("\n");
        count--;
    }
}
