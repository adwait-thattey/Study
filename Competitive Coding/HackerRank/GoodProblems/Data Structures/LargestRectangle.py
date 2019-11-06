"""
There are 2 ways to solve this problem.
1 - Using divide and conquer 
        - gives O(nlogn) complexity average, 
        - may give O(n^2) in worst case if optimizations not done
        - Similar to quick sort

2 - Using stack 
        - gives O(n) even in worst case


Original generic problem derived from 
    - Largest Rectangle under histogram 
        - from Geeks for geeks
        - https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

Method 1: Divide and conquer

    - For a given array, the required area will be maximum of these possibilities
        - Area of array = len(arr)*min(arr)
        - Area of array to the left of min(arr) without min
        - Area of array to the right of min(arr) without min
    Steps 2 and 3 can be done recursively. At every step return max

    Pseudocode: 
        getArea(arr):
            minpos = get_pos_of_min_in_arr(arr)
            curArea = len(arr)*min(arr)
            return max(curArea, getArea(arr[:minpos]), getArea(arr[minpos+1:]))

    Finding the min takes n, best case, min is always in middle, total = nlogn
    Worst case, min always at start or end, total = n^2
    This can be optimized. We can use segment tree to get min, which requires only logn
    So best becomes (logn)*log(n) and worst becomes nlogn

    Segment Tree for range min query: https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/

Method 2: Using Stack

    The idea is to find, the possible area for each element if it were the min in the group

    Start from left, insert elements one by one into a stack.
    If new element to be pushed 
            - is greater than or equal to top of stack,
                    - simply push. no problem
            - is smaller than top, pop out all elements which are bigger than this. 
                For each popped element, the width limit will be from new_stack_top to here, where x is the popped element
                We take new stack top here, because the new stack top is the left limit to where the area for the popped element can go
            Example:
                                  |  
                                | |   | 
                            | | | | | | |
                            1 2 3 4 5 6 7 

                        Initially we push 1,2,3,4 to stack, now we encounter 5, which is smaller than the top
                        top=4, 5 is smaller than 4, pop 4. Width for area with 4 will be: 4 to 4 = 3*1 = 3
                        top=3 5 is smaller than 3, pop 3. Width for area with 3 will be 3 to 4 = 2*2 = 4
                        top=2 5 is not smaller than 2, so continue
                        Push 5
                        Push 6
                        top=6, 7 is smaller than 6, pop 6, width of area with 6 will be 6 to 6: 2*1 = 2
                        top=5, 7 is not smaller, continue
                        Push 7
                        End of array. So for each element in stack, width will be their position to end
                        for 7 : 1*1 = 1
                        for 5 : 3*1 = 3
                        for 2 : 6*2 = 6
                        for 1 : 7*1 = 7

                        So max we encountered till now is 7. So answer is 7 



""" 

# Method 1
def largestRectangleRecursion(harr):

    if len(harr) <=0:
        return -1
    elif len(harr) == 1:
        return harr[0]

    minpos = min(range(0,len(harr)), key=lambda k: harr[k])

    cur_area = len(harr)*harr[minpos]

    # leftARea = largestRectangleRecursion([])

    return max(cur_area, largestRectangleRecursion(harr[:minpos]), largestRectangleRecursion(harr[minpos+1:]))


def largestRectangleStack(harr):
    # print(harr)
    max_area = -99999
    
    stack = list()
    # push indexes into the stack, not the actual values

    for ix in range(len(harr)):
        

        if stack and harr[stack[-1]] > harr[ix]:
            #found smaller elem, start popping
            while stack and harr[stack[-1]] > harr[ix]:
                popped_ix = stack.pop()

                width = ix - stack[-1] - 1 if stack else ix
                area = width*harr[popped_ix]

                max_area = max(max_area, area)

        stack.append(ix)
    
    # get area for remaining elems in stack
    # print(stack)

    # leave the case where stack has only 1 element
    while stack:
        popped_ix = stack.pop()
        width = len(harr) - stack[-1] - 1 if stack else len(harr)
        area = width*harr[popped_ix]
        # print(width, harr[popped_ix], area)
        max_area = max(max_area, area)

    # now stack has only 1 element, which can encompass entire arr


    return max_area



def largestRectangle(h):
    return largestRectangleStack(h)


if __name__ == "__main__":
    n = int(input())
    harr = [int(i) for i in input().split()]

    print(largestRectangle(harr))