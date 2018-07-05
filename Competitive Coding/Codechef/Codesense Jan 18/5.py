T = int(input())

while T>0 :
	T-=1
	road = input()
	cars = list()
	auto = list()
	
	for ix in range(len(road)) :
		if road[ix]=='c' : cars.append(ix+1)
		elif road[ix]=='a' : auto.append(ix+1)

	L = len(road)
	count=0
	while L>0 :
		L-=1
		cars = [i for i in cars if i<L]
		for i in cars:
			if i in auto : count+=1
			if i+1 in auto : 
				if i+1<L :
					count+=1
		cars = [i+1 for i in cars]

	print(count//2 + count%2)	
					


