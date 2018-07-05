T = int(input())

while(T) :
	T-=1
	S = input()
	S = list(S)
	S1 = list(S)
	L = len(S)

	S2 = list()

	for i in range(len(S)) :
		S2.append('.')

	pos = 0
	oddflag = 0
	exitflag = 0
	while(len(S)>0) :
		count = S.count(S[0])

		if(count%2) : 
			if(L%2 == 0) : 
				exitflag=1;
				break;

			if(oddflag) :
				exitflag=1;
				break;

			oddflag=1
			S2[L//2] = S[0]
			S.remove(S[0])
			continue;

		COUNT = count

		while(count>0) :
			S2[pos] = S[0]
			S2[L-1-pos] = S[0]
			pos+=1
			count-=2	
		
		temp = S[0]	
		for d in range(COUNT) :
			S.remove(temp)

		
	if(exitflag) :
		print("-1")
		continue			


	for i in S2 :
		ix = S1.index(i)
		S1.pop(ix)
		print(ix+count,end = " ")

	print()	