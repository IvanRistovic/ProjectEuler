# Problem 13
# Work out the first ten digits of the sum of the following one-hundred
# 50-digit numbers (see 0013.txt)

try:
	with open("0013.txt", "r") as f:
		lines = f.readlines();
except IOError:
	exit("error: fopen error")

sum = 0
for line in lines:
	sum += int(line)

print sum

# Solution:
# 5537376230390876637302048746832985971773659831892672
