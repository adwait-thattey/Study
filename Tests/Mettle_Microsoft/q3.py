
def blahblah(inorder, levelorder, height):
    print(inorder, levelorder, height)
    if not inorder:
        return 99999999

    if len(inorder) == 1:
        return 1

    temp_flag = False
    parent_index = 0    
    for x in levelorder:
        for ix in range(len(inorder)):
            if inorder[ix] == x:
                parent_index = ix
                temp_flag = True
                break
        if temp_flag:
            break
    
    print("parent_index", parent_index)
    left_inorder = inorder[:parent_index]
    right_inorder = inorder[parent_index+1:]

    min_height = min( blahblah(left_inorder, levelorder, height), blahblah(right_inorder, levelorder, height))

    height = min_height + 1
    return height

io = [int(i) for i in input().split()]
lo = [int(i) for i in input().split()]

print(blahblah(io, lo, 0))          