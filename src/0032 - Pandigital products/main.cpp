/*
	Problem 32

	We shall say that an n-digit number is pandigital if it makes use of all the
	digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
	through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
	multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product identity
	can be written as a 1 through 9 pandigital.

	HINT: Some products can be obtained in more than one way so be sure to only
	include it once in your sum.
*/

#include <iostream>
#include <set>
#include "../timer.h"

bool is_pandigital(unsigned multiplier, unsigned multiplicand, unsigned product);


int main()
{
	ProgramTimer timer;

	std::set<unsigned> products;
	for (unsigned i = 1; i < 100; i++) {
		unsigned limit = 10000 / i + 1;
		for (unsigned j = i; j < limit; j++)
			if (is_pandigital(i, j, i*j))
				products.insert(i*j);
	}

	unsigned sum = 0;
	for (auto p : products)
		sum += p;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


bool is_pandigital(unsigned multiplier, unsigned multiplicand, unsigned product)
{
	bool digits[] = { false, false, false, false, false, false, false, false, false };

	for (; multiplier != 0; multiplier /= 10) {
		int digit = multiplier % 10 - 1;
		if (digit == -1 || digits[digit] == true)
			return false;
		else
			digits[digit] = true;
	}
	for (; multiplicand != 0; multiplicand /= 10) {
		int digit = multiplicand % 10 - 1;
		if (digit == -1 || digits[digit] == true)
			return false;
		else
			digits[digit] = true;
	}
	for (; product != 0; product /= 10) {
		int digit = product % 10 - 1;
		if (digit == -1 || digits[digit] == true)
			return false;
		else
			digits[digit] = true;
	}

	for (int i = 0; i < 9; i++)
		if (digits[i] == false)
			return false;

	return true;
}

/*
	Solution:	45228
	Avg time:	0.000890146s
*/
