/*
	Problem 5

	2520 is the smallest number that can be divided by each of the numbers
	from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of
	the numbers from 1 to 20?
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned step = 2*3*5*7*11*13*17*19, number = step;

	// Explanation:
	// The only numbers that can possibly satisfy the given condition are
	// the multiples of 'step' (since primes below 20 must divide it without
	// a remainder). Therefore we simply loop as long as the largest divisor
	// of 'number' is below 21.

	while (true) {
		unsigned d;

		// We know that 2 and 3 must divide x, so divisors starts from 4.
		for (d = 4; d <= 20 && number % d == 0; d++)
			;

		// If we managed to divide the number with every d <= 20, d is 21.
		if (d == 21)
			break;

		// If not, then we will try again with another increment of number
		number += step;
	}

	std::cout << number << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	232792560
	Avg time:	4.6836e-05s
*/
