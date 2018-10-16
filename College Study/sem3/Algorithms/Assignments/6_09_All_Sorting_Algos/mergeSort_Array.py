#!/usr/bin/python3

def merge(Arr1 , Arr2) :
    mergedList = list()
    i=j=0
    while(i<len(Arr1) and j<len(Arr2)) :
        if(Arr1[i]<Arr2[j]) :
            mergedList.append(Arr1[i])
            i+=1
        else :
            mergedList.append(Arr2[j])
            j+=1

    while i<len(Arr1) :
        mergedList.append(Arr1[i])
        i+=1
    while j<len(Arr2) :
        mergedList.append(Arr2[j])
        j+=1

    return mergedList    

def mergeSort(Arr) :
    if(len(Arr)<=1) : 
        return Arr
    if(len(Arr)==2) :
        return merge(Arr[0:1] , Arr[1:2])

    dividePivot = len(Arr)//2

    Arr = merge(mergeSort(Arr[:dividePivot]) , mergeSort(Arr[dividePivot:]))

    return Arr


if __name__ == "__main__" :
    import sys
    if len(sys.argv) < 2:
        print("No Input FIle")
        exit()

    F = open(sys.argv[1])
    Arr = list()

    for line in F:
        line = line.strip('\n')
        line= float(line)
        Arr.append(line)

    F.close()    
    Arr = mergeSort(Arr)

    F = open("sorted" + sys.argv[1],"w")
    for elem in Arr:
        F.write(str(elem) + "\n")

    F.close()
    print("Sorted and output written to sorted" + sys.argv[1])