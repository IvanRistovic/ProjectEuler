/*
	Problem 39

	If p is the perimeter of a right angle triangle with integral length sides,
	{a,b,c}, there are exactly three solutions for p = 120:

	{20,48,52}, {24,45,51}, {30,40,50}

	For which value of p <= 1000, is the number of solutions maximised?
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned maxsol = 0, maxp = 0;
	for (unsigned p = 5; p <= 1000; p++) {
		unsigned sol = 0;
		for (unsigned a = 1; a < p; a++) {
			for (unsigned b = a; b < p - a; b++) {
				unsigned c = p - a - b;
				if (c*c == a*a + b*b)
					sol++;
			}
		}
		if (sol > maxsol) {
			maxsol = sol;
			maxp = p;
		}
	}

	std::cout << maxp << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	840
	Avg time:	0.403111s
*/
