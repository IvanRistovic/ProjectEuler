/*
	Problem 23

	A perfect number is a number for which the sum of its proper divisors is
	exactly equal to the number. For example, the sum of the proper divisors of
	28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than
	n and it is called abundant if this sum exceeds n.
	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
	number that can be written as the sum of two abundant numbers is 24.

	By mathematical analysis, it can be shown that all integers greater than 28123
	can be written as the sum of two abundant numbers. However, this upper limit
	cannot be reduced any further by analysis even though it is known that the
	greatest number that cannot be expressed as the sum of two abundant numbers is
	less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum
	of two abundant numbers.
*/

/*
	Some things that might help:
	1. Every multiple of a perfect number is abundant.
	2. Every multiple of an abundant number is abundant.
	3. Every integer greater than 20161 can be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include "../divisors.h"
#include "../timer.h"

#define LIMIT 20161

void create_abundants(std::vector<unsigned> &abundant_numbers, bool abund_ind[]);
void create_sums(std::vector<unsigned> &abundant_numbers, bool abund_ind[]);


int main()
{
	ProgramTimer timer;

	bool abund_ind[LIMIT + 1];
	std::vector<unsigned> abundant_numbers;

	create_abundants(abundant_numbers, abund_ind);
	create_sums(abundant_numbers, abund_ind);

	unsigned sum = 0;
	for (unsigned i = 1; i <= LIMIT; i++)
		if (!abund_ind[i])
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


void create_abundants(std::vector<unsigned> &abundant_numbers, bool abund_ind[])
{
	// Reset indicators
	std::memset(abund_ind, false, LIMIT);

	for (unsigned i = 2; i < LIMIT; i++) {
		if (!abund_ind[i]) {
			unsigned divsum = pe_div::div_sum(i);

			// If the number is perfect
			if (divsum == i) {
				for (unsigned j = 2; j * i <= LIMIT; j++)
					abund_ind[j * i] = true;
			}

			// If the number is abundant
			if (divsum > i) {
				for (unsigned j = 1; j * i <= LIMIT; j++)
					abund_ind[j * i] = true;
			}
		}
	}

	for (unsigned i = 0; i < LIMIT; i++)
		if (abund_ind[i])
			abundant_numbers.push_back(i);
}

void create_sums(std::vector<unsigned> &abundant_numbers, bool abund_ind[])
{
	// Reset indicators
	std::memset(abund_ind, false, LIMIT);

	for (unsigned i = 0; i < abundant_numbers.size(); i++) {
		for (unsigned j = i; j < abundant_numbers.size(); j++) {
			int tmp = abundant_numbers[i] + abundant_numbers[j];
			if (tmp <= LIMIT)
				abund_ind[tmp] = true;
			else
				break;
		}
	}
}

/*
	Solution:	4179871
	Avg time:	0.117534s
*/
