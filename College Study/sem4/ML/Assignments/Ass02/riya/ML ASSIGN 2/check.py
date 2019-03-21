import matplotlib.pyplot as plt
import random


def predict(w, row):
    val = 0
    for id2, feature in enumerate(row):
        val = val + float(feature)*w[id2]

    pred = 0 if val <= 0 else 1
    return pred


def grad(rows, w):
    g = [0 for i in range(len(rows[1]))]
    for id1, row in enumerate(rows):
        val = predict(w, row)
        diff = val - labels_training[id1]
        for i in range(len(row)):
            g[i] = g[i] + (float(row[i])*diff)/dataset_size

    return g


def cost(rows, w):
    error = 0
    for idx, row in enumerate(rows):
        prediction = predict(w, row)
        error = error + (prediction-labels_training[idx]) ** 2

    return error/(2*dataset_size)


def error_calculation(labs, rows, w):
    error = 0
    for idx, row in enumerate(rows):
        val = predict(w, row)
        if(val != labs[idx]):
            error = error+1

    return error


def train(data, params, labs, learning_rate, th):
    J = []
    iters = 0
    iters_plot = []

    while any(abs(z) > th for z in grad(data, params)):
        iters_plot.append(iters+1)
        J.append(cost(data, params))
        gradient = grad(data, params)

        for idx, j in enumerate(params):
            params[idx] = params[idx] - learning_rate*gradient[idx]

        iters = iters+1

    print("Training set error:", (error_calculation(labs, data, params)/70)*100, "%")
    print("Training set accuracy:",
          100 - ((error_calculation(labs, data, params)/70)*100), "%")

    plt.plot(iters_plot, J)
    plt.xlabel('Number of iterations')
    plt.ylabel('Cost Function')

    plt.title('Cost function against number of iterations')
    plt.show()
    print("Calculated weights: ", params)
    return params


filename = "data1"

labels = []
training_set = []  # Training examples
no_train_examples = 70
no_test_examples = 30
dataset = []
labels_training = []
test_set = []
labels_test = []


with open('data1', 'r') as f:
    for line in f:
        words = line.split(',')
        if(words[-1] == 'Iris-versicolor\n'):
            labels.append(0)
        else:
            labels.append(1)
        dataset.append([1]+words[:-1])


dataset_size = len(dataset)

c = range(0, dataset_size)
d = random.sample(c, no_train_examples)
for i in d:
    training_set.append(dataset[i])
    labels_training.append(labels[i])

for idx, row in enumerate(dataset):
    if row not in training_set:
        test_set.append(row)
        labels_test.append(labels[idx])

eta = 0.01
weight = [0, 0, 0, 0, 0]
max_iters = 1000
theta = 0.01


# Training
weight = train(training_set, weight, labels_training, eta, theta)


# Calculating test set error
test_error = error_calculation(labels_test, test_set, weight)
print("Test set error: ", test_error*100/30, "%")
print("Test set accuracy: ", 100 - (test_error*100/30), "%")
