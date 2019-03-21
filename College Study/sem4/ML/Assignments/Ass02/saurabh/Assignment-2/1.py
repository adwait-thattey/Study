from random import shuffle
f = open('Yacht-Hydrodynamics.txt','r', encoding = 'utf-8')

dataset = f.read().split('\n')
f.close()

dataset.remove('')

for i in range(0, len(dataset)):
    dataset[i] = dataset[i].split()
    dataset[i] = list(map(float, dataset[i]))
    dataset[i] = [1] + dataset[i]



print('the given dataset is: \n\n')
for i in range(0, len(dataset)):
    print(dataset[i])
print('\n\n')

shuffle(dataset)
shuffle(dataset)

training_dataset=dataset[:200]
testing_dataset=dataset[200:]

iita = 0.001

W = [1, 1, 1, 1, 1, 1, 1]
for i in range(0, 7):
    W[i] = W[i]*15

# 1,1,1,1,1,1,1   215
# 15,15,15,15,15,15,15  156
# 14,14,14,14,14,14,14  233
# best we could find :
#W = [1.0627363346643806, -0.23081157967369945, 1.8609189863603948, 0.21634628945419818, 0.233653726756084, 0.33544709249039073, 15.621794544464136]
loop = 1

for times in range(0, 80000):
    if(loop==0):
        break
    for w in range(0, len(W)):
        loop = 0
        # 0 1 2 3 4 5 6
        W[0], W[w] = W[w], W[0]
        for swap in range(0, len(training_dataset)):
            training_dataset[swap][0], training_dataset[swap][w] = training_dataset[swap][w], training_dataset[swap][0]
        error = 0.0

        for x in range(0, len(training_dataset)):
            error = error + training_dataset[x][0]*(2*training_dataset[x][0]*W[0] + training_dataset[x][1]*W[1] + training_dataset[x][2]*W[2] + training_dataset[x][3]*W[3] + training_dataset[x][4]*W[4] + training_dataset[x][5]*W[5] + training_dataset[x][6]*W[6] - training_dataset[x][7])
        comp = W[0]
        W[0] = W[0] - (iita*error)/len(training_dataset)

        diff = comp - W[0]
        if(diff > 0.00000001 or diff < -0.00000001):
            loop = 1
        print('{} error :{} is {}'.format(times, w, W[0]))

        W[0], W[w] = W[w], W[0]
        for swap in range(0, len(training_dataset)):
            training_dataset[swap][0], training_dataset[swap][w] = training_dataset[swap][w], training_dataset[swap][0]

print('\n\nfinal W vector is \n')
print(W)
error = 0.0
for x in range(0, len(testing_dataset)):
    one = ((testing_dataset[x][0]*W[0] + testing_dataset[x][1]*W[1]+testing_dataset[x][2]*W[2]+testing_dataset[x][3]*W[3]+testing_dataset[x][4]*W[4]+testing_dataset[x][5]*W[5]+testing_dataset[x][6]*W[6] - testing_dataset[x][7]))
    error = error + one*one
    print('the error for y {} is {}'.format(testing_dataset[x][7], one))

print('\ntotal error = {}\n\n final W : {}'.format(error/len(testing_dataset), W))




