def fast_multiply(num1,num2):
    """
    Both numbers are strings.
    @param num1 = 10^(n/2)A + B
    @param num2 = 10^(n/2)C + D
    return num1*num2 = 10^(n)AC + 10^(n/2)(AD+BC) + BD
    Note: AD+BC = (A+B)(C+D) - AC - BD
    """

    if len(num1)!=len(num2):
        raise ValueError("Length Of Both Numbers should be equal")

    if len(num1)==1:
        return int(num1)*int(num2)

    else:
        A = num1[:len(num1)//2]
        B = num1[len(num1)//2:]
        C = num2[:len(num2)//2]
        D = num2[len(num2)//2:]

        AC = fast_multiply(A,C)
        BD = fast_multiply(B,D)
        ApB = str(int(A) + int(B))
        CpD = str(int(C) + int(D))
        ApB,CpD = pre_process(ApB,CpD)
        ApBCpD = fast_multiply(ApB,CpD)
        ADpBC = ApBCpD - AC - BD
        power = "1" + "0"*len(num1)
        half_power = "1" + "0"*(len(num1)//2)

        return int(power)*AC + int(half_power)*ADpBC + BD

def pre_process(num1,num2):
    num1 = str(num1)
    num2 = str(num2)
    flag = False
    if len(num1) >= len(num2):
        flag=True
        larger = num1
        smaller = num2
    else:
        larger = num2
        smaller = num1

    from math import log,ceil
    
    req = 2**ceil(log(len(larger),2))

    larger = "0"*(req-len(larger)) + larger
    smaller = "0"*(req-len(smaller)) + smaller

    if flag:
        return (larger,smaller)
    else:
        return (smaller,larger)    
                
def start(File):
    F = open(File)
    num1 = F.readline().strip('\n')
    num2 = F.readline().strip('\n')
    # print(num1,num2)
    num1,num2 = pre_process(num1,num2)
    print(num1)
    print(num2)
    return str(fast_multiply(num1,num2))

if __name__ == "__main__":
    import sys
    print(start(sys.argv[1]))
