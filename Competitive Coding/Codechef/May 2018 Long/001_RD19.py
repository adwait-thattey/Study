T = int(input())
while T>0 :
    T-=1
    N = input()
    Arr = [int(i) for i in input().split()]
    i=0
    pre_length = len(Arr)
    while i<len(Arr) :
        j=i+1
        while j<len(Arr) :
            if (Arr[j]%Arr[i])==0 :
                del(Arr[j])
                j-=1
            j+=1
        i+=1

    #print(Arr)
    deleted = pre_length - len(Arr)
    if(len(Arr))==1 :
        print(-1)
    else :
        print(deleted)            