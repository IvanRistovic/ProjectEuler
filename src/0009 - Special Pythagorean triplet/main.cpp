/*
	Problem 9

	A Pythagorean triplet is a set of three natural numbers, a < b < c,
	for which a^2 + b^2 = c^2

	For example, 32 + 42 = 9 + 16 = 25 = 52.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	for (unsigned a = 1; a < 500; a++) {
		unsigned asq = a*a;
		for (unsigned b = a; b < 500; b++) {
			unsigned c = 1000 - a - b;
			if (asq + b*b == c*c) {
				std::cout << a*b*c << '\n';
				timer.print_time();
				return 0;
			}
		}
	}

	return 0;
}

/*
	Solution:	31875000
	Avg time:	0.000253417s
*/
