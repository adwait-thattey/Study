import sys
print()
for i in range(int(sys.argv[1]) , int(sys.argv[2]) + 1) :
	flag = 1
	for j in str(i) :
		if (int(j)%2) : 
			flag = 0
			break
	if(flag) : print(i , end = " ")