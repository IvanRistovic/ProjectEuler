/*
	Problem 48

	The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

	Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <iostream>
#include <gmpxx.h>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	mpz_t sum;
	mpz_init(sum);

	for (unsigned i = 1; i <= 1000; i++) {
		mpz_t add;
		mpz_init(add);
		mpz_ui_pow_ui(add, i, i);
		mpz_add(sum, sum, add);
	}

	mpz_mod_ui(sum, sum, 10000000000);
	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	9110846700
	Avg time:	0.00588684s
*/
