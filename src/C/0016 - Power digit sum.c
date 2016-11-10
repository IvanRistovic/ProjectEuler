/*
 Problem 16
 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
 What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 500

double pow_(double base, unsigned exp);

int main() {
    double p;
    char num[MAX_LEN];
    int sum = 0, i = 0;
    
    p = pow_(2.0, 1000);
    sprintf(num, "%.0lf", p);
    
    while (num[i]) {
        sum += num[i] - '0';
        i++;
    }
    
    printf("%d\n", sum);
    return 0;
}

double pow_(double base, unsigned exp) {
    double result = 1;
    
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    
    return result;
}

/*
 Solution:
 1366
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/