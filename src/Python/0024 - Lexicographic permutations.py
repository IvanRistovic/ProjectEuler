# Problem 24
# A permutation is an ordered arrangement of objects. For example, 3124 is one
# possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
# are listed numerically or alphabetically, we call it lexicographic order.
# The lexicographic permutations of 0, 1 and 2 are:
#
# 012   021   102   120   201   210
#
# What is the millionth lexicographic permutation of the digits
# 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

import itertools

print list(itertools.permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))[999999]

# Solution:
# 2783915460
# real	0m1.261s
# user	0m0.968s
# sys	0m0.236s
