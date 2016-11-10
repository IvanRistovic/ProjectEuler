/*
 A library that is a collection of functions that work with number divisors,
 made for Project Euler tasks.
 All of the functions are optimized for speed, and most of them do not check
 their arguments. It is recommended to check the manual before using these functions
*/

#ifndef __H_DIVISORS_H__
#define __H_DIVISORS_H__


#include <stdio.h>
#include "primes.h"


    /* --- FUNCTIONS --- */

int div_num(unsigned number);
    /* returns number of all divisors of 'number' */
    
int div_sum(unsigned number);
    /* returns sum of all divisors of 'number' */

    
    
    // TODO, check some problem there is a function of REAL divisors?
    
    
    
    
#endif