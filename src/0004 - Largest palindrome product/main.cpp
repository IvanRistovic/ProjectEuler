/*
	Problem 4

	A palindromic number reads the same both ways. The largest palindrome made
	from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include "../utility.h"
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	int max_product = 0;
	for (int i = 999; i >= 100; i--) {
		for (int j = i; j >= 100; j--) {
			int product = i * j;
			if (product > max_product && pe_util::is_palindrome(product))
				max_product = product;
		}
	}

	std::cout << max_product << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	906609
	Avg time:	0.00169847s
*/
