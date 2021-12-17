input()
correct = input()

aseq = "ABC"
bseq = "BABCBABCBABC"
gseq = "CCAABB"
adrian = 0
bruno = 0
goran = 0
for i in range(len(correct)):
	adrian += int(correct[i] == aseq[i % len(aseq)])
	bruno += int(correct[i] == bseq[i % len(bseq)])
	goran += int(correct[i] == gseq[i % len(gseq)])

winner = max(adrian, bruno, goran)
print(winner)
if (adrian == winner):
	print("Adrian")
if (bruno == winner):
	print("Bruno")
if (goran == winner):
	print("Goran")
