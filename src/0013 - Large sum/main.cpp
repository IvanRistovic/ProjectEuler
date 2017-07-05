/*
	Problem 13

	Work out the first ten digits of the sum of the following one-hundred 50-digit
	numbers (see the 0013.txt).
*/

#include <stdio.h>
#include <fstream>
#include <gmpxx.h>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	mpz_class sum(0), n;

	std::ifstream f("../_txt/0013.txt");
	do {
		sum += n;
		f >> n;
	} while (f);
	f.close();

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	5537376230390876637302048746832985971773659831892672
	Avg time:	0.000311689s
*/
