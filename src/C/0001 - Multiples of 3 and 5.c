/*
 Problem 1
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

#define LIMIT 1000

int main() {
	unsigned s = 0, i;
    
	for (i = 3; i < LIMIT; i++)
		if (i % 3 == 0 || i % 5 == 0)
		s += i;
        
	printf("%d\n", s);
        
	return 0;
}

/*
 Solution:
 233168
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/