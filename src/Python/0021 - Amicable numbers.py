# Problem 21
# Let d(n) be defined as the sum of proper divisors of n (numbers less than n
# which divide evenly into n).
# If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
# each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
# 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
# 71 and 142; so d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.


def div_sum(number):
	s = 1
	i = 2
	while i*i < number:
		if number % i == 0:
			s += i + number/i
		i += 1

	if i*i == number:
		s += i

	return s


s = 0
i = 0
while i < 10000:
	tmp = div_sum(i)
	if tmp > i and div_sum(tmp) == i:
		s += i + tmp
	i += 1

print s

# Solution:
# 31626
# real 0m0.172s
# user 0m0.144s
# sys  0m0.020s
