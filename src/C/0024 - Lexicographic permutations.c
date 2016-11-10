/*
 Problem 24
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>

#define SIZE 10
#define INIT 1000000

unsigned fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int ceili(double x);
void remove_from_array(int *array, int n, int x);

int main() {
    int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char perm[SIZE + 1];
    int k = INIT, i, n = SIZE;
    
    for (i = 0; i < SIZE; i++) {
        int tmp1 = fact[n-1];
        int tmp2 = ceili((double)k / tmp1);
        perm[i] = array[tmp2 - 1] + '0';    // tmp2 - 1 because we count from 0
        k = k - (tmp2 - 1) * tmp1;
        remove_from_array(array, n, array[tmp2 - 1]);
        n--;
    }
    perm[i] = '\0';
    
    printf("%s\n", perm);
    
    return 0;
}

int ceili(double x) {
    int tmp = (int)x;
    
    if (x > tmp)
        return tmp + 1;
    else
        return tmp;
}

void remove_from_array(int *array, int n, int x) {
    int i;
    
    for (i = 0; array[i] != x; i++)
        ;
    for (; i < n-1; i++)
        array[i] = array[i+1];
}

/*
 Solution:
 2783915460
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/