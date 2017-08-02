/*
	Problem 44

	Pentagonal numbers are generated by the formula, Pn = n(3n−1)/2.
	The first ten pentagonal numbers are:

	1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

	It can be seen that P4 + P7 = 22 + 70 = 92 = P8.
	However, their difference, 70 - 22 = 48, is not pentagonal.

	Find the pair of pentagonal numbers, Pj and Pk, for which their sum and
	difference are pentagonal and D = |Pk - Pj| is minimised; what is the value
	of D?
*/

#include <iostream>
#include <cmath>
#include "../timer.h"

bool is_pentagonal(unsigned number);


int main()
{
	ProgramTimer timer;

	unsigned D = 0;
	unsigned i = 1;
	while (true) {
		i++;
		unsigned n = i * (3 * i - 1) / 2;

		for (unsigned j = i - 1; j > 0; j--) {
			unsigned m = j * (3 * j - 1) / 2;
			if (is_pentagonal(n - m) && is_pentagonal(n + m)) {
				D = n - m;
				std::cout << D << '\n';
				timer.print_time();
				return 0;
			}
		}
	}

	return 0;
}


bool is_pentagonal(unsigned number)
{
	double t = (std::sqrt(1 + 24 * number) + 1.0) / 6.0;
	return t == ((int)t);
}

/*
	Solution:	5482660
	Avg time:	0.0636477s
*/