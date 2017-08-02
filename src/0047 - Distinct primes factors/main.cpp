/*
	Problem 47

	The first two consecutive numbers to have two distinct prime factors are:
	14 = 2 x 7
	15 = 3 x 5

	The first three consecutive numbers to have three distinct prime factors are:
	644 = 2^2 x 7 x 23
	645 = 3 x 5 x 43
	646 = 2 x 17 x 19.

	Find the first four consecutive integers to have four distinct prime factors
	each. What is the first of these numbers?
*/

#include <iostream>
#include "../timer.h"

int prime_factor_num(unsigned n);


int main()
{
	ProgramTimer timer;

	unsigned i = 2*3*5*7, streak = 0;
	while (streak < 4) {
		if (prime_factor_num(i) == 4)
			streak++;
		else
			streak = 0;
		i++;
	}

	std::cout << i - streak << '\n';

	timer.print_time();
	return 0;
}


int prime_factor_num(unsigned n)
{
	int count = 0;

	for (unsigned i = 2; i <= n; i++) {
		unsigned old_n = n;

		while (n % i == 0)
			n /= i;

		if (n < old_n)
			count++;
	}

	return count;
}

/*
	Solution:	5777
	Avg time:	0.0217117s
*/
