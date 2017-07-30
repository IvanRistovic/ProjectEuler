/*
	Problem 31

	In England the currency is made up of pound, £, and pence, p, and there are
	eight coins in general circulation:

	1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
	It is possible to make £2 in the following way:

	1x£1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
	How many different ways can £2 be made using any number of coins?
*/

#include <iostream>
#include "../timer.h"

#define SUM (200)

int main()
{
	ProgramTimer timer;

	unsigned coins[] = { 1, 2 , 5 , 10 , 20 , 50 , 100 , 200 };
	unsigned ways[SUM + 1] = { 0 };
	ways[0] = 1;
	
	for (unsigned i = 0; i < 8; i++)
		for (unsigned j = coins[i]; j <= SUM; j++)
			ways[j] += ways[j - coins[i]];

	std::cout << ways[SUM] << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	73682
	Avg time:	0.000114286s
*/
