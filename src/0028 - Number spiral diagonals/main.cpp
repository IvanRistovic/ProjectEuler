/*
	Problem 28

	Starting with the number 1 and moving to the right in a clockwise direction
	a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
	formed in the same way?
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned i = 1, result = 1, step = 2;
	while (i < 1001 * 1001) {
		for (unsigned j = 0; j < 4; j++) {
			i += step;
			result += i;
		}
		step += 2;
	}

	std::cout << result << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	669171001
	Avg time:	0.000312779s
*/
