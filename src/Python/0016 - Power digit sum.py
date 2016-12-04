# Problem 16
# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?

digit_sum = 0
number = str(2**1000)
for digit in number:
	digit_sum += int(digit)

print digit_sum

# Solution:
# 1366
# real	0m0.017s
# user	0m0.008s
# sys	0m0.004s
