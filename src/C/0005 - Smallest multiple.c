/*
 Problem 5
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main() {
	unsigned step = 2*3*5*7*11*13*17*19, x = 0;
	unsigned i;

	// the only numbers that makes sense to check are multiples of step
	// we loop as long as the biggest number that divides x is below 21
	do {
		x += step;

		// we know that 2 and 3 must divide x, so i starts from 4
		for (i = 4; i <= 20 && x % i == 0; i++)
			;

		// if we managed to divide x with every i, i is now 21
	} while (i != 21);

	printf("%u\n", x);

	return 0;
}

/*
 Solution:
 232792560

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
