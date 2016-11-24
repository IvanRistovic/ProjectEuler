# Problem 4
# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
#
# Find the largest palindrome made from the product of two 3-digit numbers.

def is_palindrome(n):
	reverse = 0
	number = n

	while number > 0:
		reverse = reverse * 10 + number % 10
		number /= 10

	if n == reverse:
		return True
	else:
		return False

max_palindrome = 0
for i in range(999, 100, -1):
	for j in range(999, 100, -1):
		current = i*j
		if current > max_palindrome and is_palindrome(current):
			max_palindrome = current

print max_palindrome

# Solution:
# 906609
