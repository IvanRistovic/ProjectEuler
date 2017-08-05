/*
	Problem 67

	By starting at the top of the triangle below and moving to adjacent numbers
	on the row below, the maximum total from top to bottom is 23.

	3
	7 4
	2 4 6
	8 5 9 3

	That is, 3 + 7 + 4 + 9 = 23.

	Find the maximum total from top to bottom in 0067.txt, a 15K text file
	containing a triangle with one-hundred rows.

	Note: This is a much more difficult version of Problem 18. It is not possible
	to try every route to solve this problem, as there are 2^99 altogether! If you
	could check one trillion (10^12) routes every second it would take over twenty
	billion years to check them all. There is an efficient algorithm to solve it.
	;o)
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "../timer.h"

#define TRIANGLE_SIZE 100

int maxpath(int m[][TRIANGLE_SIZE], int n);

int main()
{
	ProgramTimer timer;

	int triangle[TRIANGLE_SIZE][TRIANGLE_SIZE];

	std::ifstream f("../_txt/0067.txt");
	if (!f.is_open())
		return 1;

	for (int i = 0; i < TRIANGLE_SIZE; i++)
		for (int j = 0; j < TRIANGLE_SIZE; j++)
			if (j <= i)
				f >> triangle[i][j];
			else
				triangle[i][j] = 0;
	f.close();

	std::cout << maxpath(triangle, TRIANGLE_SIZE-1) << '\n';

	timer.print_time();
	return 0;
}

int maxpath(int m[][TRIANGLE_SIZE], int n)
{
	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			m[i][j] += std::max(m[i+1][j], m[i+1][j+1]);

	return m[0][0];
}

/*
	Solution:	7273
	Avg time:	0.00155916s
*/
