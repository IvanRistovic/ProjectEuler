/*
	Problem 41

	We shall say that an n-digit number is pandigital if it makes use of all the
	digits 1 to n exactly once.

	For example, 2143 is a 4-digit pandigital and is also prime.

	What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include <cmath>
#include "../primes.h"
#include "../timer.h"

bool is_square(unsigned n);
bool conjecture(unsigned n, const SieveOfErathostenes &sieve);


int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(10000);

	unsigned i;
	for (i = 9; ; i += 2)
		if (!sieve.is_prime_odd(i) && !conjecture(i, sieve))
			break;

	std::cout << i << '\n';
	timer.print_time();
	return 0;
}


bool is_square(unsigned n)
{
	double t = std::sqrt(n);
	return t == (int)t;
}

bool conjecture(unsigned n, const SieveOfErathostenes &sieve)
{
	for (unsigned i = 2; i < n; i++)
		if (is_square((n - i) / 2) && sieve.is_prime(i))
			return true;

	return false;
}

/*
	Solution:	5777
	Avg time:	0.0217117s
*/
