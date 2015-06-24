#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000000
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
    int sqrt_value;
    sqrt_value = (int)sqrt(value);
    memset(sieve, 0xFF, sizeof(sieve));

    for(i = 2; i<=sqrt_value; i++){
        if(is_prime(i)) {
            for(j=i*i; j<=value; j+=i){
                set_composite(j);
            }
        }
    }
}


int main() 
{
    int baseloop, basenumber;
    eratosthenes(MAX_N);
    int matrix[10] = {1110, 10110, 11010, 11100, 100110, 101010, 101100, 110010, 110100, 111000 };

    for (baseloop = 0; baseloop < 10; baseloop++) {
        for (basenumber = 100000; basenumber < 200000; basenumber++) {
            int testnumber = basenumber;

            int strike = 0;
            int candidate = 0;
            while (strike <= 2) {
                if (!is_prime(testnumber)) {
                    strike++;
                }
                if (is_prime(testnumber)) {
                    candidate++;
                }
                if (candidate >= 8){
                    printf("Found: %d %d\n", basenumber ,baseloop);
                }
                testnumber += matrix[baseloop];
            }
        }
    }

}

