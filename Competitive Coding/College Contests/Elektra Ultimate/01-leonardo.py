from primes import *

queries = int(input())

while queries >0 :
    queries-=1
    number = int(input())
    other_number = 1
    counter = 0
    for i in primes :
        other_number*=i
        if other_number > number : break
        counter+=1
    else :
        gen = generate_prime(number)
        while other_number < number :
            other_number*=next(gen)
            counter+=1
        counter-=1

    print(counter)        
