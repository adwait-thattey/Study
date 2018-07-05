n = [i for i in input()]
s = int(input())
count =0

import itertools
P = list(itertools.permutations(n))
P = list(set(P))
for i in P :
	i = "".join(i)
	if(int(i)>s) : count+=1

print(count)
