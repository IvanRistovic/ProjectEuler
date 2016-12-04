/*
 Problem 20
 n! means n × (n − 1) × ... × 3 × 2 × 1

 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

 Find the sum of the digits in the number 100!
*/

/* ATTENTION Compile with largenum.c */

#include <stdio.h>
#include <stdlib.h>
#include "largenum.h"

#define LIMIT 100

int main() {
	largenum x, product, one;
	int i;

	one = x = product = load("1");		  // x = p = 1;

	for (i = 0; i < LIMIT; i++) {
		product = mul(x, product);		  // p *= x;
		x = add(x, one);					// x++;
	}

	printf("%d\n", digit_sum(product));

	return 0;
}

/*
 Solution:
 648

 real 0m0.024s
 user 0m0.022s
 sys  0m0.000s
*/
