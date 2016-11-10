/*
 Problem 23
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. 
 
 By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

/* ATTENTION Compile with divisors.c */

#include <stdio.h>
#include <stdlib.h>
#include "divisors.h"

#define START 12
#define LIMIT 28123
#define ABUNDANT_ARR_SIZE 7000

void error(char *s);
void create_sums(unsigned *array, unsigned n, unsigned *sums);

int main() {
    unsigned i, n = 0;
    unsigned abundant[ABUNDANT_ARR_SIZE], *sums;
    
    /* 
     sums is an array of indicators, if numbers from 1 to LIMIT can be written as sum of 2 abundant numbers. example: sums[54] = 0 => 54 cannot be written as sum of 2 abundant numbers.
     this is why we are using calloc, and not malloc
     
     array will contain all abundant numbers <= LIMIT
    */
    
    sums = calloc(LIMIT + 1, sizeof(unsigned));
    if (sums == NULL)
        error("Initial allocation error");
    
    // finding abundant numbers
    for (i = START; i < LIMIT; i++)
        if (div_sum(i) > i)
            abundant[n++] = i;
    
    // updating indicators
    create_sums(abundant, n, sums);
    
    // counting how many numbers have 0 as indicator
    int sum = 0;
    for (i = 1; i <= LIMIT; i++)
        if (!sums[i])
            sum += i;
    printf("%u\n", sum);
    
    free(sums);
    return 0;
}

void error(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void create_sums(unsigned *abundant, unsigned n, unsigned *sums) {
    unsigned i, j;
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int tmp = abundant[i] + abundant[j];
            if (tmp <= LIMIT)
                sums[tmp] = 1;
            else 
                break;
            // since all above LIMIT are sum of 2 abundant numbers, we can break here because this list goes in ascending order
        }
    }
}

/*
 Solution:
 4179871

 real 0m0.104s
 user 0m0.096s
 sys  0m0.000s
*/