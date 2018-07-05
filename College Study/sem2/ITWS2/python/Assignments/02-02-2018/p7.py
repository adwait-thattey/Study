def fibonacci(n): #generator function
   a, b= 0, 1

   while(a<=n):
      yield a
      a,b=b,a+b


import sys
if(len(sys.argv)<3) :
	print("Insufficient Arguments!!")
	exit()
L = fibonacci(int(sys.argv[2]))

[print(i,end=" ") for i in L if i>int(sys.argv[1])]      