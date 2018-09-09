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
    print("\n Enter elements for Array 1 (space seperated) \n ")
    Arr1 = [int(i) for i in input().split()]
    # print("\n Enter elements for Array 2 (space seperated) \n ")
    # Arr2 = [int(i) for i in input().split()]
    # print(merge(Arr1,Arr2))
    Arr1 = mergeSort(Arr1)
    print(Arr1)
