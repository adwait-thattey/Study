

data = list()
n = int(input().strip())
for a0 in range(n):
    details = input().strip().split(' ')
    name = details[0]
    diff = int(details[2]) - int(details[1])
    data.append([name,diff])

WINNER = data[n-1]
for i in data[::-1] :
	if(i[1]>=WINNER[1]) :
		WINNER = i
print(WINNER[0] , WINNER[1])		