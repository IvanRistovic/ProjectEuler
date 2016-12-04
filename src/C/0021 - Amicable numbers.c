/*
 Problem 21
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

 Evaluate the sum of all the amicable numbers under 10000.
*/

/* ATTENTION Compile with divisors.c */

#include <stdio.h>
#include "divisors.h"

#define LIMIT 10000

int main() {
	unsigned i, sum = 0, tmp;

	for (i = 1; i < LIMIT; i++) {
		tmp = div_sum(i);
		if (tmp > i && div_sum(tmp) == i)
			sum += i + tmp;
	}

	printf("%u\n", sum);

	return 0;
}

/*
 Solution:
 31626

 real 0m0.007s
 user 0m0.004s
 sys  0m0.000s
*/
