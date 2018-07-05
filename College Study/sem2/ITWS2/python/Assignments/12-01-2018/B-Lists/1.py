Numbers = [1000,832,622,322,124]
print("Current List : " , end=" ")
print(Numbers)
num = int(input("\n Enter A Number : ").strip())
Numbers.append(num)
Numbers.sort(reverse=True)
print("\nNew List: ", end=" ")
print(Numbers)