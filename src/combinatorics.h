#ifndef _H_COMBINATORICS_H_
#define _H_COMBINATORICS_H_

namespace pe_comb {

	template <typename T>
	T choose(T n, T k)
	{
		T result = 1;

		for (T i = 1; i <= k; i++) {
			result *= n - (k - i);
			result /= i;
		}

		return result;
	}

	template <typename T>
	bool is_perm(T m, T n)
	{
		T arr[10] = { 0 };

		T temp = n;
		while (temp > 0) {
			arr[temp % 10]++;
			temp /= 10;
		}

		temp = m;
		while (temp > 0) {
			arr[temp % 10]--;
			temp /= 10;
		}

		for (unsigned i = 0; i < 10; i++)
			if (arr[i] != 0)
				return false;

		return true;
	}

}	// namespace pe_comb

#endif
