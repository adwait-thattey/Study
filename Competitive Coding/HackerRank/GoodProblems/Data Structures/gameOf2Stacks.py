#!/bin/python3

"""
Solution:

First scan 1st stack till the end (or until you hit sum limit),
Then, try adding elements from second stack. If while adding, 
sum of all exceeds, max limit, try removing one element from 1st stack and se if you can get

Ex:
stack1: 10 3 8 6
stack2: 2 1 5 4 3 1 8
sum limit: 22

First scan elements of stack1 one by one. We can scan 3 elements without hitting limit
So currently max_blocks are 3 and scanned elements are 6, 8, 3
Now try scanning from stack 2
If we scan 8, we will hit limit. So scan 8 and remove from stack1 until we are within limit
If we remove 3 from scanned stack 1, we will be within limit
So scanned elements are 8,6 from 1st and 8 from 2nd. This is same as original max_blocks = 3

Now scan 1 from stack 2. We hit limit, so remove 8 from stack 1
Now elements are 6 from 1st and 8, 1 from 2nd. Sum = 14

We can scan 3 and 4 from 2 also. 
So scanned elements are 6 from 1st and 8,1,3,4 from 2nd. Sum=22, blocks=5. This is bigger that original 3, so keep max as 5

Now scan 5, we have to remove 6 from 1st. But then we can also scan 1 from 2nd
SO finally no elements from 1st, 8,1,3,4,5,1 from 2nd. Total = 6 blocks
This is max till now. So answer is 6
"""
def getMaxScore(stack1, stack2, max_score):
    # scan all elements of stack1 until max_score is hit
    cur_sum = 0
    
    stack1Pos = len(stack1) - 1

    while stack1Pos >=0:
        cur_sum += stack1[stack1Pos]
        if cur_sum > max_score:
            cur_sum -= stack1[stack1Pos]
            break

        stack1Pos -=1

    stack1Pos +=1
    max_blocks = len(stack1) - stack1Pos
    finalMaxBlocks = max_blocks
    # try to increase max_blocks by adding something from stack2, if exceeds remove from stack1

    stack2Pos = len(stack2) - 1

    while stack2Pos >=0:
        cur_sum += stack2[stack2Pos]

        while cur_sum > max_score and stack1Pos < len(stack1):
            cur_sum -= stack1[stack1Pos]
            stack1Pos +=1
            max_blocks -=1
        
        if cur_sum > max_score:
            cur_sum -= stack2[stack2Pos]
            break

        max_blocks +=1
        stack2Pos -=1

        finalMaxBlocks = max(finalMaxBlocks, max_blocks)
    
    return max(max_blocks, finalMaxBlocks)


if __name__ == "__main__":
    g = int(input())

    while g > 0:
        g-=1

        n,m,x = [int(i) for i in input().split()]
        stack1 = [int(i) for i in input().split()]
        stack2 = [int(i) for i in input().split()]        
        stack1 = stack1[::-1]
        stack2 = stack2[::-1]
        max_blocks = getMaxScore(stack1, stack2, x)
        print(max_blocks)