# Problem 11
# In the 20x20 grid below, four numbers along a diagonal line have been marked.
# (check 0011.txt)
# The product of these numbers is 26 x 63 x 78 x 14 = 1788696.
#
# What is the greatest product of four adjacent numbers in the same direction
# (up, down, left, right, or diagonally) in the 20x20 grid?

try:
	with open("0011.txt", "r") as f:
		lines = f.readlines()
except IOError:
	exit("error: fopen error")

# forming matrix
matrix = []
for i in range(1, 3):
	matrix.append(["01"]*26)
for line in lines:
	matrix.append(["01"]*3 + line.split(" ") + ["01"]*3)
for i in range(1, 3):
	matrix.append(["01"]*26)

# calculating
maxpr = 1
for i in range(2, 22):
	for j in range(3, 23):
		pr = 1
		for k in range(0, 4):
			pr *= int(matrix[i][j-k])
		if pr > maxpr:
			maxpr = pr
		pr = 1
		for k in range(0, 4):
			pr *= int(matrix[i-k][j])
		if pr > maxpr:
			maxpr = pr
		pr = 1
		for k in range(0, 4):
			pr *= int(matrix[i-k][j-k])
		if pr > maxpr:
			maxpr = pr
		pr = 1
		for k in range(0, 4):
			pr *= int(matrix[i-k][j+k])
		if pr > maxpr:
			maxpr = pr

print maxpr

# Solution:
# 70600674
