T = int(input())

while T>0 :
	T-=1
	N = input()
	Arr = [int(i) for i in input().split()]
	for i in range(len(Arr)) :
		if Arr[i]=='x' : continue
		temp = Arr[i]
		flag=0
		for j in range(i+1 , len(Arr)) :
			if Arr[j]==temp :
				Arr[j]='x'
				flag=1

		if flag==0 :
			print(Arr[i],end=" ")

	print()				


		
		

				
