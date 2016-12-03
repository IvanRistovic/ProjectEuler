# Problem 8
# The four adjacent digits in the 1000-digit number that have the greatest
# product are 9 * 9 * 8 * 9 = 5832.
# (check 0008.txt)
#
# Find the thirteen adjacent digits in the 1000-digit number that have the
# greatest product. What is the value of this product?

try:
	with open("0008.txt", "r") as f:
		content = f.readline()
except IOError:
	exit("error: fopen error")

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
