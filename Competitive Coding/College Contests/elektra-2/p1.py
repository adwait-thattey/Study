N = int(input())
Arr = [int(i) for i in input().split()]
Arr.sort()

i = 0
precount = 0
midcount=0
postcount=0

while(i<N and Arr[i]==Arr[0]) :
	precount+=1
	i+=1
pos = i	
while(i<N and Arr[i]==Arr[0]+1) :
	midcount+=1
	i+=1
while(i<N and Arr[i]==Arr[0]+2) :
	postcount+=1
	i+=1	

M = precount+midcount+postcount

while(i<N) :
	temp = midcount
	midcount = postcount
	precunt = temp
	postcount = 0
	while(i<N and Arr[i]==Arr[pos]+1) :
		postcount+=1
		i+=1
	pos = i-1
	S = precount + midcount + postcount	
	if(S>M) :
		M = S	


print(M)