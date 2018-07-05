import math
T = int(input());

while T>0 :
	T-=1
	line = [int(i) for i in input().split()]
	N,K,S = line[0],line[1],line[2]
	if(S>=7) :
		days = (N*6)/K;
		if days<7 : 
			print("-1");
			continue;
	

	X = math.ceil(S*K/N)
	days = S - S//7
	if(X>days) : 
		print("-1")
		continue
	print(X)

		

