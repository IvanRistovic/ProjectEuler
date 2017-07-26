/*
	Problem 34

	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

	Find the sum of all numbers which are equal to the sum of the factorial of
	their digits.

	Note: as 1! = 1 and 2! = 2 are not sums they are not included.
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
