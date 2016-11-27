import math

def is_prime(number):
	number_root = math.sqrt(number)
	i = 2
	while i <= number_root:
		if number % i == 0:
			return False
		i += 1
	return True


try:
	with open("prime_list.txt", "w") as f:
		f.write("2\n")
		i = 3
		while i < 2000000:
			if is_prime(i):
				f.write(str(i) + "\n")
			i += 1
except IOError:
	exit("error: fopen error")
