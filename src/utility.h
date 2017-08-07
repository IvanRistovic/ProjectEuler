#ifndef _H_UTILITY_H_
#define _H_UTILITY_H_

#define pe_util::is_palindrome(x) pe_util::is_palindrome10(x)

namespace pe_util {

	bool is_palindrome2(unsigned n)
	{
		unsigned mask_left = 1 << (8 * sizeof(unsigned) - 1);
		unsigned mask_right = 1;

		// Skip leading zeros
		while ((unsigned)(n & mask_left) == 0)
			mask_left >>= 1;

		while (mask_left > mask_right) {
			unsigned r1 = n & mask_left;
			unsigned r2 = n & mask_right;
			if (((r1 == 0 && r2 == 0) || (r1 != 0 && r2 != 0)) == false)
				return false;
			mask_left >>= 1;
			mask_right <<= 1;
		}

		return true;
	}

	template <typename T>
	bool is_palindrome10(T n)
	{
		T reversed = 0, num = n;

		while (num) {
			reversed = reversed * 10 + num % 10;
			num /= 10;
		}

		if (reversed == n)
			return true;
		else
			return false;
	}

}	// pe_util

#endif
