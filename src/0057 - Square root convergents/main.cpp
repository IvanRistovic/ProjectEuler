/*
	Problem 57

	It is possible to show that the square root of two can be expressed as an
	infinite continued fraction.

	sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

	By expanding this for the first four iterations, we get:

	1 + 1/2 = 3/2 = 1.5
	1 + 1/(2 + 1/2) = 7/5 = 1.4
	1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
	1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

	The next three expansions are 99/70, 239/169, and 577/408, but the eighth
	expansion, 1393/985, is the first example where the number of digits in the
	numerator exceeds the number of digits in the denominator.

	In the first one-thousand expansions, how many fractions contain a numerator
	with more digits than denominator?
*/

/*
	It is easy to notice that in each iteration the denominator is the sum of
	previous nominator and denominator, and the nominator is the sum of previous
	nominator and two times denominator.
*/

#include <iostream>
#include <string>
#include <gmpxx.h>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	mpz_class n = 3, d = 2, count = 0;
	for (int i = 0; i < 1000; i++) {
		mpz_class new_d = n + d;
		mpz_class new_n = new_d + d;
		if (new_n.get_str().size() > new_d.get_str().size()) {
			count++;
		}
		n = new_n;
		d = new_d;
	}

	std::cout << count << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	153
	Avg time:	0.00821606s
*/
