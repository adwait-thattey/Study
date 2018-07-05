T = int(input())

while T>0 :
	T-=1
	line = input().split()
	N,K = int(line[0]),int(line[1])
	Arr = [int(x) for x in input().split()]
	
	Sum=0
	for i in range(N) :
		Sum+=Arr[i]

	if Sum<0:
		M = max(Arr)
		ind = Arr.index(M)
		tind=ind
		Sum=MSum=M
		while Sum>=MSum and tind>0 :
			MSum=Sum
			tind-=1
			Sum+=Arr[tind]

		tind=ind
		Sum=MSum
		while Sum>=MSum and tind<(len(Arr)-1) :
			MSum=Sum
			tind+=1
			Sum+=Arr[tind]
	

		print(MSum)
		continue


	start,end=0,N-1
	mSumL,Sum,mSumi=Arr[0],Arr[0],0
	for i in range(1,N):
		Sum+=Arr[i]
		if Sum>mSumL :
			mSumL=Sum
			mSumi=i

	end = mSumi
	mSumR,Sum,mSumi=Arr[N-1],Arr[N-1],N-1

	for i in range(N-2,-1,-1):
		Sum+=Arr[i]
		if Sum>mSumR :
			mSumR=Sum
			mSumi=i

	start = mSumi


	
	if K==1 :
		Sum=0
		for i in range(start,end+1) :
			Sum+=Arr[i]
		print (Sum)
		continue

	elif K==2 :
		print (mSumR+mSumL)
		continue

	elif K>2 :
		Sum=0
		for i in range(N) :
			Sum+=Arr[i]
		Sum*=K-2
		Sum+=mSumR+mSumL
		print (Sum)
		continue	





