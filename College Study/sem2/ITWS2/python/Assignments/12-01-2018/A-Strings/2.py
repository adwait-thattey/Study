print("\n\nAssuming a file named \"file.txt\" is located in a folder named projects in C:")
print("\n\n PAth in Windows : ",end=" ");
winpath = r"C:\projects\file.txt"
print(winpath)
temp = r"/win/c" + winpath[2:]
ind = [i for i in range(len(temp)) if temp[i]=='\\']

for i in ind:
	temp = temp[:i] + r'/' + temp[i+1:]
print("Path in Linux : " , end=" ")
print(temp)	