pref = int(input())

criteria = {}
toppings = set()

for i in range(pref):
	line = input().split()
	if len(line) == 1:
		toppings.add(line[0])
	elif len(line) == 4:
		k = line[1]
		if tuple([k]) in criteria:
			criteria[tuple([k])].append(line[3])
		else:
			criteria[tuple([k])] = [line[3]]
	else:
		keys = []
		val = None
		t = line[2]
		idx = 1
		while (line[idx-1] != "then"):
			keys.append(line[idx])
			idx += 2
		val = line[-1]

		if t == "or":
			for k in keys:
				if tuple([k]) in criteria:
					criteria[tuple([k])].append(val)
				else:
					criteria[tuple([k])] = [val]
		elif t == "and":
			if tuple(keys) in criteria:
				criteria[tuple(keys)].append(val)
			else:
				criteria[tuple(keys)] = [val]
				
changes = True
while changes:
	changes = False
	for key in list(criteria):
		if len(key) == 1:
			if key[0] in toppings:
				for top in criteria[key]:
					toppings.add(top)
				changes = True
				criteria.pop(key)
		else:
			all_in = True
			for item in key:
				if item not in toppings:
					all_in = False
					break	
			if all_in:
				for top in criteria[key]:
					toppings.add(top)
				changes = True
				criteria.pop(key)

print(len(toppings))
