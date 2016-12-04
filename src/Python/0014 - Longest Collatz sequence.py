# Problem 14
# The following iterative sequence is defined for the set of positive integers:
#
# n -> n/2 (n is even)
# n -> 3n + 1 (n is odd)
#
# Using the rule above and starting with 13, we generate the following sequence:
#
# 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
# It can be seen that this sequence (starting at 13 and finishing at 1) contains
# 10 terms. Although it has not been proved yet (Collatz Problem), it is
# thought that all starting numbers finish at 1.
#
# Which starting number, under one million, produces the longest chain?
#
# note: Once the chain starts the terms are allowed to go above one million.


# i will save all the calculated chain lengths in this map
cache = {}
cache[1] = 1

def collatz(number):
	chain_len = 1

	n = number
	while n != 1 and n >= number:
		if n % 2 == 0:
			n /= 2
		else:
			n = 3*n + 1
		chain_len += 1

	cache[number] = chain_len + cache[n]

	return cache[number]

max_chain = 0
max_i = 0
i = 2
while i < 1000000:
	current_chain = collatz(i)
	if current_chain > max_chain:
		max_chain = current_chain
		max_i = i
	i += 1

print max_i

# Solution:
# 837799
# real	0m2.182s
# user	0m2.052s
# sys	0m0.088s
