/*
	Problem 38

	Take the number 192 and multiply it by each of 1, 2, and 3:
	192 x 1 = 192
	192 x 2 = 384
	192 x 3 = 576
	By concatenating each product we get the 1 to 9 pandigital, 192384576.
	We will call 192384576 the concatenated product of 192 and (1,2,3)

	The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
	and 5, giving the pandigital, 918273645, which is the concatenated product
	of 9 and (1,2,3,4,5).

	What is the largest 1 to 9 pandigital 9-digit number that can be formed as
	the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "../timer.h"

bool is_concat_prod(const std::string &num);


int main()
{
	ProgramTimer timer;

	std::string num = "987654321";
	do {
		if (is_concat_prod(num))
			break;
	} while (std::prev_permutation(num.begin(), num.end()));

	std::cout << num << '\n';

	timer.print_time();
	return 0;
}


bool is_concat_prod(const std::string &num)
{
	for (int i = 1; i <= 4; i++) {
		auto result = std::stoi(std::string(num.cbegin(), num.cbegin() + i));

		unsigned offset = i;
		unsigned current_res = result;
		while (result < 10000 && offset < num.length()) {
			current_res += result;
			std::string res_str = std::to_string(current_res);
			if (num.find(res_str) == offset)
				offset += res_str.length();
			else
				break;
		}

		if (offset >= num.length())
			return true;
	}

	return false;
}

/*
	Solution:	932718654
	Avg time:	0.0806915s
*/
