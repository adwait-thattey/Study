T = int(input())

while T>0 :
	T-=1
	N = input()
	Arr = input().split()
	E = list()

	for i in Arr:
		for j in i:
			E.append(j)


	while True :
		try :
			M = max(E)
			E.remove(M)
			print(M,end="")
		except (TypeError,ValueError) as ERR :
			break 
	print()
	