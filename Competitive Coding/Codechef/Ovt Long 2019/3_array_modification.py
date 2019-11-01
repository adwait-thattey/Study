"""
Chef is really interested in the XOR operation. He wants to take a sequence A0,A1,…,AN−1 and for each i from 0 to K−1 inclusive (in this order, one by one), perform the following operation:

Let's denote a=Ai%N and b=AN−(i%N)−1 before this operation.
Change Ai%N to a⊕b, i.e. a XOR b.
Since Chef is busy, he asked you to find the final sequence he should get after performing these operations.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A0,A1,…,AN−1.
Output
For each test case, print a single line containing N space-separated integers ― the elements of the final sequence.

Constraints
1≤T≤70
1≤N≤104
1≤K≤1012
1≤Ai≤107 for each valid i
Subtasks
Subtask #1 (30 points): 1≤K≤106
Subtask #2 (70 points): original constraints

Example Input
1
2 2
1 2
Example Output
3 1
"""

T = int(input())
while T>0:

    N,K = [int(i) for i in input().split()]

    arr = [int(i) for i in input().split()]

    if K > N and N%2:
        arr[N//2] = 0
    
    K = K%(3*N)
    
    out_arr = arr
    
    if K > (2*N):
        out_arr = arr[::-1]
        idx = len(out_arr)//2
        while idx < N:
            out_arr[idx] = out_arr[idx] ^ arr[idx]
            idx+=1
        K-= 2*N

    elif K > N:
        out_arr = arr[::-1]
        idx = 0
        while idx < len(out_arr)//2:
            out_arr[idx] = out_arr[idx] ^ arr[idx]
            idx+=1
        K -= N

    for xx in range(K):
        out_arr[xx] = out_arr[xx] ^ out_arr[N - 1 - xx ]

    # for i in range(K):
    #     arr[i%N] = arr[i%N] ^ arr[N - 1 - (i%N)]

    # out_arr = arr
    [print(x, end=" ") for x in out_arr]
    print()
    T-=1