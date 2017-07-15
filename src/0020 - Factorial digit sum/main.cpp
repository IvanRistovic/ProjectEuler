/*
	Problem 20

	n! means n × (n − 1) × ... × 3 × 2 × 1

	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

	Find the sum of the digits in the number 100!
*/

#include <iostream>
#include <gmpxx.h>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	mpz_class fact(1);
	for (unsigned i = 2; i <= 100; i++)
		fact *= i;

	mpz_class digit_sum(0);
	while (fact) {
		digit_sum += fact % 10;
		fact /= 10;
	}

	std::cout << digit_sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	648
	Avg time:	0.000514448s
*/
