#!/bin/python3

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

    max_blocks = len(stack1) -1 - stack1Pos

    # try to increase max_blocks by adding something from stack2, if exceeds remove from stack1

    stack2Pos = len(stack2) - 1

    while stack1Pos >=0:
        cur_sum += stack2[stack2Pos]

        if cur_sum > max_score:
            # try removing block from stack1
            if stack1Pos < len(stack1):
                cur_sum -= stack1[stack1Pos]

                if cur_sum > max_score:
                    # cant get more
                    break
                else:
                    # worked. max_blocks remains the same
                    stack1Pos +=1
                    max_blocks -=1
            else:
                break

        max_blocks +=1
        stack2Pos -=1

    
    return max_blocks


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