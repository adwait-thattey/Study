#!/usr/bin/python3

def countSortRadix(Arr , radix) :
    count = [0]*10
    sortedArray = [0]*len(Arr)
    
    for i in Arr :
        i//=(10**(radix-1))
        count[i%10]+=1

    for i in range(1,len(count)) : count[i]+=count[i-1]  
    for i in Arr[::-1] :
        j = i//(10**(radix-1))
        j%=10
        index = count[j]-1
        sortedArray[index] = i
        count[j]-=1

    return sortedArray        


print("Enter Array :")
Array = [int(i) for i in input().split()]
MAX = max(Array)
start = 1
while(MAX>0) :
    Array = countSortRadix(Array, start)
    start+=1
    MAX/=10
print(Array)
