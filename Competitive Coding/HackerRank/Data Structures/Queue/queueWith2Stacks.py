"""
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each
 query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
Input Format

The first line contains a single integer, , denoting the number of queries.
Each line  of the  subsequent lines contains a single query in the form described in the problem
 statement above. All three queries start with an integer denoting the query , but only query  is 
 followed by an additional space-separated value, , denoting the value to be enqueued.

Output Format

For each query of type , print the value of the element at the front of the queue on a new line.


SOLUTION:
Maintain 2 stacks, 
for enque operation push into stack1
for deque, if stack2 is empty, pop all from stack1 and push into stack2
        return top of stack2
"""

STACK1 = list()
STACK2 = list()

def enqueue(x):
    global STACK1, STACK2

    STACK1.append(x)


def dequeue():
    global STACK1, STACK2

    if not STACK2:
        while STACK1:
            STACK2.append(STACK1.pop())

    return STACK2.pop()

def printTop():
    dequeued = dequeue()
    print(dequeued)
    STACK2.append(dequeued)


if __name__=="__main__":
    Q = int(input())
    for _ in range(Q):
        query = input().split()
        
        if query[0] == "1":
            # enqueue
            enqueue(int(query[1]))

        elif query[0] == "2":    
            dequeue()
        
        elif query[0] == "3":
            printTop()