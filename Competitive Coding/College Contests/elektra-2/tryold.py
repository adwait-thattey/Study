def chk(a,b,c) :
    if((a^b^c)==0) :
        if(a+b>c) and (b+c > a) and (a+c > b) :
            return True
        return False
    return False        


N = int(input())
a=0
b=0
c=0

count =0
while a<= N-1 :
    b=a
    while b<=N :
        c=b
        if(b == a+1) :
            b+=1
            continue
        while c<=N and c<a+b :
            if(chk(a,b,c)) : count+=1
            c+=1
        b+=1    	
    a+=1    

print(count)   