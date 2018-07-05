T = int(input())
while T>0 :
	T-=1
	N = input()
	Arr = [int(i) for i in input().split()]
	oc = 0
	ec = 0
	for i in Arr :
		if(i%2) :
			oc+=1
		else :
			ec+=1	

	rem = 0

	if(oc==0) :
		pass
	elif(oc%2) :
		ec+=1
		oc = 1
	else :
		ec+=1
		oc = 0

	if(ec==0) :
		pass
	else:
		ec = 1

	rem = ec + oc

	print(rem)
					