/*
	Problem 16

	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	char num[512];
	double p = std::pow(2.0, 1000);
	std::sprintf(num, "%.0lf", p);

	int sum = 0;
	for (int i = 0; num[i] != '\0'; i++)
		sum += num[i] - '0';

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
 Solution:
 1366

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
