#!/bin/python3

import os
import sys
import heapq
import math

# Complete the minimumAverage function below.
#

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
    

    def top(self):
        return self.data[0] if self.data else None
    
    def add_to_all(self, amount):
        self.data = [d+amount for d in self.data]

    def __len__(self):
        return len(self.data)

    def __bool__(self):
        return bool(self.data)

class TimePizzaPair:
    def __init__(self, t, p):
        self.time = t
        self.pizza = p
    
    def __gt__(self, value):
        return (self.pizza - self.time) > (value.pizza - value.time)
    
    def __lt__(self, value):
        return (self.pizza - self.time) < (value.pizza - value.time)



def minimumAverage(customers):
    #
    # Write your code here.
    #
    customers.sort(key=lambda x: x[0])
    minhp = MinHeap()
    cur_time = 0
    waiting_times = list()
    cur_order = TimePizzaPair(math.inf,math.inf)
    started = -1
    cusix = 0
    while cusix < len(customers):
        cus = customers[cusix]
        cpair = TimePizzaPair(cus[0], cus[1])
        if cur_time < started + cur_order.pizza and cur_time < cpair.time:
            cur_time = min(started+cur_order.pizza, cpair.time)
        
        if cur_time >= cpair.time:
            minhp.push(cpair)
            cusix+=1

        if started == -1:
            if minhp:
                started = True
                cur_order = minhp.pop()
                started = cur_time
            
        elif (cur_time >= started + cur_order.pizza):
            time_taken = cur_time - cur_order.time
            waiting_times.append(time_taken)
            if minhp:
                cur_order = minhp.pop()
                started = cur_time
            else:
                cur_order = TimePizzaPair(math.inf, math.inf)
                started = -1

    
    # process remaining orders
    if started!=-1:
        cur_time = started + cur_order.pizza
        waiting_times.append(cur_time - cur_order.time)
    while minhp:
        cur_order = minhp.pop()
        cur_time += cur_order.pizza
        waiting_times.append(cur_time - cur_order.time)

    print(waiting_times)
    return sum(waiting_times)//len(waiting_times)

if __name__ == '__main__':
   
    n = int(input())

    customers = []

    for _ in range(n):
        customers.append(list(map(int, input().rstrip().split())))

    result = minimumAverage(customers)

    print(result)
