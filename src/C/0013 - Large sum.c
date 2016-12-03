/*
 Problem 13
 Work out the first ten digits of the sum of the following one-hundred 50-digit numbers (see the 0013.txt)
*/

/* ATTENTION Compile with largenum.c */

#include <stdio.h>
#include <stdlib.h>
#include "largenum.h"

int main() {
	FILE *f = fopen("0013.txt", "r");
	largenum sum, temp;
	char s[LARGENUM_MAX_DIGITS];

	if (f == NULL)
		exit(EXIT_FAILURE);

	sum = load("0");
	while (fscanf(f, "%s", s) == 1) {
		temp = load(s);
		sum = add(sum, temp);
	}
	fclose(f);

	printnum(sum);

	return 0;
}

/*
 Solution:
 5537376230390876637302048746832985971773659831892672

 real 0m0.004s
 user 0m0.000s
 sys  0m0.000s
*/
