import math

line = input().split()
a = int(line[0])
b = int(line[1])
c = int(line[2])
d = int(line[3])

s = (a + b + c + d) / 2;

print(math.sqrt((s - a) * (s - b) * (s - c) * (s - d)))
