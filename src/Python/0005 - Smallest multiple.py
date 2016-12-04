# Problem 5
# 2520 is the smallest number that can be divided by each of the numbers from
# 1 to 10 without any remainder.
#
# What is the smallest positive number that is evenly divisible by all of the
# numbers from 1 to 20?

def is_divisible(number):
	for i in range(4, 20):	# since we know 2 and 3 divide number (init value)
		if number % i != 0:
			return False
	return True

# the smallest possible number that can be divisible by all the numbers from
# 1 to 20 is the product of all primes below 20
# consequently, the number that is the solutin has to have that product in it's
# factorisation, so it is natural that we use that as the increment value

number = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19
step = number
while not is_divisible(number):
	number += step

print number

# Solution:
# 232792560
# real	0m0.018s
# user	0m0.008s
# sys	0m0.004s
