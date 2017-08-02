/*
	Problem 47

	The first two consecutive numbers to have two distinct prime factors are:
	14 = 2 x 7
	15 = 3 x 5

	The first three consecutive numbers to have three distinct prime factors are:
	644 = 2^2 x 7 x 23
	645 = 3 x 5 x 43
	646 = 2 x 17 x 19.

	Find the first four consecutive integers to have four distinct prime factors
	each. What is the first of these numbers?
*/

#include <iostream>
#include "../timer.h"

#define SIEVE_SIZE (500000)

int main()
{
	ProgramTimer timer;

	unsigned sieve[SIEVE_SIZE] = { 0 };

	// Generate sieve with number of factors
	for (unsigned i = 2; i < SIEVE_SIZE; i++) {
		if (sieve[i] > 0)
			continue;
		for (unsigned j = i; j < SIEVE_SIZE; j += i)
			sieve[j]++;
	}

	// Search 4 consecutive
	unsigned i = 2*3*5*7;
	while (i < SIEVE_SIZE)
		if (sieve[i++] == 4 && sieve[i++] == 4 &&sieve[i++] == 4 && sieve[i++] == 4)
			break;

	std::cout << i - 4 << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	134043
	Avg time:	0.0386374s
*/
