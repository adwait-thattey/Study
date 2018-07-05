
def equate_stacks(group) :
    while group[0]["height"] > 0 :
        group.sort(key=lambda x: x["height"] , reverse=True)
        
        while group[0]["height"] > group[1]["height"] :
            group[0]["height"] -= group[0]["stack"][group[0]["pos"]]
            group[0]["pos"]+=1

        while group[1]["height"] > group[2]["height"]:
            group[1]["height"] -= group[1]["stack"][group[1]["pos"]]
            group[1]["pos"]+=1

        if group[0]["height"] == group[1]["height"] and group[1]["height"]==group[2]["height"] :
            return group[0]["height"]

    else:
        return 0


n1, n2, n3 = [int(i) for i in input().split()]
stack1 = [int(i) for i in input().split()]
stack2 = [int(i) for i in input().split()]
stack3 = [int(i) for i in input().split()]
h1 = sum(stack1)
h2 = sum(stack2)
h3 = sum(stack3)

grp = list()
obj1 = dict()
obj1["height"] = h1
obj1["stack"] = stack1
obj1["pos"] = 0

obj2 = dict()
obj2["height"] = h2
obj2["stack"] = stack2
obj2["pos"] = 0

obj3 = dict()
obj3["height"] = h3
obj3["stack"] = stack3
obj3["pos"] = 0

grp.append(obj1)
grp.append(obj2)
grp.append(obj3)

ht = equate_stacks(grp)
print(ht)
