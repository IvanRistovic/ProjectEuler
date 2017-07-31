/*
	Problem 39

	If p is the perimeter of a right angle triangle with integral length sides,
	{a,b,c}, there are exactly three solutions for p = 120:

	{20,48,52}, {24,45,51}, {30,40,50}

	For which value of p <= 1000, is the number of solutions maximised?
*/

/*
	First, it's important to recognize that ANY primitive Pythagorean triple (a,b,c)
	can be written in the form:

	a = p^2 - q^2, b = 2*p*q, c = p^2 + q^2

	This is important because the Perimeter can then be written as:
	Perimeter = 2 * p * (p + q)

	Furthermore, if p and q come from the set of coprime integers such that exactly
	one is even, we know we will hit ONLY primitive Pythagorean triples.

	Thus, we just use a nested for loop to loop through all the numbers p and q
	such that 2 * p * (p+q) <= perimeter. For each pair add one to the "count"
	for every number 2 * p * (p+q) * k that is less than the perimeter.
*/

#include <iostream>
#include "../divisors.h"
#include "../timer.h"

#define LIMIT (1000)

int main()
{
	ProgramTimer timer;

	int perimeters[LIMIT] = { 0 };

	for (int p = 1; 2*p*p < LIMIT; p++) {
		for (int q = (p%2)+1; 2*p*(p+q) <= LIMIT; q += 2) {
			if (pe_div::gcd(p, q) == 1) {
				int t = 2*p*(p+q);
				while (t <= LIMIT) {
					perimeters[t-1] += 1;
					t += 2 * p * (p+q);
				}
			}
		}
	}

	int max = 0;
	int max_count = 0;
	for (int i = 0; i < LIMIT; i++) {
		if (max_count < perimeters[i]) {
			max_count = perimeters[i];
			max = i + 1;
		}
	}

	std::cout << max << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	840
	Avg time:	0.000228788s
*/
