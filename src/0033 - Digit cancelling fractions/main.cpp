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
#include "../divisors.h"
#include "../timer.h"

bool is_curious(unsigned n, unsigned d);


int main()
{
	ProgramTimer timer;

	unsigned solution_n = 1, solution_d = 1;
	for (unsigned n = 10; n < 100; n++) {
		for (unsigned d = n + 1; d < 100; d++) {
			if (n % 10 && d % 10 && is_curious(n, d)) {
				solution_n *= n;
				solution_d *= d;
			}
		}
	}

	std::cout << solution_d / pe_div::gcd(solution_n, solution_d) << '\n';

	timer.print_time();
	return 0;
}


bool is_curious(unsigned n, unsigned d)
{
	unsigned n0 = n % 10;
	unsigned n1 = n / 10;
	unsigned d0 = d % 10;
	unsigned d1 = d / 10;

	double res = (double)n / d;

	if (n0 == d0) {
		if ((double)n1 / d1 == res)
			return true;
		else
			return false;
	} else if (n0 == d1) {
		if ((double)n1 / d0 == res)
			return true;
		else
			return false;
	} else if (n1 == d0) {
		if ((double)n0 / d1 == res)
			return true;
		else
			return false;
	} else if (n1 == d1) {
		if ((double)n0 / d0 == res)
			return true;
		else
			return false;
	} else
		return false;
}

/*
	Solution:	100
	Avg time:	0.000297238s
*/
