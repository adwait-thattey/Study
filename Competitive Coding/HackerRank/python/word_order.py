# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import OrderedDict
n = int(input())

word_dict = OrderedDict()

for i in range(n):
    word = input()
    if word in word_dict:
        word_dict[word]+=1
    else:
        word_dict[word] = 1

print(len(word_dict))
print(*word_dict.values())
