# 2 solutions
# solution 1

""" 
Trick for solving:

For each element, in array, prepare a list of all divisors of the number.
Increase count of each divisor in a dict by 1. 
Check the count of list elem in dict, if more than current max value, make max value as that.

The complexity of naive is N**2
Complexity of this algo is N**K (where K is each element of array). 
Even though, theoritically this is bigger (becoz K can go upto 10**6 and N only upto 10**5),
this special case rarely happens

"""
import math 
from functools import reduce

def printDivisors(n):    
    return list(set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
for _ in range(int(input())):
    N=int(input())
    List=[int(y) for y in input().split()]
    Dict=dict()
    Answ=0
    for i in range(N):
        Divisor_List=printDivisors(List[i])
        if List[i] in Dict:
            if(Dict[List[i]]>Answ):
                Answ=Dict[List[i]]
        for i in Divisor_List:
            if i in Dict:
                Dict[i]+=1
            else:
                Dict[i]=1
    print(Answ)

