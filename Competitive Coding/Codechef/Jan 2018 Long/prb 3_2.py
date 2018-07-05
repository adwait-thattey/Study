def genS(Arr,key):
	    sum=0
	    if key==1:
	            for i in Arr:
	                    yield sum+i
	                    sum+=i
	    else :
	            for i in Arr[::-1]:
	                    yield sum+i
	                    sum+=i
	
T = int(input())

while T>0 :
	T-=1
	line = input().split()
	N,K = int(line[0]),int(line[1])
	Arr = [int(x) for x in input().split()]

	if K==0 :
		print("0")
		continue


	elif sum(Arr)<=0 : K=1
	 
	elif K==2 :
		Sum = max(list(genS(Arr,1)))
		Sum+= max(list(genS(Arr,-1)))		
		print(Sum)	
		continue

	elif K>2 :

		Sum = (K-2)*sum(Arr)
		Sum+= max(list(genS(Arr,1)))
		Sum+= max(list(genS(Arr,-1)))	
		print(Sum)	
		continue

	elif K==1 :
		maxNum = max(Arr)
		Si = Sitemp = Arr.index(maxNum)
		Sum = max(genS(Arr[Si:],1))
		Sum += max(genS(Arr[:Si],-1))

		maxSum=Sum

		while True:
			try :
				Si = Arr[Si+1:].index(maxNum)
				Sum = max(genS(Arr[Si:],1))
				Sum += max(genS(Arr[:Si],-1))
				if Sum>maxSum : maxSum=Sum

			except IndexError :
				break

			except ValueError :
				break

		print (maxSum)
		continue


