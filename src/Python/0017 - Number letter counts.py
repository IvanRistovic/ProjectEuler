# Problem 17
# If the numbers 1 to 5 are written out in words: one, two, three, four, five,
# then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out
# in words, how many letters would be used?
#
# note: Do not count spaces or hyphens. For example, 342 (three hundred and
# forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
# letters. The use of "and" when writing out numbers is in compliance with
# British usage.

# ATTENTION this is so boring problem, so this is a copy-paste of C solution


AND = 3
HUNDRED = 7
ONETHOUSAND = 11

ones = [0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8]
tenths = [0, 3, 6, 6, 5, 5, 5, 7, 6, 6]
sum = 0

for i in range(1, 1000):
	a = i / 100;
	b = i / 10 % 10
	c = i % 10
	if a != 0:
		sum += ones[a] + HUNDRED
		if b != 0 or c != 0:
			sum += AND
	if b == 0 or b == 1:
		sum += ones[b * 10 + c]
	else:
		sum += tenths[b] + ones[c]

sum += ONETHOUSAND
print sum

# Solution:
# 21124
