#ifndef _H_PRIMES_H_
#define _H_PRIMES_H_

#include <vector>

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

class SieveOfErathostenes {
public:
	SieveOfErathostenes();

	void generate_with_limit(unsigned element_limit);
	void generate_for_exactly(unsigned prime_count);
	const std::vector<bool>& sieve() const;
	unsigned get_prime_with_index(unsigned index) const;

	template <typename T>
	bool is_prime(T number) {
		if ((number % 2 == 0 && number != 2) || number < 2)
			return false;
		else
			return m_sieve[number / 2];
	}

	template <typename T>
	bool is_prime_odd(T number) {
		return m_sieve[number / 2];
	}


private:
	std::vector<bool> m_sieve;
};

#endif
