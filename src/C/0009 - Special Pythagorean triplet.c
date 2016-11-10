/*
 Problem 9
 A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 
 a^2 + b^2 = c^2
 
 For example, 32 + 42 = 9 + 16 = 25 = 52.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 
 Find the product abc. 
*/

#include <stdio.h>

#define LIMIT 500
#define WANTED 1000

int main() {
    unsigned a, b, c;
    
    for (a = 1; a < LIMIT; a++) {
        unsigned asq = a*a;
        for (b = a; b < LIMIT; b++) {
            c = WANTED - a - b;
            if (asq + b*b == c*c) {
                printf("%u\n", a*b*c);
                return 0;
            }
        }
    }
    
    return 1;
}

/*
 Solution:
 31875000
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/