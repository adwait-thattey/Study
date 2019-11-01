import math

gcds = list()
levels = int(input())
for l in range(levels+1):
    nodes = [int(i) for i in input().split()]
    x = 0
    while x+1 < len(nodes):
        if nodes[x] == -1 or nodes[x+1] == -1:
            pass
        else:
            gcds.append(math.gcd(nodes[x], nodes[x+1]))
        x+=2    

print(max(gcds) - min(gcds))
