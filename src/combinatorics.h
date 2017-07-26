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

}	// namespace pe_comb

#endif
