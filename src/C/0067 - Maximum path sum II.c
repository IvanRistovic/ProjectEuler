/*
 Problem 67
 By starting at the top of the triangle below and moving to adjacent numbers on
  the row below, the maximum total from top to bottom is 23.

 3
 7 4
 2 4 6
 8 5 9 3

 That is, 3 + 7 + 4 + 9 = 23.

 Find the maximum total from top to bottom in 0067.txt, a 15K text file
 containing a triangle with one-hundred rows.

 note: This is a much more difficult version of Problem 18. It is not possible
 to try every route to solve this problem, as there are 299 altogether! If you
 could check one trillion (1012) routes every second it would take over twenty
 billion years to check them all. There is an efficient algorithm to solve it.
 ;o)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int max(int a, int b);
int maxpath(int m[][MAX], int n);

int main() {
	int triangle[MAX][MAX];
	int i, j;
	FILE *f;

	f = fopen("../_txt/0067.txt", "r");
	if (f == NULL) {
		fprintf(stderr, "Missing 0067.txt file\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			if (j <= i)
				fscanf(f, "%d", &triangle[i][j]);
			else
				triangle[i][j] = 0;

	printf("%d\n", maxpath(triangle, MAX-1));

	fclose(f);
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int maxpath(int m[][MAX], int n) {
	int i, j;

	for (i = n-1; i >= 0; i--)
		for (j = 0; j <= i; j++)
			m[i][j] += max(m[i+1][j], m[i+1][j+1]);

	return m[0][0];
}

/*
 Solution:
 7273

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
