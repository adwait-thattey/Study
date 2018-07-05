T = int(input())
while(T) :
	T-=1	
	N,M,X,K = [int(i) for i in input().split()]
	S = input()
	Wodd = S.count('O')
	Weve = S.count('E')
	Meve = M//2
	Modd = Meve + M%2

	if(X*Modd >= Wodd) :
		N-=Wodd

	else :	
		N-=X*Modd


	if(X*Meve >= Weve) :
		N-=Weve

	else :
		N-=X*Meve

	if(N>0) : print("no")

	else : print("yes")		