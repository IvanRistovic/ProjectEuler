/*
 Problem 4
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <string.h>

int is_palindrome_s(int x);
int is_palindrome(int n);

int main() {
	int i, j, p, max;
    
	for (i = 999; i > 99; i--)
		for (j = i; j > 99; j--) {
			p = i * j;
			if (p > max && is_palindrome(p))
				max = p;
		}

	printf("%d\n", max);

	return 0;
}

int is_palindrome(int n) {
	int tmp = 0, num = n;
    
	while (n) {
		tmp = tmp * 10 + n % 10;
		n /= 10;
	}
    
	if (tmp == num)
		return 1;
	else
		return 0;
}

// string variant, alot slower but still interesting
int is_palindrome_s(int x) {
	int l, i = 0;
	char s[6];
    
	sprintf(s, "%d", x);
	l = strlen(s) / 2;
    
	while (i < l) {
		if (s[i] != s[l-1-i])
			return 0;
		i++;
	}
    
	return 1;
}

/*
 Solution:
 906609
 
 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/ 