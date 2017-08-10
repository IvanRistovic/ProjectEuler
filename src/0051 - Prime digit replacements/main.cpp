/*
	Problem 51

	By replacing the 1st digit of the 2-digit number *3, it turns out that six
	of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

	By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit
	number is the first example having seven primes among the ten generated numbers,
	yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
	Consequently 56003, being the first member of this family, is the smallest
	prime with this property.

	Find the smallest prime which, by replacing part of the number (not necessarily
	adjacent digits) with the same digit, is part of an eight prime value family.
*/

/*
	A few things which I will exploit:
		- Since we are looking for 8 prime value family number, the digits that are
		repeated must be either 0, 1 or 2.
		- The only number of repeated digits that make sense is 3, since in any
		other case the modulo 3 of the sum of the repeated digits will be 0 more
		than 2 times (hence we can't get 8 primes).
		- Last digit cannot be a repeated digit (obviously)
*/

#include <iostream>
#include "../primes.h"
#include "../timer.h"

#define PATTERN_NUM (10)
#define PATTERN_SIZE (6)

void fill_pattern(int result[], unsigned number, const bool pattern[]);
unsigned make_num(int filled_pattern[], unsigned repeated_digit);


int main()
{
	ProgramTimer timer;

	// Creating all possible patterns for the number to test
	const bool patterns[PATTERN_NUM][PATTERN_SIZE] = {
		{ 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 1 },
		{ 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 1 },
		{ 0, 1, 1, 0, 0, 1 },
		{ 0, 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 0, 1, 1 },
		{ 0, 0, 1, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 0, 1, 1, 1 }
	};

	unsigned result = ~0u;

	// Loop through 3 digit numbers and put them in pattern
	for (unsigned i = 100; i < 1000; i++) {
		if (i % 5 == 0)
			continue;

		for (unsigned j = 0; j < PATTERN_NUM; j++) {
			for (unsigned digit = 0; digit <= 2; digit++) {
				// Don't generate number with leading zeros
				if (!patterns[j][0] && digit == 0)
					continue;

				int filled_pattern[PATTERN_SIZE];
				fill_pattern(filled_pattern, i, patterns[j]);

				unsigned candidate = make_num(filled_pattern, digit);
				if (candidate < result && pe_primes::is_prime(candidate)) {
					// Count family size
					unsigned count = 1;
					for (unsigned d = digit + 1; d < 10; d++)
						if (pe_primes::is_prime(make_num(filled_pattern, d)))
							count++;
					if (count == 8)
						result = candidate;
					break;
				}
			}
		}
	}

	std::cout << result << '\n';

	timer.print_time();
	return 0;
}


void fill_pattern(int result[], unsigned number, const bool pattern[])
{
	for (int i = PATTERN_SIZE - 1; i >= 0; i--) {
		if (pattern[i]) {
			result[i] = number % 10;
			number /= 10;
		} else {
			result[i] = -1;
		}
	}
}

unsigned make_num(int filled_pattern[], unsigned repeated_digit)
{
	unsigned res = 0;
	for (int i = 0; i < PATTERN_SIZE; i++) {
		res *= 10;
		res += (filled_pattern[i] == -1) ? repeated_digit : filled_pattern[i];
	}
	return res;
}

/*
	Solution:	121313
	Avg time:	0.0224266s
*/
