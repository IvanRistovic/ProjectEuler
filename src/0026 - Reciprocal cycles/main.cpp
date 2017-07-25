/*
	Problem 26

	A unit fraction contains 1 in the numerator. The decimal representation of
	the unit fractions with denominators 2 to 10 are given:

	1/2 = 0.5
	1/3 = 0.(3)
	1/4 = 0.25
	1/5 = 0.2
	1/6 = 0.1(6)
	1/7 = 0.(142857)
	1/8 = 0.125
	1/9 = 0.(1)
	1/10 = 0.1

	Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
	It can be seen that 1/7 has a 6-digit recurring cycle.

	Find the value of d < 1000 for which 1/d contains the longest recurring cycle
	in its decimal fraction part.
*/

#include <iostream>
#include <vector>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned maxchain = 0, d;
	for (unsigned i = 1000; maxchain < i; i--) {
		unsigned rem = 1, chain = 1;
		std::vector<int> ind(i, 0);

		while (ind[rem] == 0 && rem != 0) {
			ind[rem] = true;
			rem *= 10;
			rem %= i;
			chain++;
		}

		if (chain - ind[rem] > maxchain) {
			maxchain = chain - ind[rem];
			d = i;
		}
	}

	std::cout << d << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	-59231
	Avg time:	0.0386337s
*/
