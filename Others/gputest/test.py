# make a matrix of 1000*1000 elements
# add 1 to each cell in every iteration

from timeit import default_timer as timer
from numba import jit, cuda 
import numpy as np

ITERATIONS = 1000
MAT_SIZE = 1000
    
@jit(target ="cuda")
def gpu_func(mat):
    

    for _ in range(ITERATIONS):
        for i in range(MAT_SIZE):
            for j in range(MAT_SIZE):
                mat[i][j]+=1


if __name__ == "__main__":
    

    mat =  np.zeros(shape=(MAT_SIZE,MAT_SIZE))
    
    start = timer()
    gpu_func(mat)
    print("Time taken:", timer()-start)

#for i in range(MAT_SIZE):
#    print(mat[i])
