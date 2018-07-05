T = int(input())
while T>0 :
	T-=1
	line = input().split()
	N,M = int(line[0]),int(line[1])
	S1 = list(input())
	S2 = list(input())

	count=1
	id1,id2,curch=1,0,S1[0]
	for i in range(N+M) :
		if id1<N and S1[id1]==curch :
			#print("S1-" + curch + "-" +  str(id1))
			id1+=1
			continue;
		elif id2<M and S2[id2]==curch :
			#print("S2-" + curch + "-" +  str(id1))
			id2+=1
			continue;

		else :
		 count+=1
		 if id1<N :
		 	curch = S1[id1]
		 	#print("S1-" + curch + "-" + str(id1))
		 	id1+=1
		 elif id2<M :
		 	curch = S2[id2]
		 	#print("S2-" + curch + "-" + str(id1))
		 	id2+=1	

	print(count)
