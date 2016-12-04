# Problem 15
# Starting in the top left corner of a 2x2 grid, and only being able to move to
# the right and down, there are exactly 6 routes to the bottom right corner.
#
# How many such routes are there through a 20x20 grid?

def choose(n, k):
    p = 1
    for i in xrange(1, min(k, n - k) + 1):
        p *= n
        p //= i
        n -= 1
    return p

print choose(40, 20)

# Solution:
# 137846528820
# real	0m0.022s
# user	0m0.016s
# sys	0m0.000s
