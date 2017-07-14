/*
	Problem 15

	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

	How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include "../combinatorics.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	std::cout << choose<unsigned long>(40, 20) << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	137846528820
	Avg time:	0.000108997s
*/
