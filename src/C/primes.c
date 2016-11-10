#include "primes.h"


unsigned is_prime_u(unsigned number) {
    unsigned i;
    
    if (!(number & 1u))
        return 0;
    
    for (i = 3u; i*i <= number; i += 2u)
        if (number % i == 0u)
            return 0u;
    
    return 1u;
}

int is_prime_i(int number) {
    int i;
    
    if (!(number & 1))
        return 0;
    
    for (i = 3; i*i <= number; i += 2)
        if (number % i == 0)
            return 0;
    
    return 1;
}

int is_prime_acc(int number) {
    int i;
    
    if (!(number & 1) || number < 2)
        return 0;
    
    for (i = 3; i*i <= number; i += 2)
        if (number % i == 0)
            return 0;
    
    return 1;
}

int is_prime_arr(prime_indicator *prime_array, unsigned number) {
    if ((number & 1) == 0)              // "is even" check
        return 0;
    
    if (prime_array[number >> 1])
        return 1;
    else 
        return 0;
}

int is_prime_arr_odd(prime_indicator *prime_array, unsigned number) {
    if (prime_array[number >> 1])
        return 1;
    else 
        return 0;
}

prime_indicator* generate_prime_array(unsigned limit) {
    
    /* the idea is to use the sieve of erathostenes.
     * we will create a char indicator array that will keep information
     * in the following way:
     *      element on position i corresponds to number 2*i+1, if that element
     *      is 1, then the number 2*i+1 is prime
     * the reason for this is because we do not need to save indicators for
     * odd numbers (saves half the memory). */
    
    
    // calculating array_size and cross limit for counter i
    unsigned array_size = (limit) >> 1;
    unsigned crosslimit = ((unsigned)floor(sqrt(limit-1)-1)) >> 1;
    array_size++;   // since we count from index 1, 0 gives that 1 is prime so..
    PRIME_ARR_LEN = array_size;
    
    prime_indicator *sieve = malloc(array_size * sizeof(char));
    sieve[0] = 0;   // here we say 1 isn't prime, in case someone counts from 0
    
    // initializing array to 1 - all are prime
    unsigned i, j;
    for (i = 1; i < array_size; i++)
        sieve[i] = 1;
    
    // for every number that isn't crossed
    for (i = 1; i <= crosslimit; i++)
        if (sieve[i]) {
            // cross all it's multiples from number (2i+1)^2 
            // since we have only odd numbers in array, that would be number
            // 4i^2 + 4i + 1, which has index 2i(i+1)
            int tmp = i << 1;         // 2i
            j = tmp * (i + 1);        // 2i(i+1)
            tmp++;                    // step for j is 2i+1
            for (; j < array_size; j += tmp)
                sieve[j] = 0;
        }
        
    return sieve;
}

prime_indicator* generate_prime_array_n(unsigned num_of_primes) {
    
    // TODO
        
    return NULL;
}

unsigned find_prime(prime_indicator *prime_array, unsigned index) {
    unsigned i = 0, counter = 0;
    
    if (index == 1)
        return 2u;
    
    index--;                     // 2 is first prime and it isn't in list
    do {
        i++;
        if (prime_array[i])
            counter++;
    } while (counter != index);

    return (i << 1) + 1;
}