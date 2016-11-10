/*
 Problem 25:
 The Fibonacci sequence is defined by the recurrence relation:
 
 Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 Hence the first 12 terms will be:
 
 F1 = 1
 F2 = 1
 F3 = 2
 F4 = 3
 F5 = 5
 F6 = 8
 F7 = 13
 F8 = 21
 F9 = 34
 F10 = 55
 F11 = 89
 F12 = 144
 The 12th term, F12, is the first term to contain three digits.
 
 What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <stdio.h>
#include "largenum.h"

#define LIMIT 1000

int main() {
    largenum f1, f2, f3;
    int index = 3;
    
    f1 = f2 = load("1");
    f3 = load("2");
    
    while (f3.len < LIMIT) {
        f1 = f2;
        f2 = f3;
        f3 = add(f1, f2);
        index++;
    }
    
    printf("%d\n", index);
    
    return 0;
}

/*
 Solution:
 4782
 
 real 0m0.063s
 user 0m0.060s
 sys  0m0.000s
*/