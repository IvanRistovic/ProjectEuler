# Problem 8
# The four adjacent digits in the 1000-digit number that have the greatest
# product are 9 * 9 * 8 * 9 = 5832.
# (check 0008.txt)
#
# Find the thirteen adjacent digits in the 1000-digit number that have the
# greatest product. What is the value of this product?

try:
	with open("../_txt/0008.txt", "r") as f:
		content = f.readline()
except IOError:
	exit("missing file: _txt/0008.txt")

max_pr = 1
for i in range(0, 987):
	pr = 1
	for j in range(0, 13):
		if content[i+j] == "0":
			i += j + 1
			break
		else:
			pr *= int(content[i+j])
	if j == 12 and pr > max_pr:
		max_pr = pr

print max_pr

# Solution:
# 23514624000
# real	0m0.027s
# user	0m0.016s
# sys	0m0.008s
