/*
	Problem 21

	Let d(n) be defined as the sum of proper divisors of n (numbers less than n
	which divide evenly into n).
	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and
	each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
	55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
	71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include "../divisors.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned sum = 0;
	for (unsigned i = 1; i < 10000; i++) {
		unsigned tmp = pe_div::div_sum(i);
		if (tmp > i && pe_div::div_sum(tmp) == i)
			sum += i + tmp;
	}

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	31626
	Avg time:	0.0207572s
*/
