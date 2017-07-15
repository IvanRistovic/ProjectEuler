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

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include "../timer.h"

#define MAX_NAME_LEN 64

unsigned value_sum(std::vector<std::string> &names);


int main()
{
	ProgramTimer timer;

	std::vector<std::string> names;

	FILE *f = std::fopen("../_txt/0022.txt", "r");
	if (f == NULL)
		return 1;

	char name[MAX_NAME_LEN];
	while (std::fscanf(f, "%[\"A-Z]", name) != EOF) {
		names.push_back(std::string(name));
		std::fgetc(f);
	}
	std::fclose(f);

	std::sort(names.begin(), names.end());
	std::cout << value_sum(names) << '\n';

	timer.print_time();
	return 0;
}


unsigned value_sum(std::vector<std::string> &names)
{
	unsigned sum = 0;

	for (unsigned i = 0; i < names.size(); i++) {
		unsigned tmp = 0;
		for (unsigned j = 1; names[i][j] != '"'; j++)
			tmp += names[i][j] - 'A' + 1;
		sum += tmp * (i+1);
	}

	return sum;
}

/*
	Solution:	871198282
	Avg time:	0.0212568s
*/
