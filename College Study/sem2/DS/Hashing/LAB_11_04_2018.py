
def hash(x,size) :
    return x%size

def new_hash(H,i,size) :
    return (H+i)%size


def get_length(S) :
    size = 0
    for i in S :
        size+=1
    return size    

def search_in_table(hash_table , x , size) :
    hash_value = hash(x,size)
    # print(hash_table)
    k=0
    pos = new_hash(hash_value,k,size)
    # print(x, pos)
    while(hash_table[pos]!=x) :
        if(hash_table[pos]==None) : break
        elif k>=size : break
        k+=1
        pos = new_hash(hash_value,k,size)
    else :
        return pos

    return -1   




def check_whether_string_in_table(hash_table , string , table_size) :
    for i in string :
        x = ord(i);
        pos = search_in_table(hash_table,x,table_size)
        if(pos==-1) : 
            #print(i)
            return False
    else : return True
            


testcases = int(input())
while(testcases > 0):
    testcases-=1
    word1 = input()
    word2 = input()
    word1_size = get_length(word1)
    word2_size = get_length(word2)
    hash_table_1 = [None]*word1_size
    hash_table_2 = [None]*word2_size
    
    print(hash_table_1)
    print(hash_table_2)
    
    for i in word1:
        hash_key = hash(ord(i), word1_size)
        pos = hash_key
        k = 0
        while(hash_table_1[pos] != None):
            k += 1
            pos = new_hash(hash_key, k, word1_size)

        hash_table_1[pos] = ord(i)
    
    for i in word2 :
        hash_key = hash(ord(i),word2_size)
        pos = hash_key
        k=0
        while(hash_table_2[pos]!=None) :
            k+=1
            pos = new_hash(hash_key,k, word2_size)
            
        hash_table_2[pos] = ord(i)

    # print(hash_table_1)
    # print(hash_table_2)

    flag1,flag2 = False,False
    if(check_whether_string_in_table(hash_table_2,word1,word2_size)) : flag1 = True 
    if(check_whether_string_in_table(hash_table_1,word2,word1_size)) : flag2 = True   

    # print(flag1,flag2)
    if(flag1) :
        if(flag2) :
            print("BOTH")
        else : print("ONLY 1st in 2nd")
    elif(flag2) : print("ONLY 2nd in 1st")
    else : print("NONE")                

