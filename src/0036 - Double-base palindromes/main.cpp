/*
	Problem 36

	The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

	Find the sum of all numbers, less than one million, which are palindromic
	in base 10 and base 2.

	(Please note that the palindromic number, in either base, may not include
	leading zeros.)
*/

#include <iostream>
#include "../timer.h"

bool is_palindrome2(unsigned n);
bool is_palindrome10(unsigned n);


int main()
{
	ProgramTimer timer;

	unsigned sum = 0;
	for (unsigned i = 1; i < 1000000; i++)
		if (is_palindrome2(i) && is_palindrome10(i))
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


bool is_palindrome2(unsigned n)
{
	unsigned mask_left = 1 << (8 * sizeof(unsigned) - 1);
	unsigned mask_right = 1;

	// Skip leading zeros
	while ((unsigned)(n & mask_left) == 0)
		mask_left >>= 1;

	while (mask_left > mask_right) {
		unsigned r1 = n & mask_left;
		unsigned r2 = n & mask_right;
		if (((r1 == 0 && r2 == 0) || (r1 != 0 && r2 != 0)) == false)
			return false;
		mask_left >>= 1;
		mask_right <<= 1;
	}

	return true;
}

bool is_palindrome10(unsigned n)
{
	int reversed = 0, num = n;

	while (num) {
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}

	if (reversed == n)
		return true;
	else
		return false;
}

/*
	Solution:	872187
	Avg time:	0.0640739s
*/
