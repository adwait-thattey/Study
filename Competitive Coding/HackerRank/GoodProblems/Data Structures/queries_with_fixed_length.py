#!/bin/python3

import os
import sys
from collections import deque
# Complete the solve function below.

def solve(arr, queries):
    solution = list()
    for q in queries:
        max_set = set()
        cur_max = -1
        queue = deque(range(0,q))
        cur_max = max(queue, key=lambda x: arr[x])
        max_set.add(arr[cur_max])
        rt_pos = q
        while rt_pos < len(arr):
            popped = queue.popleft()
            queue.append(rt_pos)
            if arr[rt_pos] >= arr[cur_max]:
                cur_max = rt_pos
                max_set.add(arr[cur_max])
            if popped == cur_max:
                cur_max = max(queue, key=lambda x: arr[x])
                max_set.add(arr[cur_max])
            
            rt_pos+=1
        solution.append(min(max_set))

    return solution
    
if __name__ == '__main__':

    nq = input().split()

    n = int(nq[0])

    q = int(nq[1])

    arr = list(map(int, input().rstrip().split()))

    queries = []

    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)

    result = solve(arr, queries)

    print(('\n'.join(map(str, result))))

