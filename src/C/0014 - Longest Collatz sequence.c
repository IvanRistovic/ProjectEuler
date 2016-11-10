/*
 Problem 14                                                               
 The following iterative sequence is defined for the set of positive integers:
 
 n → n/2 (n is even)
 n → 3n + 1 (n is odd)
 
 Using the rule above and starting with 13, we generate the following sequence:
 
 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 
 Which starting number, under one million, produces the longest chain?
 
 note: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>

#define START 500001
#define LIMIT 1000000

int main() {
    unsigned i, current_chain, max, max_chain = 0;
    
    // there is no reason to check numbers lower than 500000 because 
    // all numbers between 500001 and 1000000 must have longer chain
    // also i don't have to check even numbers
    // there is much faster one below with cache
    
    // i am creating a cache array, i will save the chain length for
    // all numbers along the way. if i get to some number i have already
    // calculated, i will just add those two values together
    
    unsigned cache[LIMIT + 1];      // 1000001 integers ~4MB doesn't hurt
    cache[1] = 1;                   // 1 takes 1 step to finish
    
    unsigned number;
    for (i = 2; i < LIMIT; i++) {
        number = i;
        current_chain = 0;
        
        // calculating chain length
        while (number != 1 && number >= i) {
            current_chain++;
            if (number & 1)
                number += (number << 1) + 1;    // 3n + 1
            else
                number >>= 1;                   // n/2
        }
        
        // store in cache
        cache[i] = current_chain + cache[number];
        
        // checking if this chain is longest
        if (cache[i] > max_chain) {
            max_chain = cache[i];
            max = i;
        }
    }
    
    printf("%u\n", max);
    
    return 0;
}

/*
 Solution:
 837799
 
 real 0m0.071s
 user 0m0.060s
 sys  0m0.000s
*/