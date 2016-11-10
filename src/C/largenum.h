/*
 A library that works with large numbers made for Project Euler tasks.
 All of the functions are optimized for speed, and most of them do not check
 their arguments. It is recommended to check the manual before using these functions

 NOTE: All of the following functions do not check their arguments
*/

#ifndef __H_LARGENUM_H__
#define __H_LARGENUM_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LARGENUM_MAX_DIGITS 1024
    /* maximum length of large number */
    

typedef struct _largenum_ {
    char digits[LARGENUM_MAX_DIGITS];
    int len;
} largenum;
typedef largenum BigInt;
typedef largenum LargeNum;
    /* the structure that stores our large number */        


    /* --- MACRO FUNCTIONS --- */

#define numlen(num) (num.len)

    
    /* --- FUNCTIONS --- */
    
BigInt load(char *string);
    /* loads large number from a string pointed to by 'string' */
    
BigInt fload(FILE *file);
    /* loads large number from a file pointed to by 'file' */
    
BigInt sfload(char *filename);
    /* loads large number from a file with a name 'filename'
       if the file opening fails, the function returns empty large number */

int cmp(BigInt, BigInt);
    /* compares two large numbers returning 0 if they are equal, 1 if first number is greater,
       -1 if second number is greater */

int digit_sum(BigInt);
    /* returns sum of all operand's digits */

BigInt add(BigInt, BigInt);
    /* adds two large numbers and returns result */
    
BigInt add_(BigInt, BigInt);
    /* slower version, old */
    
BigInt shift_left(BigInt);
    /* equivalent to multiplication with 10 */

BigInt turn(BigInt);
    /* reverses the digit order */
    
BigInt digit_mul(BigInt, char digit);
    /* multiplies number with a single digit */
    
BigInt digit_mul_(BigInt, char digit);
    /* slower version, old */
    
BigInt mul(BigInt, BigInt);
    /* multiplies two large numbers and returns result */
    
BigInt mul_slow(BigInt, BigInt);
    /* slower version, old */

void printnum(BigInt);
    /* prints argument to stdout */
    
void fprintnum(FILE *file, BigInt);
    /* prints argument to file pointed to by 'file' */
    
void sfprintnum(char *filename, BigInt);
    /* prints argument to file with a name 'filename' */

#endif
