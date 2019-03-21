from collections import OrderedDict

def chunkIt(seq, num):
    avg = len(seq) / float(num)
    out = []
    last = 0.0

    while last < len(seq):
        out.append(seq[int(last):int(last + avg)])
        last += avg

    return out

s = list(input())
k = int(input())

chunks = chunkIt(s,k)

for t in chunks:
    u = ''.join(OrderedDict.fromkeys(t))
    print(u)

#print(chunks)

