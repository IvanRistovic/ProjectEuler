/*
	Problem 7

	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
	that the 6th prime is 13.

	What is the 10001st prime number?
*/

#include <iostream>
#include "../timer.h"
#include "../primes.h"

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes e;
	e.generate_with_limit(110000);

	std::cout << e[10001] << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	104743
	Avg time:	0.009719s
*/
