T = int(input().strip())
while T>0 :
    T-=1
    line = input().split()
    N,K = int(line[0]),int(line[1])
    Arr = [int(i) for i in input().split()]

    if K>10 : 



        Smax2 = Arr[0]
        scur2 = 0    
        for i in Arr*2 :
            scur2+=i
            if scur2<=0 : scur2=0
            if scur2>Smax2 : Smax2 = scur2
    
        if Smax2<=0 : Smax2 = max(Arr)
        #else : print(Smax2)

      
        Smax = K*sum(Arr)
        scur = Smax
        for i in Arr :
            scur-=i
            if scur>Smax :
                Smax = scur

        scur = Smax        

        for i in Arr[::-1] :
            scur-=i
            if scur>Smax :
                Smax = scur

        if Smax>Smax2 :
            if Smax>max(Arr) : 
                print(Smax)
                continue
            else : K=1
        else :
         print(Smax2)            
         continue



    if K<10 :
        Smax = Arr[0]
        scur = 0    
        for i in Arr*K :
            scur+=i
            if scur<=0 : scur=0
            if scur>Smax : Smax = scur
    
        if Smax<=0 : print(max(Arr))
        else : print(Smax)

