/*
 Problem 22
 Using names.txt, a 46K text file containing over five-thousand first names,
 begin by sorting it into alphabetical order. Then working out the alphabetical
 value for each name, multiply this value by its alphabetical position in the
 list to obtain a name score.

 For example, when the list is sorted into alphabetical order, COLIN, which is
 worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 would obtain a score of 938 x 53 = 49714.

 What is the total of all the name scores in the file?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64
#define ARRAY_SIZE 5163

int compare(const void* a, const void* b);
unsigned value_sum(char *array[], int n);

int main() {
	char *array[ARRAY_SIZE], name[MAX];

	FILE *f = fopen("../_txt/0022.txt", "r");
	if (f == NULL) {
		perror("_txt/0022.txt");
		exit(EXIT_FAILURE);
	}

	int i = 0, n;
	while (fscanf(f, "%[\"A-Z]", name) != EOF) {
		array[i++] = strdup(name);
		fgetc(f);
	}
	fclose(f);
	n = i;

	qsort(array, n, sizeof(char*), &compare);

	printf("%u\n", value_sum(array, n));

	/* freeing */
	for (i = 0; i < n; i++)
		free(array[i]);

	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

unsigned value_sum(char *array[], int n) {
	int i, j, tmp;
	unsigned sum = 0;

	for (i = 0; i < n; i++) {
		tmp = 0;
		j = 1;							  // skip initial "
		while (array[i][j] != '"')
			tmp += array[i][j++] - 'A' + 1;
		sum += tmp * (i+1);
	}

	return sum;
}

/*
 Solution:
 871198282

 real 0m0.005s
 user 0m0.004s
 sys  0m0.000s
*/
