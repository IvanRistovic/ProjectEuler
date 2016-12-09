# Problem 19
# You are given the following information, but you may prefer to do some
# research for yourself.
#
# 1 Jan 1900 was a Monday.
# Thirty days has September,
# April, June and November.
# All the rest have thirty-one,
# Saving February alone,
# Which has twenty-eight, rain or shine.
# And on leap years, twenty-nine.
#
# A leap year occurs on any year evenly divisible by 4, but not on a century
# unless it is divisible by 400.
# How many Sundays fell on the first of the month during the twentieth century
# (1 Jan 1901 to 31 Dec 2000)?

# copy-pasted C solution, since it is a boring problem for me

def has_thirty_days(n):
	if n == 2 or n == 4 or n == 6 or n == 9 or n == 11:
		return True
	else:
		return False

def leap(y):
	return ((y%4 == 0) and (y % 100 != 0)) or (y % 400 == 0)


weekday = 1		# 1 - Monday, .. , 7 - Sunday
day = 1
month = 1
year = 1900
count = 0
leapind = False
thirtydayind = False

while year < 2001:
	if weekday == 8:
		weekday = 1
	if month == 2:
		if (day == 29 and not leapind) or (day == 30 and leapind):
			day = 1
			month += 1
	elif (day == 31 and thirtydayind) or (day == 32 and not thirtydayind):
		day = 1
		month += 1

	if month == 13:
		month = 1
		year += 1
		leapind = leap(year)

	thirtydayind = has_thirty_days(month)

	if year > 1900 and weekday == 7 and day == 1:
		count += 1

	day += 1
	weekday += 1

print count


# Solution:
# 171
# real	0m0.068s
# user	0m0.056s
# sys	0m0.008s
