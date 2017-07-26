#ifndef _H_DIVISORS_H_
#define _H_DIVISORS_H_

namespace pe_div {

	template <typename T>
	T gcd(T n, T d)
	{
		while (d != 0) {
			T r = n % d;
			n = d;
			d = r;
		}

		return n;
	}

	template <typename T>
	unsigned div_num(T x)
	{
		unsigned p = 1;

		for (T i = 2; i <= x; i++) {
			unsigned v = 0;
			while (x % i == 0) {
				x /= i;
				v++;
			}
			if (v)
				p *= (v + 1);
		}

		return p;
	}

	template <typename T>
	T div_sum(T n)
	{
		unsigned sum = 1;
		T i;

		for (i = 2; i*i < n; i++)
			if (n % i == 0)
				sum += i + n/i;

		if (i*i == n)
			sum += i;

		return sum;
	}

}	// namespace divisors

#endif
