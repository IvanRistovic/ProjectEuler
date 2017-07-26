/*
	Problem 37

	The number 3797 has an interesting property. Being prime itself, it is
	possible to continuously remove digits from left to right, and remain prime
	at each stage: 3797, 797, 97, and 7.
	Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left
	to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

bool is_circular_prime(unsigned n, const SieveOfErathostenes &sieve);


int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(1000000);
	sieve.setpos(3);

	unsigned count = 0, sum = 0;
	while (count < 11) {
		unsigned i = sieve.next_prime<unsigned>();
		if (is_circular_prime(i, sieve)) {
			sum += i;
			count++;
		}
	}

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


bool is_circular_prime(unsigned n, const SieveOfErathostenes &sieve)
{
	for (unsigned num = n; num != 0; num /= 10)
		if (sieve.is_prime(num) == false)
			return false;

	for (unsigned prod = 10; n % prod != n; prod *= 10)
		if (sieve.is_prime(n % prod) == false)
			return false;

	return true;
}

/*
	Solution:	748317
	Avg time:	0.138456s
*/
