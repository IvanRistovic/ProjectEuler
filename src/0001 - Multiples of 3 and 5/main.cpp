/*
	Problem 1

	If we list all the natural numbers below 10 that are multiples of 3 or 5,
	we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned sum = 0;
	for (unsigned i = 3; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	233168
	Avg time:	3.6291e-05s
*/
