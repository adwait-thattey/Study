from numba import jit, cuda 
import numpy as np 
# to measure exec time 
from timeit import default_timer as timer    
  

n = 100000000                        
# normal function to run on cpu 
def func(a):                                 
    for i in range(n-2): 
        a[i]*= a[i+1]      
  
# function optimized to run on gpu  
@jit(target ="cuda")                          
def func2(a): 
    for i in range(n-2): 
        [i for i in range(1,n)]


if __name__=="__main__": 
    a = np.ones(n, dtype = np.float64) 
    b = np.ones(n, dtype = np.float32) 
      
    start = timer() 
    #func(a) 
    print("without GPU:", timer()-start)     
      
    start = timer() 
    func2(a) 
    print("with GPU:", timer()-start) 
