T = int(input())

def MMM(Arr) :
	MIN = Arr[0]
	for i in Arr :
		if i[2]<MIN[2] :
			MIN=i
	
	for i in Arr :
		if i[2]==MIN[2] :
			yield i
	

def rembet(Arr,D) :
	for i in Arr :
		if i[0]>=D[0] and i[0]<D[1] : Arr.remove(i)
		elif i[1]>D[0] and i[1]<=D[1] : Arr.remove(i)
		elif i[0]<=D[0] and i[1]>=D[1] : Arr.remove(i)

def perform(Arr,count) :
	mcount=count
	if len(Arr)==0 :
		return count
	temp = MMM(Arr)
	while True:		
		try :
			xxx = next(temp)
			Arr2 = list(Arr)
			Arr2.remove(xxx)
			rembet(Arr2,xxx)
			nnn = perform(Arr2,count+1)
			if nnn>mcount : mcount=nnn
		except StopIteration :
			return mcount	


while T>0 :
	T-=1
	N = input()
	line = [int(i) for i in input().split()]
	Arr = list()
	for ix in range(0,len(line),2) :
		Arr.append([line[ix],line[ix+1],line[ix+1]-line[ix]])
	count=0
	
	print(perform(Arr,0))	
		

