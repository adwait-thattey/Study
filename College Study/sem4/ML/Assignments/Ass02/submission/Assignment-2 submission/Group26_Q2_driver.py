import random
from matplotlib import pyplot as plt

NO_OF_FEATURES = 6

PERCEPTRON = [0]*(NO_OF_FEATURES+1)  # From w0 to wn
# PERCEPTRON[1] = -2.3
# PERCEPTRON = [-2.8823466100687996, 6.825859943430779, -1.7894779990024727, -
#   0.30448100164078074, 0.04340274912407705, -0.4295948080239039, 113.91553233820511]
ETA = 0.015
STOP_DER_J = 0.00001
ERR_VEC = list()
ITERS = 0
# CUR_GRAD = 100


def add_vectors(vector1, vector2):
    if len(vector1) != len(vector2):
        raise IndexError("Vectors are of uneven length")

    for x in range(len(vector1)):
        vector1[x] = vector1[x] + vector2[x]

    return vector1


def calc_error_for_point(pt, expected_y):
    """
    put point in perceptron and calculate difference
    """
    calc_y = 0
    for i in range(len(pt)):
        calc_y += PERCEPTRON[i]*pt[i]
        error = (expected_y - calc_y)
    return error


def calc_error_square_for_point(pt, expected_y):

    return calc_error_for_point(pt, expected_y)**2


def calc_total_error_square(pt_vec, expected_vec):
    tot = 0
    for i in range(len(pt_vec)):
        tot += calc_error_square_for_point(pt_vec[i], expected_vec[i])

    tot /= 2
    tot /= len(pt_vec)

    return tot


def calc_error_derivative_for_one_dim(pt, expected_y, dim):
    """
    dim may range from 1 to NO_OF_FEATURES
    error = calc_error_for_point(pt, expected_y)

    """
    error = calc_error_for_point(pt, expected_y)
    derivative_error = 2*error*pt[dim]

    return derivative_error


def calc_derivative_error_for_point(pt, expected_y):
    """
    calc for all dims
    error = calc_error_for_point(pt, expected_y)
    """

    der_error = list()

    for dim in range(0, NO_OF_FEATURES+1):

        der_error.append(
            calc_error_derivative_for_one_dim(pt, expected_y, dim)
        )

    return der_error


def calc_der_error_for_all_points(pt_vector, expected_y_vector):
    tot_der_error = [0]*(NO_OF_FEATURES+1)

    for i in range(len(pt_vector)):
        der_error = calc_derivative_error_for_point(
            pt_vector[i], expected_y_vector[i])

        tot_der_error = add_vectors(tot_der_error, der_error)

    return tot_der_error


def alter_perceptron(tot_der_error_vector):

    global PERCEPTRON
    # print("original p:", PERCEPTRON)
    # sign = (CUR_GRAD > 0 and 1) or -1
    for i in range(len(PERCEPTRON)):
        PERCEPTRON[i] += ETA*tot_der_error_vector[i]

    # print("altered", PERCEPTRON)


def perform_gradient_descent(pt_vector, expected_y_vector):
    global CUR_GRAD
    T = 100000
    global ITERS
    ITERS = 0
    while True:
        #
        tot_der_error_vector = calc_der_error_for_all_points(
            pt_vector, expected_y_vector)

        tot_avg_der_error_vec = [ss/len(pt_vector)
                                 for ss in tot_der_error_vector]

        s = sum(tot_avg_der_error_vec)
        print("gradient: ", s)

        CUR_GRAD = s
        # input()
        ERR_VEC.append(calc_total_error_square(pt_vector, expected_y_vector))
        if(-1*STOP_DER_J < s < STOP_DER_J):
            print("\n")
            print("final perceptron: ", PERCEPTRON)
            print("iterations: ", ITERS)
            print("final training set error:", calc_total_error_square(
                pt_vector, expected_y_vector))

            iters = [i+1 for i in range(ITERS)]
            plt.xlabel("Iterations")
            plt.ylabel("Total Error")
            plt.plot(iters, ERR_VEC[1:])

            plt.show()
            raise StopIteration("Gradient is below threshold")

        ITERS += 1
        alter_perceptron(tot_avg_der_error_vec)


def shuffle_file(file_name):
    f = open(file_name, mode="r")
    lines = f.readlines()
    random.shuffle(lines)

    f.close()
    f = open('shuffled' + file_name, mode="w")
    for l in lines:
        f.write(l)

    f.close()


def read_points_from_file(file_path):
    """
        Append 1 at the begining of pt
    """
    f = open(file_path)
    lines = f.readlines()
    pt_vector = list()
    expected_y_vector = list()

    for l in lines:
        # print(l.strip('\n').split(' '))

        float_l = [float(x) for x in l.strip('\n').split(' ') if x]
        pt = [1] + float_l[:NO_OF_FEATURES]  # append 1 at start of p
        exp_y = float_l[NO_OF_FEATURES]

        pt_vector.append(pt)
        expected_y_vector.append(exp_y)

    f.close()
    return pt_vector, expected_y_vector
