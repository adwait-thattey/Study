import os
import platform
import struct
data = open("data.csv","w");
data.write("N" + "," + "Time" + "\n")
if(platform.system()=="Linux") : 
	mainrun = r"./a.out "
elif (platform.system()=="Windows") :
	mainrun = r".\a.exe "	
N = 1
os.system(r"gcc mul.c")
while N<1000000 :
	print("running " + str(N))
	run = mainrun + str(N)
	D = list()
	for i in range(3) :
		os.system(run)
		F = open("test.bin","rb")
		block = F.read(8)
		F.close()
		D.append(float(struct.unpack('d',block)[0]))
		#print(D , end=" ")

	D = sum(D)/3
	
	data.write("%d"%(2*N + 12) + "," + "%lf"%(D*1000))
	data.write('\n')
	
	N+=100

data.close()	
