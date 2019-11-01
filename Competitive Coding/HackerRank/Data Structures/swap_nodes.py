#!/bin/python3

import os
from collections import deque
import resource
import sys

# Will segfault without this line.


class Node:
    def __init__(self, data, left=None, right=None, height=1):
        self.data = data
        self.lt = left
        self.rt = right
        self.ht = height

def get_inorder(node, ioarr):
    stack = list()

    def push_cur_to_stack(cur_node):
        while cur_node:
            stack.append(cur_node)
            cur_node = cur_node.lt

    push_cur_to_stack(node)

    while stack:
        n = stack.pop()
        ioarr.append(n.data)
        if n.rt:
            push_cur_to_stack(n.rt)

def build_tree(indexes):
    root = Node(1)
    queue = deque()
    queue.append(root)    
    for arr in indexes:
        cur = queue.popleft()
        if arr[0] != -1:
            cur.lt = Node(arr[0], height=cur.ht+1)
            queue.append(cur.lt)
        if arr[1] != -1:
            cur.rt = Node(arr[1], height=cur.ht + 1)
            queue.append(cur.rt)
                
    return root

def swap_at_k(node, k, ht=1):
    queue = deque()
    queue.append(node)
    
    while queue:
        cur = queue.popleft()
        if cur.ht%k == 0:
            cur.lt, cur.rt = cur.rt,cur.lt

        if cur.lt:
            queue.append(cur.lt)
        if cur.rt:
            queue.append(cur.rt)        

def get_max_ht(root, ht=0):

    if root:
        max_ht = max(get_max_ht(root.lt, ht+1), get_max_ht(root.rt, ht+1))
        return max_ht
    else:
        return ht

def swapNodes(indexes, queries):
    print(indexes)
    print(queries)
    
    root = build_tree(indexes)
    ret_mat = list()

    for q in queries:
        swap_at_k(root, q)
        
        io = list()
        get_inorder(root, io)
        ret_mat.append(io)


    
    
    return ret_mat
    #
    # Write your code here.
    #

if __name__ == '__main__':
    N = int(input())
    indexes = list()
    for _ in range(N):
        indexes.append([int(i) for i in input().split()])
    
    Q = int(input())
    queries = list()
    for _ in range(Q):
        queries.append(int(input()))
        
    #print(indexes, queries)
    
    mat = swapNodes(indexes, queries)
    
    for l in mat:
        print(" ".join([str(x) for x in l]))
