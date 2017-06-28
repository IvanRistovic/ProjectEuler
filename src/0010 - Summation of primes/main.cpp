/*
	Problem 10

	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include "../timer.h"
#include "../primes.h"

int main()
{
	ProgramTimer timer;

	SieveOfErathostenes e;
	e.generate_with_limit(2000000);

	std::cout << e.accumulate<unsigned long>() << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	142913828922
	Avg time:	0.335731s
*/
