/*
	Problem 40

	An irrational decimal fraction is created by concatenating the positive integers:
	0.123456789101112131415161718192021...

	It can be seen that the 12th digit of the fractional part is 1.

	If dn represents the nth digit of the fractional part, find the value of the
	following expression:
	d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <string>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	std::string constant = "";

	for (int i = 1; constant.length() < 1000000; i++)
		constant += std::to_string(i);

	std::cout
		<< (constant[0] - '0')
			* (constant[9] - '0')
			* (constant[99] - '0')
			* (constant[999] - '0')
			* (constant[9999] - '0')
			* (constant[99999] - '0')
			* (constant[999999] - '0')
		<< '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	840
	Avg time:	0.403111s
*/
