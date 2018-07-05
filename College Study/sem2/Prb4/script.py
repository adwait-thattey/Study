import os
import struct
data = open("data.csv","w");
data.write("N" + "," + "Time" + "\n")

x = 1
while x<200000 :
	print("running " + str(x))
	run = r"./a.out " + str(x)
	os.system(r"gcc mul.c")
	D = list()
	for i in range(3) :
		os.system(run)
		F = open("test.bin","rb")
		block = F.read(8)
		F.close()
		D.append(float(struct.unpack('d',block)[0]))
		#print(D , end=" ")

	D = sum(D)/3
	
	data.write("%d"%x + "," + "%lf"%D)
	data.write('\n')
	
	x+=10
