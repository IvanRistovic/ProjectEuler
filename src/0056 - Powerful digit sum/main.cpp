/*
	Problem 56

	A googol (10^100) is a massive number: one followed by one-hundred zeros;
	100^100 is almost unimaginably large: one followed by two-hundred zeros.
	Despite their size, the sum of the digits in each number is only 1.

	Considering natural numbers of the form, ab, where a, b < 100, what is the
	maximum digital sum?
*/

#include <iostream>
#include <gmp.h>
#include "../timer.h"

unsigned digit_sum(mpz_t n);


int main()
{
	ProgramTimer timer;

	unsigned max = 0;
	for (unsigned a = 2; a < 100; a++) {
		for (unsigned b = 2; b < 100; b++) {
			mpz_t n;
			mpz_init(n);
			mpz_ui_pow_ui(n, a, b);
			unsigned digsum = digit_sum(n);
			if (digsum > max)
				max = digsum;
		}
	}

	std::cout << max << '\n';

	timer.print_time();
	return 0;
}

unsigned digit_sum(mpz_t n)
{
	unsigned sum = 0;

	char buf[256];
	gmp_sprintf(buf, "%Zd", n);
	for (unsigned i = 0; buf[i]; i++)
		sum += buf[i] - '0';

	return sum;
}


/*
	Solution:	972
	Avg time:	0.0313342s
*/
