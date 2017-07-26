/*
	Problem 35

	The number, 197, is called a circular prime because all rotations of the digits:
	197, 971, and 719, are themselves prime.

	There are thirteen such primes below 100:
	2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

	How many circular primes are there below one million?
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

unsigned pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

unsigned shift(unsigned n, unsigned size);
bool is_circular_prime(unsigned n, const SieveOfErathostenes &sieve);


int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(1000000);

	// There are 24 primes below 100
	sieve.setpos(24);

	// We know there are 13 circular primes below 100
	unsigned count = 13;

	unsigned i = sieve.next_prime<unsigned>();
	while (i < 1000000) {
		if (is_circular_prime(i, sieve))
			count++;
		i = sieve.next_prime<unsigned>();
	};

	std::cout << count << '\n';

	timer.print_time();
	return 0;
}


unsigned shift(unsigned n, unsigned size)
{
	return (n % 10) * pow10[size - 1] + (n / 10);
}

bool is_circular_prime(unsigned number, const SieveOfErathostenes &sieve)
{
	unsigned n = number;
	unsigned size = 0;
	while (n) {
		n /= 10;
		size++;
	}

	for (n = shift(number, size); n != number; n = shift(n, size))
		if (n % 2 == 0 || sieve.is_prime_odd(n) == false)
			return false;

	return true;
}

/*
	Solution:	55
	Avg time:	0.157703s
*/
