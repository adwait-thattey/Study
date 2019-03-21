from ass01 import *
import matplotlib.pyplot as plt
ptv, expv = read_points_from_file('shuffledyacht_hydrodynamics.data')

train_ptv = ptv[200:]
train_expv = expv[200:]

test_ptv = ptv[:50]
test_expv = expv[:50]

try:
    perform_gradient_descent(train_ptv, train_expv)
except StopIteration:
    pass
# print("final perceptron:", WEIGHTS)
print()
print("final test set error", calc_total_error_square(test_ptv, test_expv))

# print(ITERS)
