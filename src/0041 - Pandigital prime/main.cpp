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

	/*
		We know that the number must have 7 or 4 digits, since the sum of
		other digit pandigital numbers is divisible by 3 which means that the
		whole number is divisible by 3 and hence isn't prime
	*/
	std::string num = "7654321";
	do {
		unsigned n = std::stoi(num);
		if (MillerRabinPrimeTest::is_prime(n))
			break;
	} while (std::prev_permutation(num.begin(), num.end()));

	std::cout << num << '\n';

	timer.print_time();
	return 0;
}


/*
	Solution:	7652413
	Avg time:	0.000154526s
*/
