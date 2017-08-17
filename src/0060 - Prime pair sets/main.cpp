/*
	Problem 60

	The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes
	and concatenating them in any order the result will always be prime.
	For example, taking 7 and 109, both 7109 and 1097 are prime.
	The sum of these four primes, 792, represents the lowest sum for a set of
	four primes with this property.

	Find the lowest sum for a set of five primes for which any two primes
	concatenate to produce another prime.
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

bool concat_prime(unsigned n1, unsigned n2);


int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(10000);

	unsigned sum = ~0u;
	for (unsigned i = 3; i < 10000; i += 2) {
		if (!sieve.is_prime_odd(i))
			continue;
		for (unsigned j = i; j < 10000; j += 2) {
			if (!sieve.is_prime_odd(j))
				continue;
			if (!concat_prime(j, i))
				continue;
			for (unsigned k = j; k < 10000; k += 2) {
				if (!sieve.is_prime_odd(k))
					continue;
				if (
					!concat_prime(k, i) ||
					!concat_prime(k, j)
				)	continue;
				for (unsigned l = k; l < 10000; l += 2) {
					if (!sieve.is_prime_odd(l))
						continue;
					if (
						!concat_prime(l, i) ||
						!concat_prime(l, j) ||
						!concat_prime(l, k)
					)	continue;
					for (unsigned t = l; t < 10000; t += 2) {
						if (!sieve.is_prime_odd(t))
							continue;
						if (
							!concat_prime(t, i) ||
							!concat_prime(t, j) ||
							!concat_prime(t, k) ||
							!concat_prime(t, l)
						)	continue;
						std::cout << i + j + k + l + t << '\n';
						timer.print_time();
						return 0;
					}
				}
			}
		}
	}

	timer.print_time();
	return 0;
}


bool concat_prime(unsigned n1, unsigned n2)
{
	unsigned p = 1;
	if (n1 < 10)
		p = 10;
	else if (n1 < 100)
		p = 100;
	else if (n1 < 1000)
		p = 1000;
	else
		p = 10000;
	if (!pe_primes::is_prime(n2 * p + n1))
		return false;
	if (n2 < 10)
		p = 10;
	else if (n2 < 100)
		p = 100;
	else if (n2 < 1000)
		p = 1000;
	else
		p = 10000;
	if (!pe_primes::is_prime(n1 * p + n2))
		return false;
	return true;
}

/*
	Solution:	26033
	Avg time:
*/
