T = int(input())

while (T>0) :
	T-=1
	N = int(input())
	Arr = [float(i) for i in input().split()]
	C,D,S = [float(i) for i in input().split()]
	C = int(C)

	delay = max(Arr)
	print(float(delay*(C-1)))
	