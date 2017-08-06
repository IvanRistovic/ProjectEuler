/*
	Problem 52

	It can be seen that the number, 125874, and its double, 251748, contain
	exactly the same digits, but in a different order.

	Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
	contain the same digits.
*/

#include <iostream>
#include "../combinatorics.h"
#include "../timer.h"

bool is_6_times_perm(unsigned x);


int main()
{
	ProgramTimer timer;

	unsigned i = 10;
	while (!is_6_times_perm(i))
		i++;

	std::cout << i << '\n';

	timer.print_time();
	return 0;
}


bool is_6_times_perm(unsigned x)
{
	/*
		Numbers with first digit 2 or higher can't be the solutions because
		when they are multiplied by 6, the result will always have more digits
		than the starting number, so it cannot be permutation of it.
	*/
	unsigned digit;
	for (unsigned n = x; n != 0; n /= 10)
		digit = n % 10;
	if (digit > 1)
		return false;

	for (unsigned i = 2; i <= 6; i++)
		if (!pe_comb::is_perm(i*x, x))
			return false;

	return true;
}

/*
	Solution:	142857
	Avg time:	0.0220208s
*/
