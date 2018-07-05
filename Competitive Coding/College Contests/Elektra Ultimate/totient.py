from primes import *
def totient(n):
    result = n

    for i in primes : 
        if i*i > n : break
        if n % i == 0:
            while n % i == 0:
                n //= i
            result -= result // i
        i += 1
    if n > 1:
        result -= result // n
    return result

T = int(input())
while T > 0 :
    T-=1
    print(totient(int(input())))
