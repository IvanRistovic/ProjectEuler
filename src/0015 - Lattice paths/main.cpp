/*
 Problem 15
 Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

 How many such routes are there through a 20×20 grid?
*/

#include <iostream>
#include "../timer.h"

unsigned long latticecomb(void);
unsigned long lattice(void);


int main()
{
	ProgramTimer timer;

	// std::cout << lattice() << '\n';
	std::cout << latticecomb() << '\n';

	timer.print_time();
	return 0;
}


unsigned long latticecomb(void)
{
	unsigned long k = 1;

	for (unsigned long i = 0; i < 20; i++) {
		k = k * ((2 * 20) - i);
		k = k / (i + 1);
	}

	return k;
}

unsigned long lattice(void)
{
	unsigned long int matrix[20+1][20+1];

	for (unsigned long i = 0; i <= 20; i++) {
		matrix[20][i] = 1;
		matrix[i][20] = 1;
	}

	for (unsigned long i = 19; i >= 0; i--)
		for (unsigned long j = 19; j >= 0; j--)
			matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];

	return matrix[0][0];
}

/*
	Solution:	137846528820
	Avg time:	0.000108997s
*/
