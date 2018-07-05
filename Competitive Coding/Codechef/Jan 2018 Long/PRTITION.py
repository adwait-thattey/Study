line = input().split();
X,N = int(line[0]),int(line[1]);

S1,S2=0,0;

for i in range(1,N+1):
	if i==X : continue
	if(i%2):
		S1+=i
	if(i%2==0):
		S2+=i

changed = list()

diff = abs(S1-S2)//2
if abs(S1-S2)%2 :
	if S1>S2 :
		if X!=1 : 
			changed.append(1)
			S1-=1
			S2+=1
		else : 
			changed.append(3)
			changed.append(2)
			S1-=1
			S2+=1
	else : 
		if X!=1 and X!=2 :
			changed.append(1)
			changed.append(2)
			S1+=1
			S2-=1
		else :
			changed.append(3)
			changed.append(4)
			S1+=1
			S2-=1	






	while S1>S2:
		try:
			temp = max([i for i in range(1,diff+1,2) if i!=X and i not in changed])
			changed.append(i)
			diff-=temp
			S1-=temp
			S2+=temp
		except ValueError:
			try :
				if diff%2: 
					temp = min([i for i in range(diff,N+1,2) if i!=X and i not in changed])
				else : 
					temp = min([i for i in range(diff+1,N+1,2) if i!=X and i not in changed])
				changed.append(i)
				diff-=temp
				diff = abs(diff)
				S1-=temp
				S2+=temp
			except ValueError:
				print("impossible")
				break

	while S2>S1:
		try:
			temp = max([i for i in range(2,diff+1,2) if i!=X and i not in changed])
			changed.append(i)
			diff-=temp
			S1-=temp
			S2+=temp
		except ValueError:
			try :
				if diff%2: 
					temp = min([i for i in range(diff+1,N+1,2) if i!=X and i not in changed])
				else : 
					temp = min([i for i in range(diff,N+1,2) if i!=X and i not in changed])	
				changed.append(i)
				diff-=temp
				diff = abs(diff)
				S1-=temp
				S2+=temp
			except ValueError:
				print("impossible")
				break

		

print(S1,S2);			

