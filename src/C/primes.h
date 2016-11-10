/*
 A library that works with prime numbers made for Project Euler tasks.
 All of the functions are optimized for speed, and most of them do not check
 their arguments. It is recommended to check the manual before using these functions

 NOTE: Compile with -lm
 NOTE: The bit operators are often used for multiplication/division by multiples of 2
*/


#ifndef __H_PRIMES_H__
#define __H_PRIMES_H__


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef char prime_indicator;


int PRIME_ARR_LEN;
#define PRIME_ARR_SIZE PRIME_ARR_LEN
    /* this variable is modified whenever generate_prime_array function is called
       the new array size is stored here, for the user to use */


    /* --- MACRO FUNCTIONS --- */

#define is_prime(n) is_prime_i(n)
    /* equivalent to is_prime_i */


    /* --- FUNCTIONS --- */
    
unsigned is_prime_u(unsigned number);
    /* prime test for an unsigned number greater than 2, no argument checking */

int is_prime_i(int number);
    /* prime test for a signed integer greater than 2, no argument checking */

int is_prime_acc(int number);
    /* accurate prime test for all integers
       has a few more instructions than specialized functions
       try not to call alot of times (noticeable difference shows for 100000 calls) */

int is_prime_arr(prime_indicator *prime_array, unsigned number);
    /* does a O(1) prime test if the prime_array from function below is provided
       NOTE: THIS FUNCTION DOES NOT WORK FOR NUMBER 2 */    

int is_prime_arr_odd(prime_indicator *prime_array, unsigned odd_number);
    /* same as the previous function, but skips the "is even" check */
    
prime_indicator* generate_prime_array(unsigned limit);
    /* NOTE: length of the array is saved in PRIME_ARR_LEN
          it can also be calculated using the following equation:
            arr_size = 2*limit + 1;
       generates char indicator array for every odd number if it is prime or not
       the limit is the biggest number that will have it's indicator in array
       the element at index i corresponds to number 2i+1, 1 if it is prime */

prime_indicator* generate_prime_array_n(unsigned num_of_primes);
    // TODO

unsigned find_prime(prime_indicator *prime_array, unsigned index);
    /* returns index-th prime number */

#endif
