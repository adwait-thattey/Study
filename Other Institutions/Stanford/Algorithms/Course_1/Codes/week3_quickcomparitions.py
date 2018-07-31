total_comparitions = 0

def get_pivot(Arr,left,right) :
    return Arr[left]

def quick_sort(Arr,left,right):
    global total_comparitions
    if left >=right :
        return
    pivot = get_pivot(Arr,left,right)
    Arr[left],Arr[pivot] = Arr[pivot],Arr[left]
    i = left+1
    for j in range(left+1,right+1) :
        if Arr[j] < Arr[left]:
            Arr[j],Arr[i] = Arr[i],Arr[j]
            i+=1

    Arr[left],Arr[i-1] = Arr[i-1],Arr[left]
    total_comparitions+=(right-left)

    quick_sort(Arr,left,i-2)
    quick_sort(Arr,i,right)        

