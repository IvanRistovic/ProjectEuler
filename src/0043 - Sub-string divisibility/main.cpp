/*
	Problem 43

	The number, 1406357289, is a 0 to 9 pandigital number because it is made up
	of each of the digits 0 to 9 in some order, but it also has a rather interesting
	sub-string divisibility property.

	Let d1 be the 1st digit, d2 be the 2nd digit, and so on.
	In this way, we note the following:

	d2d3d4 = 406 is divisible by 2
	d3d4d5 = 063 is divisible by 3
	d4d5d6 = 635 is divisible by 5
	d5d6d7 = 357 is divisible by 7
	d6d7d8 = 572 is divisible by 11
	d7d8d9 = 728 is divisible by 13
	d8d9d10 = 289 is divisible by 17

	Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "../timer.h"

bool passes_all_conditions(const std::string &n);


int main()
{
	ProgramTimer timer;

	std::string n = "0123456789";
	unsigned long sum = 0;
	do {
		if (passes_all_conditions(n))
			sum += std::stoul(n);
	} while (std::next_permutation(n.begin(), n.end()));

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


bool passes_all_conditions(const std::string &n)
{
	// d4d5d6 = 635 is divisible by 5
	if (n[5] != '0' && n[5] != '5')
		return false;

	// d2d3d4 = 406 is divisible by 2
	if ((n[3] - '0') % 2 == 1)
		return false;

	// d3d4d5 = 063 is divisible by 3
	if (((n[2] - '0') + (n[3] - '0') + (n[4] - '0')) % 3 != 0)
		return false;

	unsigned t;

	// d5d6d7 = 357 is divisible by 7
	t = std::stoi(std::string(n.cbegin() + 4, n.cbegin() + 7));
	if (t % 7 != 0)
		return false;

	// d6d7d8 = 572 is divisible by 11
	t = std::stoi(std::string(n.cbegin() + 5, n.cbegin() + 8));
	if (t % 11 != 0)
		return false;

	// d7d8d9 = 728 is divisible by 13
	t = std::stoi(std::string(n.cbegin() + 6, n.cbegin() + 9));
	if (t % 13 != 0)
		return false;

	// d8d9d10 = 289 is divisible by 17
	t = std::stoi(std::string(n.cbegin() + 7, n.cbegin() + 10));
	if (t % 17 != 0)
		return false;

	return true;
}

/*
	Solution:	16695334890
	Avg time:	0.679972s
*/
