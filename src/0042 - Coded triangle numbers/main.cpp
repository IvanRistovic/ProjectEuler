/*
	Problem 42

	The nth term of the sequence of triangle numbers is given by,
	tn = 1/2 * n * (n+1); so the first ten triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	By converting each letter in a word to a number corresponding to its
	alphabetical position and adding these values we form a word value.
	For example, the word value for SKY is 19 + 11 + 25 = 55 = t10.
	If the word value is a triangle number then we shall call the word a triangle word.

	Using 0042.txt, a 16K text file containing nearly two-thousand common English
	words, how many are triangle words?
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	std::vector<unsigned> triagle_numbers;
	for (unsigned i = 1, step = 2; i < 1000; i += step, step++)
		triagle_numbers.push_back(i);

	FILE *f = std::fopen("../_txt/0042.txt", "r");
	if (f == NULL)
		return 1;

	std::vector<std::string> words;

	char word[64];
	while (std::fscanf(f, "%[\"A-Z]", word) != EOF) {
		words.push_back(std::string(word));
		std::fgetc(f);
	}
	std::fclose(f);

	unsigned count = 0;
	for (auto word : words) {
		unsigned value = 0;
		for (auto it = word.cbegin() + 1; it != word.cend() - 1; it++)
			value += *it - 'A' + 1;
		if (std::binary_search(triagle_numbers.cbegin(), triagle_numbers.cend(), value))
			count++;
	}

	std::cout << count << '\n';

	timer.print_time();
	return 0;
}

/*
	Solution:	162
	Avg time:	0.00351698s
*/
