#!/usr/bin/python3

N,Q = input().split()
N = int(N)
Arr = list()
for i in range(N): Arr.append(list())
Q = int(Q)
lastAnswer=0
while True :
    q = [int(i) for i in input().split()]
    if(len(q)<=0) : break
    elif(q[0]==1) :
        Arr[(q[1]^lastAnswer)%N].append(q[2])
    elif(q[0]==2) :
        TArr = Arr[(q[1]^lastAnswer)%N]         
        pos = 0
        if(len(TArr)>0) :
            pos = q[2]%len(TArr)
        lastAnswer = TArr[pos]
        print(lastAnswer)
               
