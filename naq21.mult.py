n = int(input())
mult = True
base = -1
for i in range(n):
	test = int(input())
	if mult:
		base = test
		mult = False
	elif test % base == 0:
		print(test)
		mult = True
