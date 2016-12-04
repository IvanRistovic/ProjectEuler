# Problem 9
# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
# a^2 + b^2 = c^2
# For example, 32 + 42 = 9 + 16 = 25 = 52.
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

for a in range(1, 500):
	for b in range(a, 500):
		c = 1000 - a - b
		if a*a + b*b == c*c:
			print a*b*c
			exit()

# Solution:
# 31875000
# real	0m0.049s
# user	0m0.036s
# sys	0m0.008s
