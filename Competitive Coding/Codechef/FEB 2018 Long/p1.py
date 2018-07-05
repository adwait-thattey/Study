L = ["chef","chfe","cehf","cefh","cfeh","cfhe","hcef","hcfe","hecf","hefc","hfec","hfce","ehcf","ehfc","echf","ecfh","efch","efhc","fhec","fhce","fehc","fech","fceh","fche"]

T = int(input()) 

while(T) :
	T-=1
	S = input();

	count = 0;

	for i in L :
		count += S.count(i)

	if(count==0) :
		print("normal")

	else :
		print("lovely",end=" ")
		print(count)		
