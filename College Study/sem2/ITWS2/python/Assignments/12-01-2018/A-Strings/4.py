PIN = list()
print("Enter Multiline Address with last line containing the pincoe at end:\n")
while True:
	S = input().strip()
	if len(S)==0:
		break;
	PIN=S	

try :
	PIN = int(PIN[-6:])
except : 
	print("You did not follow Syntax")
	exit()
print("Pin : " + str(PIN))

