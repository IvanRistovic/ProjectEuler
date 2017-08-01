/*
	Problem 46

	It was proposed by Christian Goldbach that every odd composite number can
	be written as the sum of a prime and twice a square.

	9 = 7 + 2×1^2
	15 = 7 + 2×2^2
	21 = 3 + 2×3^2
	25 = 7 + 2×3^2
	27 = 19 + 2×2^2
	33 = 31 + 2×1^2

	It turns out that the conjecture was false.

	What is the smallest odd composite that cannot be written as the sum of a
	prime and twice a square?
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
