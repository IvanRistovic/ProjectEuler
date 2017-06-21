/*
	Problem 3

	The prime factors of 13195 are 5, 7, 13 and 29.

	What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned long long int target = 600851475143;
	unsigned long long int curr_largest_factor = 1;

	for (unsigned long long i = 2; i < target; i++) {
		while (target % i == 0)
			target /= i;

		if (i > curr_largest_factor)
			curr_largest_factor = i;
	}

	std::cout << target << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	6857
	Avg time:	0.000133125s
*/
