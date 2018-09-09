import sys
import time
#import resource


#resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
sys.setrecursionlimit(10000)

def merge(arr,start,mid,end):
	nl = int(mid-start+1)
	nr = int(end-mid)

	LAr = []
	for i in range(nl):
		LAr.append(arr[start+i])
	
	RAr = []
	for j in range(nr):
		RAr.append(arr[mid+1+j])
	
	i = 0 
	j = 0 
	k = start
	
	while i < nl and j < nr:
		if L[i] <= R[j]:
			arr[k] = LAr[i]
			i = i+1
		
		else:
			arr[k] = RAr[j]
			j = j+1
		k = k+1
	
	while i < nl:
		arr[k] = LAr[i]
		i = i+1
		k = k+1
	
	while j < nr:
		arr[k] =RAr[j]
		j = i+1
		k = k+1




def merge_sort(arr,start,end):
	if start < end:
		mid = (start+(end-start))/2
		merge_sort(arr,start,mid)
		merge_sort(arr,mid+1,end)
		merge(arr,start,mid,end)



n = int(sys.argv[1])
arr=[]	


with open(sys.argv[3]) as f1:
	fl = f1.readlines()
	for i in range(n):
		arr.append(float(fl[i]))
		
stime = time.time() 
merge_sort(arr,0,n-1)
etime = time.time()

print()
print()
print()
print()

for i in range(len(arr)):
	print(arr[i])
	
print()
print()
print(etime-stime) 
	
	
		
