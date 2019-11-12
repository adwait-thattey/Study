#!/bin/python3
"""
A series of elements are given.
AT each step, print the median of the numbers encountered till then

If size of numbers is odd, median is float of middle element.
If size if even, median is the average of both middle elements
"""
import os
import sys
import heapq
#
# Complete the runningMedian function below.
#

class MaxHeap:
    def __init__(self, iterable=None):
        self.data = list()
        if iterable:
            self.data = [i*-1 for i in  iterable]

    def heapify(self):
        heapq.heapify(self.data)
    
    def push(self, data):
        data = data*-1
        heapq.heappush(self.data, data)
    
    def pop(self):
        return -1*heapq.heappop(self.data)
    
    def top(self):
        return -1*self.data[0] if self.data else None

    def __len__(self):
        return len(self.data)

    def __bool__(self):
        return bool(self.data)

class MinHeap:
    def __init__(self, iterable=None):
        self.data = list()
        if iterable:
            self.data = iterable

    def heapify(self):
        heapq.heapify(self.data)
    
    def push(self, data):
        heapq.heappush(self.data, data)
    
    def pop(self):
        return heapq.heappop(self.data)
    
    def __len__(self):
        return len(self.data)

    def __bool__(self):
        return bool(self.data)

    def top(self):
        return self.data[0] if self.data else None


def runningMedian(a):
    minhp = MinHeap()
    maxhp = MaxHeap()
    medians = list()
    for i in a:
        if minhp and minhp.top() <=i:
            minhp.push(i)
        else:
            maxhp.push(i)
        
        # balance heaps
        while len(maxhp) - len(minhp) > 1:
            minhp.push(maxhp.pop())
        while len(minhp) - len(maxhp) > 1:
            maxhp.push(minhp.pop())
        
        if len(minhp) > len(maxhp):
            # median is top of minheap
            medians.append(float(minhp.top()))
        elif len(maxhp) > len(minhp):
            # median is top of maxhp
            medians.append(float(maxhp.top()))
        else:
            # median is haplf of both tops
            medians.append((minhp.top() + maxhp.top())/2)

    return medians
    

if __name__ == '__main__':

    a_count = int(input())

    a = []

    for _ in range(a_count):
        a_item = int(input())
        a.append(a_item)

    result = runningMedian(a)


    for i in result:
        print(i)
