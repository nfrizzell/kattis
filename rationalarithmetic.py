def euclid(a, b):
	if a == 0:
		return b

	return euclid(b % a, a)

cases = int(input())
for i in range(cases):
	line = input().split(" ")
	x1 = int(line[0])
	y1 = int(line[1])
	op = line[2]
	x2 = int(line[3])
	y2 = int(line[4])

	num = 0
	den = 0
	if (op == '+'):
		num = (x1 * y2) + (x2 * y1)
		den = y1 * y2

	elif (op == '-'):
		num = (x1 * y2) - (x2 * y1)
		den = y1 * y2

	elif (op == '*'):
		num = x1 * x2
		den = y1 * y2

	else:
		num = x1 * y2
		den = y1 * x2
		
	gcf = euclid(abs(num), abs(den))
	num //= gcf
	den //= gcf

	if den < 0:
		den *= -1
		num *= -1

	print(f"{num} / {den}")
