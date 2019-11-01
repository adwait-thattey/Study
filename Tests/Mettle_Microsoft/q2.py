input1 = int(input())
input2 = [int(i) for i in input().split()]
marks_dict = dict()
duplicates = dict()

total = 0
for i in input2:
    total+=i
    if i in marks_dict:
        if i in duplicates:
            duplicates[i]+=1
        else:
            duplicates[i] = 1
    else:
        marks_dict[i] = True

for key in duplicates:
    for x in range(duplicates[key]):
        try_val = key+1
        while try_val in marks_dict:
            try_val+=1
        marks_dict[try_val] = True
        total+=(try_val-key)

print(total)            