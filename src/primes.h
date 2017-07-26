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

	void rewind();

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
T SieveOfErathostenes::next_prime() {
	do {
		m_pos++;
	} while (m_pos < m_sieve.size() && m_sieve[m_pos] == false);

	return (T)(2 * m_pos + 1);
}

#endif
