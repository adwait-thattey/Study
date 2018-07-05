def lexisort(S):
    Q = 9
    while Q < S:
        Q = 10 * Q + 9 

    return S / Q

N = int(input())
Arr = [int(i) for i in input().split()]
Arr = sorted(Arr, key=lexisort, reverse=True)
for i in Arr :
	print(i,end="")
