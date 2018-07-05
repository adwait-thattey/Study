N,K = [int(i) for i in input().split()]
Arr = [int(i) for i in input().split()]
func = list()
Arr.sort()
for i in range(len(Arr)) :
	for j in range(i,len(Arr)) :
		k = i
		MIN = XOR = Arr[k]
		if(i < j) :
			if(i in Arr[i+1:j]) :
				func.append(0)

		while(k<j) :
			k+=1
			if(Arr[k]<MIN) : MIN = Arr[k]
			XOR = XOR^Arr[k]
		func.append(MIN*XOR)
		if(len(func)==K) :
			print(func[K-1])
			exit()
#	print(func)
func.sort()
print(func[K-1])				
