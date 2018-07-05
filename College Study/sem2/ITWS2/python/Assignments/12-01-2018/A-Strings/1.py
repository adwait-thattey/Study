path = input("Enter Path : ")
fname = input("Enter Name : ")
if path[-1][0] !='\\':
	print("Missing Trailing \\ \n Adding it")
	path = path + '\\'

print("Path + Name is : " + path + fname)	