import math
levelOrder = [1,2,3,4,5,6,7,8,9]
inOrder = [2,4,8,7,9,6,3,5,1]

# levelOrder = [int(x) for x in input().split()]
# inOrder = [int(x) for x in input().split()]

def getMin( inOrder, levelOrder, count):

    if len(inOrder) == 1:
        return count
    if len(inOrder) == 0:
        return math.inf
    
    for x in levelOrder:
        if x in inOrder:
            root = x
            break
    i = inOrder.index(root)

    return min(getMin(inOrder[:i],levelOrder,count+1),getMin(inOrder[i+1:],levelOrder,count+1))

print(getMin(inOrder,levelOrder,1))