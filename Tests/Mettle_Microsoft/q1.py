n = int(input())
l = [int(i) for i in input().split()]
count_dict = dict()
for i in l:
    if i in count_dict:
        count_dict[i]+=1
    else:
        count_dict[i] = 1

num = [i for i in count_dict.keys() if count_dict[i] > n/2]
if num:
    print(num[0])
else:
    print(-1)             