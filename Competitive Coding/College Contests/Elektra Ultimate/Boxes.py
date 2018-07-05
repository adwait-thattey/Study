N = int(input())
boxes = list()
while N>0 :
    N-=1
    T = [int(i) for i in input().split()]
    boxes.append(T)

boxes.sort(key = lambda x: x[1] , reverse=True)
boxes.sort(key=lambda x: x[0], reverse=True)
boxes.sort(key=lambda x: x[2]*x[1]*x[0], reverse=True)
for x in boxes :
    print(x[0],x[1],x[2])
