# Problem 10
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.

try:
	with open("prime_list.txt", "r") as f:
		lines = f.readlines()
except IOError:
	exit("error: fopen error")

s = 0
for line in lines:
	s += int(line)

print s

# Solution:
# 142913828922
