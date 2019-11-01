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
def get_nearest_low(found_elems, num):

    if not found_elems:
        return -1

    if found_elems[0] > num:
        return -1    

    nearest = 0
    lower = 0
    upper = len(found_elems) -1

    while upper > lower:
        mid = (upper - lower)//2

        if found_elems[mid] < num:
            lower = mid+1
            if lower > nearest:
                nearest = mid
                break
            nearest = lower
        elif found_elems[mid] > num:
            
            upper = mid -1
        else:
            nearest = mid
            break

    # print(found_elems[nearest])
    return nearest

def insert_into_seen(found_elems, num):
    for ix in range(len(found_elems)):
        if found_elems[ix] >= num:
            if found_elems[ix] == num:
                return
            found_elems.insert(ix,num)
            return

    found_elems.append(num)            

T = int(input())
while T > 0:

    found_elems = list()
    greater_dict = dict()
    max_star = 0
    

    N = int(input())
    arr = [int(i) for i in input().split()]

    for ix in range(len(arr)-1, -1, -1):

        if max_star >= ix - 1:
            # can not get a max_start more than this
            break
        
        if arr[ix] == 1:
            max_star = ix-1
            break
        
        low_idx = get_nearest_low(found_elems, arr[ix])
        positions_to_see = None
        if low_idx != -1:
            if found_elems[low_idx] == ix:
                break
            positions_to_see = [x for x in greater_dict[found_elems[low_idx]] if x < ix and arr[x] >= arr[ix]]
            greater_dict[arr[ix]] = positions_to_see

            cur_star = 0
            for xx in positions_to_see:
                if arr[xx]%arr[ix] == 0:
                    cur_star+=1

            if cur_star > max_star:
                max_star = cur_star       
        else:
            positions_to_see = list()
            cur_star = 0
            for k in range(ix):
                if arr[k] >= arr[ix]:
                    positions_to_see.append(k)
                    if arr[k] % arr[ix] == 0:
                        cur_star+=1

            if cur_star > max_star:
                max_star = cur_star

            greater_dict[arr[ix]] = positions_to_see

        if max_star >= ix - 2:
            # can not get a max_start more than this
            break


        insert_into_seen(found_elems, arr[ix])   

    print(max_star)                     
    T-=1