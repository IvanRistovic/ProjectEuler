/*
	Problem 36

	The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

	Find the sum of all numbers, less than one million, which are palindromic
	in base 10 and base 2.

	(Please note that the palindromic number, in either base, may not include
	leading zeros.)
*/

#include <iostream>
#include "../utility.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	unsigned sum = 0;
	for (unsigned i = 1; i < 1000000; i++)
		if (pe_util::is_palindrome2(i) && pe_util::is_palindrome10(i))
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	872187
	Avg time:	0.0640739s
*/
