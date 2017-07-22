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

#include <iostream>
#include <vector>
#include "../timer.h"
#include "../divisors.h"

#define START 12
#define LIMIT 28123

void create_sums(std::vector<unsigned> &abundant_numbers, std::vector<bool> &sums);


int main()
{
	ProgramTimer timer;

	std::vector<unsigned> abundant_numbers;
	std::vector<bool> sums(LIMIT + 1, false);

	for (unsigned i = START; i < LIMIT; i++)
		if (div_sum(i) > i)
			abundant_numbers.push_back(i);

	create_sums(abundant_numbers, sums);

	unsigned sum = 0;
	for (unsigned i = 1; i <= LIMIT; i++)
		if (!sums[i])
			sum += i;

	std::cout << sum << '\n';

	timer.print_time();
	return 0;
}


void create_sums(std::vector<unsigned> &abundant_numbers, std::vector<bool> &sums)
{
	for (unsigned i = 0; i < abundant_numbers.size(); i++) {
		for (unsigned j = i; j < abundant_numbers.size(); j++) {
			int tmp = abundant_numbers[i] + abundant_numbers[j];
			if (tmp <= LIMIT)
				sums[tmp] = true;
			else
				break;
		}
	}
}

/*
	Solution:	4179871
	Avg time:	0.671717s
*/
