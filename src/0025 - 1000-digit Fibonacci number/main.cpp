/*
	Problem 25

	The Fibonacci sequence is defined by the recurrence relation:

	Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
	Hence the first 12 terms will be:

	F1 = 1
	F2 = 1
	F3 = 2
	F4 = 3
	F5 = 5
	F6 = 8
	F7 = 13
	F8 = 21
	F9 = 34
	F10 = 55
	F11 = 89
	F12 = 144
	The 12th term, F12, is the first term to contain three digits.

	What is the index of the first term in the Fibonacci sequence to contain
	1000 digits?
*/

#include <iostream>
#include <gmpxx.h>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	mpz_class f1(1), f2(1), f3(2);
	int index = 2;

	while (mpz_sizeinbase(f1.get_mpz_t(), 10) < 1000) {
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
		index++;
	}

	std::cout << index << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	4782
	Avg time:	0.00172537s
*/
