T = int(input())

while T>0:
	T-=1
	line = input().split()
	x = int(line[0])^int(line[1])
	y = int(line[2])^int(line[3])
	if x^y : print("NO")
	else : print("YES")