T = int(input())
while T>0 :
	T-=1
	N = input()
	Arr = [int(i) for i in input().split()]
	eveflag = oddflag = 0
	for i in range(len(Arr)) :
		if(Arr[i]%2==0) :
			Arr[i] = -1
			eveflag=1

	for i in range(len(Arr)) :
		for j in range(i+1,len(Arr)) :
			if(Arr[i]!= -1 and Arr[j]!=-1 and (Arr[i]+Arr[j])%2 == 0) : 
				print(Arr[i] , Arr[j])
				Arr[i] = Arr[j] = -1
				oddflag = 1
	print(Arr)				
	while True:
		try :
			Arr.remove(-1)
		except :
			break

	print(Arr)
			

