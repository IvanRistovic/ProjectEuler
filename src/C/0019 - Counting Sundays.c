/*
 Problem 19
 You are given the following information, but you may prefer to do some
 research for yourself.

 1 Jan 1900 was a Monday.
 Thirty days has September,
 April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.

 A leap year occurs on any year evenly divisible by 4, but not on a century 
 unless it is divisible by 400.
 How many Sundays fell on the first of the month during the twentieth century
 (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>

int has_thirty_days(int n);
int leap(int y);

int main() {
	int weekday = 1;		// 1 - Monday, .. , 7 - Sunday
	int day = 1;
	int month = 1;
	int year = 1900;
	int count = 0;
	int leapind = 0, thirtydayind = 0;

	while (year < 2001) {

		if (weekday == 8)
			weekday = 1;
		if (month == 2) {
			if ((day == 29 && !leapind) || (day == 30 && leapind)) {
				day = 1;
				month++;
			}
		}
		else if ((day == 31 && thirtydayind) || (day == 32 && !thirtydayind)) {
			day = 1;
			month++;
		}

		if (month == 13) {
			month = 1;
			year++;
			leapind = leap(year);
		}
		thirtydayind = has_thirty_days(month);

		if (year > 1900 && weekday == 7 && day == 1)
			count++;

		day++; weekday++;
	}

	printf("%d\n", count);

	return 0;
}

int has_thirty_days(int n) {
	if (n == 2 || n == 4 || n == 6 || n == 9 || n == 11)
		return 1;
	else return 0;
}

int leap(int y) {
	return ((y%4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

/*
 Solution:
 171

 real 0m0.003s
 user 0m0.000s
 sys  0m0.000s
*/
