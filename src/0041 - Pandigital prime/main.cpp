/*
	Problem 41

	We shall say that an n-digit number is pandigital if it makes use of all the
	digits 1 to n exactly once.

	For example, 2143 is a 4-digit pandigital and is also prime.

	What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "../primes.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes sieve;
	sieve.generate_with_limit(8000000);

	/*
		We know that the number must have 7 digits, since the sum of
		8 and 9 digit pandigital numbers is divisible by 3, so every
		possible pandigital number with 8 or 9 digits is also divisible
		by 3 (hence isn't prime)
	*/
	std::string num = "7654321";
	do {
		unsigned n = std::stoi(num);
		if (sieve.is_prime(n))
			break;
	} while (std::prev_permutation(num.begin(), num.end()));

	std::cout << num << '\n';

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
	Solution:	7652413
	Avg time:	0.664959s
*/
