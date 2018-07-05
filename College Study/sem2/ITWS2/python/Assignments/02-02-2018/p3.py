S = input("Enter String : ").split()

for i in range(len(S)) :
	if(len(S[i])==0) : continue
	print(S[i] , " : " , end = " ")
	count = 1
	for j in range(i+1,len(S)) :
		if(len(S[j])==0) : continue
		if(S[j]==S[i]) : 
			S[j]=""
			count+=1
	print(count)		

