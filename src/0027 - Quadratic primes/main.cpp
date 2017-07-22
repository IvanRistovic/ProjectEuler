/*
	Problem 27

	Euler discovered the remarkable quadratic formula:
	n^2 + n + 41

	It turns out that the formula will produce 40 primes for the consecutive
	integer values 0 <= n <= 39.
	However, when n = 40, 40^2 + 40 + 41 = 40(40+1) + 41 is divisible by 41,
	and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

	The incredible formula n^2 − 79n + 1601 was discovered, which produces 80
	primes for the consecutive values 0 <= n <= 79. The product of the coefficients,
	−79 and 1601, is −126479.

	Considering quadratics of the form:
	n^2 + an + b, where |a| < 1000 and |b| <= 1000
	where |n| is the modulus/absolute value of n
	e.g. |11| = 11 and |−4| = 4

	Find the product of the coefficients, a and b, for the quadratic expression
	that produces the maximum number of primes for consecutive values of n,
	starting with n = 0.
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes primes;
	primes.generate_with_limit(100000);

	int maxpr = 0, maxchain = 0;

	// For n = 0, the formula equals b. Therefore, b has to be a prime
	for (int b = 3; b <= 1000; b += 2) {
		if (!primes.is_prime_odd(std::abs(b)))
			continue;

		// If b is prime, then check all possible variants for a
		// Also, for n = 1, the formula equals a + b + 1, therefore a has to be odd.
		int chain = 1;
		for (int a = -999; a <= 999; a += 2) {
			int n = 1;
			while (primes.is_prime(std::abs(n*n + a*n + b)))
				n++;

			if (n > maxchain) {
				maxchain = n;
				maxpr = a*b;
			}
		}
	}

	std::cout << maxpr << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	-59231
	Avg time:	0.0386337s
*/
