#include "divisors.h"

int div_num(unsigned x) {
    unsigned v, p = 1, i;
    
    // x = i1^v1 * i2^v2 ... ik^vk    - p = (v1+1)(v2+1)...(vk+1) divisors
    
    for (i = 2; i <= x; i++) {
        v = 0;
        while (x % i == 0) {
            x /= i;
            v++;
        }
        if (v)
            p *= (v+1);
    }
    
    return p;
}

int div_sum(unsigned n) {
    unsigned i, sum = 1;
    
    for (i = 2; i*i < n; i++)
        if (n % i == 0)
            sum += i + n/i;
    
    if (i*i == n)
        sum += i;    
    
    return sum;
}