/*
 Problem 7
 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 
 What is the 10001st prime number?
*/

/* ATTENTION Compile with primes.c -lm */

#include <stdio.h>
#include "primes.h"

#define LIMIT 110000u
#define WANTED 10001

int main() {
    char *prime_array = generate_prime_array(LIMIT);
    
    printf("%u\n", find_prime(prime_array, WANTED));
    
    free(prime_array);
    return 0;
}

/*
 Solution:
 104743
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
