def calc(s1,s2,cur,count):
 
	
	while len(s1)>0 and s1[0]==cur: s1 = s1[1:]
	while len(s2)>0 and s2[0]==cur: s2 = s2[1:]
 
	if len(s1)<=0 and len(s2)<=0 : return count

		
		
	elif len(s1)>1 and len(s2)>1:
		if s1[0]==s2[0] : 
			return calc(s1[1:],s2,s1[0],1)
		if s1[0]==s2[1] and s1[1]==s2[0]:
			return calc(s1[1:],s2,s1[0],1)
			
 
	if len(s2)<=0: return calc(s1[1:],"",s1[0],count+1)
	elif len(s1)<=0 : return calc("",s2[1:],s2[0],count+1)
	else : return min(calc(s1[1:],s2,s1[0],count+1) , calc(s1,s2[1:],s2[0],count+1) )
 
 
 
 
 
T = int(input())
while(T>0):
	T-=1
	line=input()
	#n,m = int(line[0]),int(line[1])
	s1 = input()
	s2 = input()
	
	if s1[0]==s2[0] : 
		print(calc(s1[1:],s2,s1[0],1))
		continue
	elif len(s1)>1 and len(s2)>1:
		if s1[0]==s2[1] and s1[1]==s2[0]:
			print(calc(s1[1:],s2,s1[0],1))
			continue
	print(min(calc(s1[1:],s2,s1[0],1) , calc(s1,s2[1:],s2[0],1)))
 