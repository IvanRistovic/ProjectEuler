/*
	Problem 6

	The sum of the squares of the first ten natural numbers is:
	1^2 + 2^2 + ... + 10^2 = 385

	The square of the sum of the first ten natural numbers is:
	(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten natural
	numbers and the square of the sum is 3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first one hundred
	natural numbers and the square of the sum.
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	// 1^2 + 2^2 + ... + n^2 = n(n+1)(2n+1)/6
	unsigned sumsq = 100 * 101 * 201 / 6;

	// 1 + 2 + ... + 100 = 101 * 50 (Gaussian rule)
	unsigned sum = 101 * 50;

	std::cout << sum * sum - sumsq << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	25164150
	Avg time:	5.965e-05s
*/
