"""
"It's totally fun to play troublemakers ― totally." - Lee Pace

Sakshi had a matrix with N rows (numbered 1 through N) and M columns (numbered 1 through M). Initially, all cells of this matrix contained 0-s. Let's denote a cell in row r and column c by (r,c).

Sakshi is well-known for troubling others. This time, her friends Nikki and Mansi planned to take revenge and teach her a lesson, so they changed her matrix by performing the following operation Q times:

Choose any valid cell (x,y).
Add 1 to all the cells in row x.
Add 1 to all the cells in column y.
For each valid i, the cell chosen in the i-th operation was (Xi,Yi). Nikki and Mansi challenged Sakshi to find the number of cells in the resulting matrix which contain odd integers. Sakshi is not good at math, since she has spent all her life troubling others, so this time, she really needs your help. Help Sakshi find the answer.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and Q.
Q lines follow. For each i (1≤i≤Q), the i-th of these lines contains two space-separated integers Xi and Yi.
Output
For each test case, print a single line containing one integer ― the number of cells with odd values.

Constraints
1≤T≤300
1≤N,M,Q≤105
1≤Xi≤N for each valid i
1≤Yi≤M for each valid i
the sum of N over all test cases does not exceed 3⋅105
the sum of M over all test cases does not exceed 3⋅105
the sum of Q over all test cases does not exceed 3⋅105
Subtasks
Subtask #1 (40 points):

1≤N,M,Q≤300
Subtask #2 (40 points):

1≤T≤3
1≤N⋅M≤106
1≤Q≤105
Subtask #3 (20 points): original constraints

Example Input
1
2 2 3
1 1
1 2
2 1
Example Output
2
Explanation
Example case 1: After applying the first operation, the matrix becomes:

2 1
1 0
After applying the second operation, it becomes:

3 3
1 1
Finally, after applying the third operation, it becomes:

4 3
3 2
"""

T = int(input())
while T > 0:

    N,M,Q = map(int, input().split())
    row_odd_dict = dict()
    col_odd_dict = dict()
    total_odd_cells = 0
    for _ in range(Q):
        i, j = [int(k) for k in input().split()]
        
        col_true_count = len(col_odd_dict)
        
        if i in row_odd_dict:
            # subtract
            to_subtract = M - 2*col_true_count
            total_odd_cells -= to_subtract
            del(row_odd_dict[i])
        else:
            #add
            to_add = M - 2*col_true_count
            total_odd_cells += to_add
            row_odd_dict[i] = True


        row_true_count = len(row_odd_dict)

        if j in col_odd_dict:
            # subtract
            to_subtract = N - 2*row_true_count
            total_odd_cells -= to_subtract
            del(col_odd_dict[j])
        else:
            to_add = N - 2*row_true_count
            total_odd_cells += to_add
            col_odd_dict[j] = True    

    print(total_odd_cells)
    
    T-=1

