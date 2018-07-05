def countUpper(S):
	count=0
	for i in S:
		if i.isupper() : count+=1

	return count


T = int(input().strip())

while T>0:
	T-=1
	line = input().split()
	N,K = int(line[0]),int(line[1])

	string = input()

	UP = countUpper(string)
	chef=brother=False
	if UP<=K :
		chef = True

	if N-UP<=K :
		brother=True

	if chef :
		if brother :
			print("both")

		else : print("chef")

	else :
		if brother :
			print("brother")
		else : print("none")			


