#include "primes.h"

SieveOfErathostenes::SieveOfErathostenes()
{

}

void SieveOfErathostenes::generate_with_limit(unsigned element_limit)
{
	m_sieve.resize(element_limit / 2, true);

	for (unsigned i = 1; i*i <= element_limit; i++) {
		if (m_sieve[i]) {
			unsigned step = 2*i + 1;
			for (unsigned j = 2*i*(i+1); j < m_sieve.size(); j += step)
				m_sieve[j] = false;
		}
	}
}

void SieveOfErathostenes::generate_for_exactly(unsigned prime_count)
{
	(void)prime_count;
	// TODO
}

const std::vector<bool>& SieveOfErathostenes::sieve() const
{
	return m_sieve;
}
