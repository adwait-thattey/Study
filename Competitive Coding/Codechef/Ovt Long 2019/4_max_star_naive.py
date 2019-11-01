"""
You are given a sequence A1,A2,…,AN. For each valid i, the star value of the element Ai is the number of valid indices j<i such that Aj is divisible by Ai.

Chef is a curious person, so he wants to know the maximum star value in the given sequence. Help him find it.

Input
The first line of the input contains a single integer T which denotes the number of test cases.
The first line of each test case contains a single integer N .
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer ― the maximum star value.

Constraints
1≤T≤10
1≤N≤105
1≤Ai≤106 for each valid i
Sum of N over all test cases does not exceed 100,000.
Subtasks
Subtask #1 (20 points): sum of N over all test cases does not exceed 5,000
Subtask #2 (80 points): original constraints

Example Input
1
7
8 1 28 4 2 6 7
Example Output
3
"""

T = int(input())
while T > 0:

    max_star = 0
    

    N = int(input())
    arr = [int(i) for i in input().split()]
    taken_arr = [False]*N
    # print(taken_arr)
    for ix in range(len(arr)-1, -1, -1):
        if max_star >= ix - 1:
            # can not get a max_start more than this
            break
        
        if arr[ix] == 1:
            max_star = ix-1
            break

        cur_star = 0
        if taken_arr[ix] is False:
            for xxx in range(0,ix):
                if arr[xxx]%arr[ix] == 0:
                    cur_star+=1
                    taken_arr[xxx] = True


        if cur_star > max_star:
            max_star = cur_star

        



    print(max_star)                     
    T-=1