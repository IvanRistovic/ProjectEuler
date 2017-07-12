/*
	Problem 14

	The following iterative sequence is defined for the set of positive integers:

	n → n/2 (n is even)
	n → 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:

	13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain?

	Note: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	/*
		I am creating a cache array where I will save the chain length for
		all the numbers along the way. If I get to some number whose chain
		I have already calculated, I will just add those two values together
	*/
	unsigned cache[1000001];
	cache[1] = 1;

	unsigned max, max_chain = 0;

	/*
		There is no reason to check numbers lower than 500000 because
		all numbers between 500001 and 1000000 must have longer chain.
	*/
	for (unsigned i = 500001; i < 1000000; i++) {
		unsigned number = i;
		unsigned current_chain = 0;

		while (number != 1 && number >= i) {
			current_chain++;
			if (number % 2 == 1)
				number = 3*number + 1;
			else
				number /= 2;
		}

		cache[i] = current_chain + cache[number];
		if (cache[i] > max_chain) {
			max_chain = cache[i];
			max = i;
		}
	}

	std::cout << max << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	837799
	Avg time:	0.0403015s
*/
