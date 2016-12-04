/*
 Problem 18
 By starting at the top of the triangle below and moving to adjacent numbers
 on the row below, the maximum total from top to bottom is 23.

 3
 7 4
 2 4 6
 8 5 9 3

 That is, 3 + 7 + 4 + 9 = 23.

 Find the maximum total from top to bottom of the triangle below:

 75
 95 64
 17 47 82
 18 35 87 10
 20 04 82 47 65
 19 01 23 75 03 34
 88 02 77 73 07 63 67
 99 65 04 28 06 16 70 92
 41 41 26 56 83 40 80 70 33
 41 48 72 33 47 32 37 16 94 29
 53 71 44 65 25 43 91 52 97 51 14
 70 11 33 28 77 73 17 78 39 68 17 57
 91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

 note: As there are only 16384 routes, it is possible to solve this problem by
 trying every route. However, Problem 67, is the same challenge with a triangle
 containing one-hundred rows; it cannot be solved by brute force, and requires
 a clever method! ;o)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int max(int a, int b);
int maxpath(int m[][MAX], int n);

int main() {
	int triangle[MAX][MAX];
	int i, j;
	FILE *f;

	f = fopen("../_txt/0018.txt", "r");
	if (f == NULL) {
		perror("_txt/0018.txt");
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
 1074

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
