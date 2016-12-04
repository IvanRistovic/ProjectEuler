# Problem 10
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.

try:
	with open("../_txt/prime_list.txt", "r") as f:
		lines = f.readlines()
except IOError:
	exit("missing file: _txt/prime_list.txt")

s = 0
for line in lines:
	prime = int(line)
	if (prime < 2000000):
		s += prime
	else:
		break;

print s

# Solution:
# 142913828922
# real	0m0.157s
# user	0m0.140s
# sys	0m0.004s
