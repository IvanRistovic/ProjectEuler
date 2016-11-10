/*
 Problem 3
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

int main() {
    unsigned long long int i, x = 600851475143;
    unsigned long long int lpf = 1;
    
    for (i = 2; i < x; i++) {
        while (x % i == 0) {
            x /= i;
            if (i > lpf)
                lpf = i;
        }
    }
    printf("%llu\n", x);
    
    return 0;
}

/*
 Solution:
 6857
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/