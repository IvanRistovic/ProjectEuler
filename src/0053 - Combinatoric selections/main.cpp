/*
	Problem 53

	There are exactly ten ways of selecting three from five, 12345:
	123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

	In combinatorics, we use the notation, C(5,3) = 10.

	In general,
	C(n,k) = n! / k!(n−k)! , where k <= n.

	It is not until n = 23, that a value exceeds one-million: C(23,10) = 1144066.

	How many, not necessarily distinct, values of C(n,k), for 1 ≤ n ≤ 100, are
	greater than one-million?
*/

#include <iostream>
#include "../timer.h"

#define SIZE (100)

int main()
{
	ProgramTimer timer;

	unsigned pascal[SIZE+1][SIZE/2+1];
	unsigned count = 0;
	for (unsigned n = 0; n <= SIZE; n++)
		pascal[n][0] = 1;

	for (unsigned n = 1; n <= SIZE; n++) {
		for (unsigned k = 1; k <= n/2; k++) {
			pascal[n][k] = pascal[n-1][k-1] + pascal[n-1][k];
			if (k == n / 2 && n % 2 == 0)
				pascal[n][k] += pascal[n-1][k-1];
			if (pascal[n][k] > 1000000) {
				pascal[n][k] = 1000000;
				count += n - 2*k + 1;
				break;
			}
		}
	}

	std::cout << count << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	4075
	Avg time:	0.000172503s
*/
