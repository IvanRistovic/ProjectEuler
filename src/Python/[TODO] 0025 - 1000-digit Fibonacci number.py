
f1 = 1
f2 = 2
ind = 2
while len(str(f1)) < 1000:
	f1, f2 = f2, f1 + f2
	ind += 1

print ind
