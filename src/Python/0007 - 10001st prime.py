# Problem 7
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
# that the 6th prime is 13.
#
# What is the 10001st prime number?

i = 0
try:
	with open("../_txt/prime_list.txt", "r") as f:
		while i < 10001:
			line = f.readline();
			i += 1
except IOError:
	exit("missing file: _txt/prime_list.txt")

print line,

# Solution:
# 104743
# real	0m0.024s
# user	0m0.016s
# sys	0m0.004s
