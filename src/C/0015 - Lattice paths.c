/*
 Problem 15
 Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

 How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>

#define SIZE 20

void latticerec(unsigned long long *k, int x, int y);
unsigned long long latticecomb(void);
void lattice(void);

int main() {

	printf("%llu\n", latticecomb());

//	 lattice();

	/*
	unsigned long long k = 0;
	printf("Starting recursive solution (go grab something to eat, it will take a while)\n");
	latticerec(&k, 0, 0);
	printf("%llu\n", k);
	*/

	return 0;
}

void latticerec(unsigned long long *k, int x, int y) {

	/* works, but mega slow for SIZE > 15 */

	if (x == SIZE && y == SIZE) {
		(*k)++;
		return;
	}

	if (x == SIZE) {
		latticerec(k, x, y+1);
		return;
	}
	if (y == SIZE) {
		latticerec(k, x+1, y);
		return;
	}

	latticerec(k, x+1, y);
	latticerec(k, x, y+1);
}

unsigned long long latticecomb(void) {
	unsigned long long k = 1;
	int i;

	/* calculating n over SIZE */

	for (i = 0; i < SIZE; i++) {
		k = k * ((2 * SIZE) - i);
		k = k / (i + 1);
	}

	return k;
}

void lattice(void) {
	long long int matrix[SIZE+1][SIZE+1];
	int i, j;

	for (i = 0; i <= SIZE; i++) {
		matrix[SIZE][i] = 1;
		matrix[i][SIZE] = 1;
	}

	for (i = SIZE-1; i >= 0; i--)
		for (j = SIZE-1; j >= 0; j--)
			matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];

	printf("%lld\n", matrix[0][0]);
}

/*
 Solution (lattice & latticecomb):
 137846528820

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
