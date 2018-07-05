T = int(input())
while(T>0) :
    N = int(input())
    T-=1
    Arr = [int(i) for i in input().split()]
    if N==1 :
        print(Arr[0])
        continue
    Arr2 = [0]*(N**2)
    # print(Arr)
    # print(Arr2)
    for i in range(N) :
        for j in range(N) :
            #print(i,j)
            Arr2[((i-1)*N + j - 1)] = Arr[i+1-1] + Arr[j+1-1] 

    Num = Arr2[0]
    for i in Arr2[1:] :
        Num = Num^i

    # print(Arr)
    # print(Arr2)
    print(Num)        
