T = int(input())

while T>0 :
	T-=1
	line = [int(i) for i in input().split()]
	K,d0,d1 = line[0],line[1],line[2]
	K-=2
	S = d0 + d1
	mod = S%10
	ans = S%3
	while(K>0) :
		K-=1
		ans = (ans + mod)%3
		mod = (2*mod)%10
		if(mod==0) :
			break
		if(mod==2 and K>=4) :
			temp = K//4
			ans = (ans + temp*2)%3
			K-=(4*temp)
			mod = 2

	if(ans%3==0) :
		print("YES")
	
	else :
		print("NO") 
