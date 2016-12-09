# Problem 22
# Using names.txt, a 46K text file containing over five-thousand first names,
# begin by sorting it into alphabetical order. Then working out the alphabetical
# value for each name, multiply this value by its alphabetical position in the
# list to obtain a name score.
#
# For example, when the list is sorted into alphabetical order, COLIN, which is
# worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
# would obtain a score of 938 x 53 = 49714.
#
# What is the total of all the name scores in the file?

def score(name, mul_factor):
	s = 0
	for letter in name:
		s += ord(letter) - ord('@')		# '@' is before 'A' in ASCII table
	return s * mul_factor

import re

try:
	with open("../_txt/0022.txt", "r") as f:
		content = f.read()
except IOError:
	exit("missing file: _txt/0022.txt")

# processing file content, extracting names
names = []
r = re.compile(r"\"(?P<name>[A-Z]+)\"")
for m in r.finditer(content):
	names.append(m.group("name"))

# sorting
names.sort()

# evaluating score sum
score_sum = 0
mul_factor = 1
for name in names:
	score_sum += score(name, mul_factor)
	mul_factor += 1

print score_sum

# Solution:
# 871198282
# real	0m0.054s
# user	0m0.032s
# sys	0m0.012s
