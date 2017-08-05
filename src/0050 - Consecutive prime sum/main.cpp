/*
	Problem 50

	The prime 41, can be written as the sum of six consecutive primes:
	41 = 2 + 3 + 5 + 7 + 11 + 13

	This is the longest sum of consecutive primes that adds to a prime below
	one-hundred.

	The longest sum of consecutive primes below one-thousand that adds to a prime,
	contains 21 terms, and is equal to 953.

	Which prime, below one-million, can be written as the sum of the most
	consecutive primes?
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

#define LIMIT (1000000)

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(LIMIT);

	std::vector<unsigned> primes;
	sieve.create_prime_vector(primes);

	unsigned max_sum = 0, max_count = 0;
	for (unsigned i = 0; i < primes.size(); i++) {
		unsigned curr_sum = primes[i];
		unsigned count = 1;
		for (unsigned j = i + 1; j < primes.size(); j++) {
			curr_sum += primes[j];
			count++;
			if (curr_sum > LIMIT)
				break;
			if (count > max_count && sieve.is_prime(curr_sum)) {
				max_sum = curr_sum;
				max_count = count;
			}
		}
	}

	std::cout << max_sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	997651
	Avg time:	0.154144s
*/
