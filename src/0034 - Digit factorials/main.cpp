/*
	Problem 33

	The fraction 49/98 is a curious fraction, as an inexperienced mathematician
	in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
	is correct, is obtained by cancelling the 9s.

	We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

	There are exactly four non-trivial examples of this type of fraction, less
	than one in value, and containing two digits in the numerator and denominator.

	If the product of these four fractions is given in its lowest common terms,
	find the value of the denominator.
*/

#include <iostream>
#include "../timer.h"

#define LIMIT (7 * 362880)

unsigned fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

unsigned digit_fact_sum(unsigned n);


int main()
{
	ProgramTimer timer;

	unsigned sum = 0;
	for (unsigned i = 3; i < LIMIT; i++)
		if (i == digit_fact_sum(i))
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


unsigned digit_fact_sum(unsigned n)
{
	unsigned sum = 0;
	for (; n != 0; n /= 10)
		sum += fact[n % 10];
	return sum;
}

/*
	Solution:	40730
	Avg time:	0.000297238s
*/
