#!/bin/python3
import sys

def merge_n_count(left_Arr,right_Arr):
    i=j=k=0
    count = 0
    merged_Arr = list()
    last_counter = None
            
    while i < len(left_Arr) and j < len(right_Arr):
        if left_Arr[i] <= right_Arr[j]:
            merged_Arr.append(left_Arr[i])
            count+=(k-i)
            i+=1
        else :
            merged_Arr.append(right_Arr[j])
            j+=1
            
        k+=1
    while i < len(left_Arr) :
        merged_Arr.append(left_Arr[i])
        count+=(k-i)
        i+=1
        k+=1        
    
    while j < len(right_Arr):
        merged_Arr.append(right_Arr[j])
        j+=1
    
    return (merged_Arr,count)

        

def count_invertions(Arr) :

    if len(Arr) <= 1 :
        return (Arr,0)
    
    left_Arr,left_in = count_invertions(Arr[:len(Arr)//2])  
    right_Arr,right_in = count_invertions(Arr[len(Arr)//2:])
    merged_Arr,split_in = merge_n_count(left_Arr,right_Arr)

    
    return (merged_Arr,left_in+right_in+split_in)   

def start(filename):
    try :
        File = open(filename)
    except: 
        print("Either no file is provided or the provided file is invalid.")
        print("The file should be of type .txt with each line containing 1 number")
        exit()    
    Array = [int(line) for line in File if line!='\n']
    File.close()
    return count_invertions(Array)[1]

if __name__=="__main__":
    start(sys.argv[1])
