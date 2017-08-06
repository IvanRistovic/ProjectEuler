/*
	Problem 49

	The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases
	by 3330, is unusual in two ways:
	(i) each of the three terms are prime, and,
	(ii) each of the 4-digit numbers are permutations of one another.

	There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
	exhibiting this property, but there is one other 4-digit increasing sequence.

	What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <iostream>
#include <vector>
#include "../primes.h"
#include "../combinatorics.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(10000);

	// From this position, next_prime will return first 4-digit prime
	sieve.setpos(167);

	std::vector<unsigned> primes;

	for (unsigned i = sieve.next_prime<unsigned>(); i < 10000; i = sieve.next_prime<unsigned>())
		primes.push_back(i);

	for (unsigned i = 0; i < primes.size(); i++) {
		if (primes[i] == 1487)
			continue;
		for (unsigned j = i + 1; j < primes.size(); j++) {
			unsigned t = primes[j] + (primes[j] - primes[i]);
			if (t < 10000 && pe_primes::is_prime(t))
				if (
					pe_comb::is_perm(primes[i], primes[j]) &&
					pe_comb::is_perm(primes[i], t)) {
					std::cout << primes[i] << primes[j] << t << '\n';
					timer.print_time();
					return 0;
				}
		}
	}

	return 0;
}

/*
	Solution:	296962999629
	Avg time:	0.0418726s
*/
