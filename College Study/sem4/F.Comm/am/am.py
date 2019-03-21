import math
import matplotlib.pyplot as plt 
  
  
# function to show the plot 
#x= range(-10,10,0.1)
x = [(-5 + (0.01*i)) for i in range(0,1000)]
wc=800
wm=100
Vm=[]
Vc=[]
Vmod = []
for i in x:
    Vm.append(20 * math.sin(wm*i))
for i in x:
    Vc.append(50*math.sin(wc*i))

for i in x:
    Vmod.append((50+20*math.sin(wm*i))*math.sin(wc*i))

plt.figure(1)
plt.subplot(211)
plt.plot(x,Vm,label="message signal")
plt.subplot(212)
plt.plot(x,Vc,label="carrier signal")
plt.figure(2)
plt.plot(x,Vmod,label="Modulated signal")
plt.xlabel("time")
plt.ylabel("Signal")
plt.show() 
