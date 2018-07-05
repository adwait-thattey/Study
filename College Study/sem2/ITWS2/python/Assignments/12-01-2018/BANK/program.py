F = open("account_data.txt",mode="r",encoding="cp1252")
data = F.readlines()
F.close()

accounts = list()
print(data)

for S in data:
	S = S.strip("\n")
	S = S.split(',')
	cur = {"name":S[0],"ACno":S[1],"pass":S[2],"balance":S[3]}
	accounts.append(cur)


def prdetails(acc):
	K = acc.keys()
	for i in K:
		print(str(i) + ":" + str(acc[i]) , end=" , ")
	print()		

def search():
	name = input("Enter first name of account holder : ")
	NAMES = [accounts[i]["name"].split()[0] for i in range(len(accounts))]
		
	if name in NAMES :
		print("\nfollowing accounts exist with the given name:\n")
		count=0
		while name in NAMES:
			
			try:
				ix = NAMES.index(name) + count
				print(str(accounts[ix]["name"] + "  " + accounts[ix]["ACno"]))
				count+=1
				NAMES.pop(ix)
			except : 
				break
	else : print("Sorry!! No Account exists with this name")				

def deposit():
	no = input("Enter Acc Number to deposit")
	if no not in [accounts[i]["ACno"] for i in range(len(accounts))] :
		print("Account Not Found")
		return

	amt = int(input("How much do you wanna deposit??"))

	ix=0

	for i in range(len(accounts)):
		if accounts[i]["ACno"]==no :
			ix=i
			break

	accounts[ix]["balance"]= str(amt + int(accounts[ix]["balance"]))

def withdraw():
	no = input("Enter Acc Number to withdraw")
	if no not in [accounts[i]["ACno"] for i in range(len(accounts))] :
		print("Account Not Found")
		return

	ix=0

	for i in range(len(accounts)):
		if accounts[i]["ACno"]==no :
			ix=i
			break

	password = input("Enter Password: ")

	if(accounts[ix]["pass"]!=password) :
		print("Wrong Password!!!")
		return

	money = int(input("How much do u want to withdraw?? : "))
	if(money>int(accounts[ix]["balance"])):
		print("Insufficient Balance!!")
		return

	accounts[ix]["balance"]= str(int(accounts[ix]["balance"]) - money)


def writeback():
	F = open("account_data.txt",mode="w",encoding="cp1252")
	for I in accounts:
		line = I.values()
		line = ",".join(line)
		line +="\n"
		F.write(line)
	F.close()	


print("\n\n ------WELCOME TO CRAPPY BANK-----\n\n")
import platform
import os
while True:
	if(platform.system()=="Windows") : os.system('cls')
	else : os.system("clear") 
	print("\n\n ------MAIN MENU-----\n\n")
	print("What do you want to do??")
	print("Type s to search for account\n     d to deposit\n     w to withdraw\n      e to exit")
	choice = input().strip().lower()

	if(platform.system()=="Windows") : os.system('cls')
	else : os.system("clear")

	if (choice=='s') : search()
	elif (choice=='d') : deposit() 
	elif (choice=='w') : withdraw()
	elif (choice=='e') : 
		print("\n\nPerforming Writeback to the file...\n\n")
		writeback()
		print("OK BYE!!!\nPrinting details of all accounts before going as required\n")
		for i in accounts:
			print("\n")
			prdetails(i)

		
		print("Bye!!")
		exit()	

	print("\n\nPress any Key to Continue")
	input()	




		
