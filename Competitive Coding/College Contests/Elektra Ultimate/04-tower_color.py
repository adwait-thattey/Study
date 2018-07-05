def bin_pow(a,b) :
    res = 1
    cur = a
    while b > 0 :
        if b&1 :
            res*=cur
        cur*=cur
        b>>=1

    return res

def modulo_pow(a,b,m) :
    res = 1
    a = a%m

    while b > 0:
        if b&1 :
            res = (res*a)%m

        b>>=1
        a = (a*a)%m
    
    return res    

if __name__ == "__main__" :
    n = int(input())
    power = modulo_pow(3,n,1000000006)
    result = modulo_pow(3,power,1000000007)
    print(result)