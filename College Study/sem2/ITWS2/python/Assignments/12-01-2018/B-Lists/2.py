Numbers = [1000,832,622,322,124]
print("Current List : " , end=" ")
print(Numbers)
num = int(input("\n Enter A Number : ").strip())
Numbers.append(num)

if Numbers[0]>Numbers[1] : Numbers.sort(reverse=True)
else : Numbers.sort()

print("\nNew List: ", end=" ")
print(Numbers)