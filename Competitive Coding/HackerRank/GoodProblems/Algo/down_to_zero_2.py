"""
This a Dynamic Programming problem
There are Q queries.
Limit of N is 10^6 So generate the answer for each N at the start, then answer each query in constant time

When we generate answer successfully for a number, multiply that number with each preceding number and generate answer for the multiplication
"""
INF = 999999
def gen_answers(limit):

    arr = [INF]*limit

    arr[0] = 0
    arr[1] = 1
    arr[2] = 2

    for ix in range(2, limit):
        arr[ix] = min(arr[ix],arr[ix-1] + 1)


        for jx in range(2, ix+1):
            px = ix*jx # product index
            if  px >= len(arr):
                break
            arr[px] = min(arr[px], arr[ix] + 1)

    return arr

if __name__ == "__main__":
    arr = gen_answers(1000000)
    # print(arr)
    Q = int(input())
    for _ in range(Q):
        n = int(input())
        print(arr[n])