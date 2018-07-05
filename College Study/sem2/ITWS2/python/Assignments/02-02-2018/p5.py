number = 15
x = int(input("Guess The Number that i am thinking...."))

for i in range(3) :
	if(x==15) : 
		print("You gussed right!!!...")
		break
	elif(i!=2) :
		print("Sorry!! Wrong Answer!! You have " + str(2-i) + " more chance left... Try Again  : ")
		x = int(input())
	else : print("Sorry!!! You couldnt guess it")		