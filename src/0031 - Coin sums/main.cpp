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

int main()
{
	ProgramTimer timer;

	unsigned ways = 0;
	for (int p200 = 200; p200 >= 0; p200 -= 200)
		for (int p100 = p200; p100 >= 0; p100 -= 100)
			for (int p50 = p100; p50 >= 0; p50 -= 50)
				for (int p20 = p50; p20 >= 0; p20 -= 20)
					for (int p10 = p20; p10 >= 0; p10 -= 10)
						for (int p5 = p10; p5 >= 0; p5 -= 5)
							for (int p2 = p5; p2 >= 0; p2 -= 2)
								ways++;

	std::cout << ways << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	76382
	Avg time:	0.000890146s
*/
