# Problem 23
# A perfect number is a number for which the sum of its proper divisors is
# exactly equal to the number. For example, the sum of the proper divisors of
# 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#
# A number n is called deficient if the sum of its proper divisors is less than
# n and it is called abundant if this sum exceeds n.
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
# number that can be written as the sum of two abundant numbers is 24.
#
# By mathematical analysis, it can be shown that all integers greater than 28123
# can be written as the sum of two abundant numbers. However, this upper limit
# cannot be reduced any further by analysis even though it is known that the
# greatest number that cannot be expressed as the sum of two abundant numbers is
# less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum
# of two abundant numbers.


div_sum = [1] * 28124
for i in range(2, int(28123**.5)+1):
	div_sum[i*i] += i
	for k in range(i+1, 28123//i+1):
		div_sum[k*i] += k+i

abundant = set()
res = 0
add_to_abun_set = abundant.add

for n in range(1, 28124):
	if div_sum[n] > n:
		add_to_abun_set(n)
	if not any((n-a in abundant) for a in abundant):
		res += n

print res


# Solution:
# 4179871
# real 0m0.104s
# user 0m0.096s
# sys	0m0.000s
