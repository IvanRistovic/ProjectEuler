/*
 Problem 17
 If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in
 words, how many letters would be used?

 note: Do not count spaces or hyphens. For example, 342 (three hundred and
 forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 letters. The use of "and" when writing out numbers is in compliance with
 British usage.
*/

#include <stdio.h>

#define AND 3
#define HUNDRED 7
#define ONETHOUSAND 11

int main() {
	unsigned ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	unsigned tenths[] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
	unsigned sum = 0;
	unsigned i, a, b, c;

	for (i = 1; i < 1000; i++) {
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;

		if (a != 0) {
			sum += ones[a] + HUNDRED;
			if (b != 0 || c != 0)
				sum += AND;
		}
		if (b == 0 || b == 1)
			sum += ones[b * 10 + c];
		else
			sum += tenths[b] + ones[c];
	}

	sum += ONETHOUSAND;

	printf("%u\n", sum);

	return 0;
}

/*
 Solution:
 21124

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
