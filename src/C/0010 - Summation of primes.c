/*
 Problem 10
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 
 Find the sum of all the primes below two million.
*/

/* ATTENTION Compile with primes.c -lm */

#include <stdio.h>
#include "primes.h"

#define LIMIT 2000000u

int main() {
    unsigned long sum = 2;
    char *prime_array = generate_prime_array(LIMIT);
    
    unsigned i;
    for (i = 1; i < PRIME_ARR_SIZE; i++)
        if (prime_array[i])
            sum += (i << 1) + 1;
    
    printf("%lu\n", sum);
    
    free(prime_array);
    return 0;
}

/*
 Solution:
 142913828922
 
 real 0m0.033s
 user 0m0.024s
 sys  0m0.000s
*/