#ifndef _H_PRIMES_H_
#define _H_PRIMES_H_

#include <vector>

namespace pe_primes {

	template <typename T>
	bool is_prime(T number, T start = 2)
	{
		for (T i = start; i*i <= number; i++)
			if (number % i == 0)
				return false;

		return true;
	}

	template <typename T>
	bool is_prime_full(T number)
	{
		if (number < 2)
			return false;
		else
			return is_prime(number);
	}

}	// namespace pe_primes

class SieveOfErathostenes {
public:
	SieveOfErathostenes();

	void generate_with_limit(unsigned element_limit);
	void generate_for_exactly(unsigned prime_count);

	const std::vector<bool>& sieve() const;

	template <typename T>
	bool is_prime(T number) const;

	template <typename T>
	bool is_prime_odd(T number) const;

	template <typename T>
	T accumulate() const;

	template <typename T>
	T next_prime();

	template <typename T>
	void create_prime_vector(std::vector<T> &v);

	void rewind();
	void setpos(unsigned pos);

	unsigned operator[](unsigned index) const;

private:
	std::vector<bool> m_sieve;
	unsigned m_pos;
};

template <typename T>
bool SieveOfErathostenes::is_prime(T number) const
{
	if ((number % 2 == 0 && number != 2) || number < 2)
		return false;
	else
		return m_sieve[number / 2];
}

template <typename T>
bool SieveOfErathostenes::is_prime_odd(T number) const
{
	return m_sieve[number / 2];
}

template <typename T>
T SieveOfErathostenes::accumulate() const
{
	T sum = 2;
	for (unsigned i = 1; i < m_sieve.size(); i++)
		if (m_sieve[i])
			sum += (T)(2*i + 1);
	return sum;
}

template <typename T>
T SieveOfErathostenes::next_prime()
{
	do {
		m_pos++;
	} while (m_pos < m_sieve.size() && m_sieve[m_pos] == false);

	return (T)(2 * m_pos + 1);
}

template <typename T>
void SieveOfErathostenes::create_prime_vector(std::vector<T> &v)
{
	v.clear();
	v.push_back(2);
	for (unsigned i = 1; i < m_sieve.size(); i++)
		if (m_sieve[i])
			v.push_back((T)(2*i + 1));
}


class MillerRabinPrimeTest {
public:
	MillerRabinPrimeTest() = delete;

	template <typename T>
	static bool is_prime(T n)
	{
		if (n < 100)
			return pe_primes::is_prime(n);

		int r, d;
		factor((int)n - 1, &r, &d);
		long long lln = (long long)n;

		int witnesses[] = { 2, 7, 61 };
		for (int i = 0; i < 3; i++) {
			long long prev = (long long)pow_mod_n(witnesses[i], d, (int)n);
			long long curr;
			for (int k = 1; k <= r; k++) {
				curr = (prev * prev) % lln;
				if ((curr == 1ll) && (prev != 1ll) && (prev != lln - 1ll))
					return false;
				prev = curr;
			}
			if (curr != 1)
				return false;
		}
		return true;
	}

private:
	template <typename T>
	static int pow_mod_n(T base, T e, T n)
	{
		long long power = base;
		long long result = 1;
		long long lln = (long long)n;

		while (e) {
			if (e % 2)
				result = (result * power) % lln;
			power = (power * power) % lln;
			e /= 2;
		}

		return (int)result;
	}

	template <typename T>
	static void factor(T n, T *r, T *d)
	{
		(*r) = 0;
		(*d) = 1;
		while (n % 2 == 0) {
			n /= 2;
			(*r)++;
		}
		*d = n;
	}
};

#endif
