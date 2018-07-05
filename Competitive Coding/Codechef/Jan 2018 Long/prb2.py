T= int(input())
while T>0:
	T-=1
	N= int(input())
	Arr = list()

	for i in range(N):
		Arr.append([int(x) for x in input().split()])

	SUM = temp = max(Arr[N-1])
	for i in range(N-2,-1,-1):
		try:
			temp=max(j for j in Arr[i] if j<temp)
			SUM+=temp
		except ValueError:
			temp=-1
			print(-1)
			break

	if temp!=-1 : print(SUM)			