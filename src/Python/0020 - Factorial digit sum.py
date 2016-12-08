# Problem 20
# n! means n x (n - 1) x ... x 3 x 2 x 1
#
# For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
#
# Find the sum of the digits in the number 100!

from math import factorial as fact

digits = str(fact(100))
s = 0
for digit in digits:
	s += int(digit)

print s

# Solution:
# 648
# real 0m0.019s
# user 0m0.008s
# sys  0m0.008s
