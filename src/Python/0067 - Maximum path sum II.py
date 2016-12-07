# Problem 67
# By starting at the top of the triangle below and moving to adjacent numbers on
#  the row below, the maximum total from top to bottom is 23.
#
# 3
# 7 4
# 2 4 6
# 8 5 9 3
#
# That is, 3 + 7 + 4 + 9 = 23.
#
# Find the maximum total from top to bottom in 0067.txt, a 15K text file
# containing a triangle with one-hundred rows.
#
# note: This is a much more difficult version of Problem 18. It is not possible
# to try every route to solve this problem, as there are 299 altogether! If you
# could check one trillion (1012) routes every second it would take over twenty
# billion years to check them all. There is an efficient algorithm to solve it.
# ;o)

try:
	with open("../_txt/0067.txt", "r") as f:
		content = f.readlines()
except IOError:
	exit("missing file: _txt/0067.txt")


triangle = []
for line in content:
	numbers = line.split(" ")
	row = []
	for number in numbers:
		row.append(int(number))
	triangle.append(row)


for i in range(len(triangle)-2, -1, -1):
	for j in range(0, i+1):
		triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])


print triangle[0][0]

# Solution:
# 7273
# real	0m0.036s
# user	0m0.016s
# sys	0m0.008s
