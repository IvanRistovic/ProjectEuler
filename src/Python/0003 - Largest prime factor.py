# Problem 3
# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143 ?

number = 600851475143
largest_pf = 1

i = 2
while i <= number:
	while number % i == 0:
		number /= i

	if i > largest_pf:
		largest_pf = i

	i += 1

print largest_pf

# Solution:
# 6857
# real	0m0.023s
# user	0m0.020s
# sys	0m0.004s
