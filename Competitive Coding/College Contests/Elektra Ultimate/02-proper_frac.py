def get_term(n) :
    p = 1 + 2*(n-1)
    q = 1 + 3*(n-1)

    return (p,q)

def modulo_pow(a, b, m):
    res = 1
    a = a % m

    while b > 0:
        if b & 1:
            res = (res*a) % m

        b >>= 1
        a = (a*a) % m

    return res

# x = modulo_pow(10,1000000005,1000000007)
# y = (x*7)%1000000007

T = int(input())
while T > 0:
    T-=1
    n = int(input())
    p,q = get_term(n)
    
    mod1 = 1000000007
    mod2 = 1000000009
    num1 = modulo_pow(q,mod1-2,mod1)
    num1 = (num1*p)%mod1
    num2 = modulo_pow(q,mod2-2,mod2)
    num2 = (num2*p)%mod2
    print(num1 , num2)