The file main.go contains the code for the assignment written in golang
The file result.out is a binary file which has been compiled from the main.go file

The result.out can be run on any Linux machine without installing any dependencies.
To run main.go, golang needs to be installed from official repositories

Usage: ./result.out [algorithm_code] [input_size] [input_type]
    result.out is the name of file. (change if different)
    [algorithm_code] refers to which algo should be applied
        - 1 : Odd-Even Transposition Sort                                                                                       
        - 2 : Sasaki n-1 round sort                                                                                             
        - 3 : Median based n-1 round sort                                                                                                                                                                                                       
    
    [input_size] is the number of integers that need to be sorted
    [input_type] refers to the order in which integers are generated                                                                
        - 1 : Generates sorted sequence                                                                                         
        - 2 : Generates random sequence                                                                                         
        - 3 : Generates reverse sorted sequence)
    
    Example: ./result.out 1 10 1
    Will generate 10 random numbers and sort them using Odd Even Transposition sort)
    
    Example: ./result.out 2 5 3
    Will generate 5 reverse sorted numbers and sort them using Median Based n-1 sort
    

# Some Sample Results

./result.out 1 5 2
[Main Thread] Generating random sequence of 5 elements
[Main Thread] Initial State:
[Main Thread] [-79 -99 28 36 -89]                                                                                                                                                                                                               

[Algo] Starting Odd Even Transposition Sort                                                                                                                                                                                                     

[Observer] Round 1 Complete                                                                                             
[Observer] [-99 -79 28 36 -89]                                                                                                                                                                                                                  

[Observer] Round 2 Complete                                                                                             
[Observer] [-99 -79 28 -89 36]                                                                                                                                                                                                                  

[Observer] Round 3 Complete                                                                                             
[Observer] [-99 -79 -89 28 36]                                                                                                                                                                                                                  

[Observer] Round 4 Complete                                                                                             
[Observer] [-99 -89 -79 28 36]                                                                                                                                                                                                                  

[Observer] Round 5 Complete                                                                                             
[Observer] [-99 -89 -79 28 36]

-----
[Observer] Algo run complete. Final Output:                                                                             
[Observer] [-99 -89 -79 28 36]                                                                                                                                                                                                                                                                                                                                          Total time taken 1.6177ms


## Observations

Below approximately 100 elements, the odd even transposition sort seems to work fastest. 
Above 100 elements, the 3rd median based sort seems to work the fastest.
