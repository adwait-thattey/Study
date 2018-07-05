def retIndex(SS,x) :
	lx = list()

	for i in range(len(SS)) :
		if(SS[i]==x) :
			lx.append(i)
			SS[i] = '.'

	return lx		

			


T = int(input())

while(T) :
	T-=1
	S = input()
	S = list(S)
	S1 = list(S)
	L = len(S)

	S2 = list()

	for i in range(len(S)) :
		S2.append(-1)

	pos = 0
	oddflag = 0
	exitflag = 0
	for i in range(len(S)) :
		if(S[i]=='.') : continue

		Lix = retIndex(S,S[i])
		count = len(Lix)

		if(count%2) : 
			if(L%2 == 0) : 
				exitflag=1;
				break;

			if(oddflag) :
				exitflag=1;
				break;

			oddflag=1
			S2[L//2] = Lix[0]
			Lix.pop(0)
			while(len(Lix)>0) :
				S2[pos] = Lix[0]
				S2[L-1-pos] = Lix[1]
				pos+=1
				Lix.pop(1)
				Lix.pop(0)
			continue;

		while(len(Lix) > 0) :
			S2[pos] = Lix[0]
			S2[L-1-pos] = Lix[1]
			Lix.pop(1)
			Lix.pop(0)
			pos+=1


		
	if(exitflag) :
		print("-1")
		continue			



	[print(ii + 1,end = " ") for ii in S2]
	print()	