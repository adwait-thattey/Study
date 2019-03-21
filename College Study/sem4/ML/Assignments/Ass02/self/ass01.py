import random
from matplotlib import pyplot as plt
import threading


# def run_in_background(func):
#     def decorator(*args, **kwargs):
#         t = threading.Thread(target=func, args=args, kwargs=kwargs)
#         t.daemon = True
#         t.start()

#     return decorator


NO_OF_FEATURES = 6

WEIGHTS = [0]*(NO_OF_FEATURES+1)  # From w0 to wn
# WEIGHTS[1] = -2.3
# WEIGHTS = [-2.8823466100687996, 6.825859943430779, -1.7894779990024727, -
#   0.30448100164078074, 0.04340274912407705, -0.4295948080239039, 113.91553233820511]
ETA = 0.015
STOP_DER_J = 0.00001
ERR_VEC = list()
ITERS = 0
PREV_ERR = 99999
CUR_ERR = 88888
# CUR_GRAD = 100

POLARITY_FLAG = 1


def check_polarity():
    global POLARITY_FLAG
    if POLARITY_FLAG:
        if PREV_ERR < CUR_ERR:
            print(
                "eta is too high!. will overshoot or oscillate. press ctrl+c to stop or enter to continue")
            input()
            POLARITY_FLAG = 0


def add_vectors(vector1, vector2):
    if len(vector1) != len(vector2):
        raise IndexError("Vectors are of uneven length")

    for x in range(len(vector1)):
        vector1[x] = vector1[x] + vector2[x]

    return vector1


def calc_error_for_point(pt, expected_y):
    """
    put point in weight_vector and calculate difference
    """
    calc_y = 0
    for i in range(len(pt)):
        calc_y += WEIGHTS[i]*pt[i]
        error = (expected_y - calc_y)
    return error


def calc_error_square_for_point(pt, expected_y):
    err_sq = calc_error_for_point(pt, expected_y)**2
    # print(err_sq)
    return err_sq


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


def alter_weights(tot_der_error_vector):

    global WEIGHTS
    # print("original p:", WEIGHTS)
    # sign = (CUR_GRAD > 0 and 1) or -1
    check_polarity()
    for i in range(len(WEIGHTS)):
        WEIGHTS[i] += ETA*tot_der_error_vector[i]

    PREV_ERR = tot_der_error_vector
    # print("altered", WEIGHTS)


def plot_graph(iters, err_vec):
    plt.xlabel("Iterations")
    plt.ylabel("Total Error")
    plt.plot(iters, ERR_VEC[1:])
    plt.show()


def final_analysis(pt_vector, expected_y_vector):
    print("\n")
    print("final weight_vector: ", WEIGHTS)
    print("iterations: ", ITERS)
    print("final training set error:", calc_total_error_square(
        pt_vector, expected_y_vector))

    iters = [i+1 for i in range(ITERS)]
    plot_graph(iters, ERR_VEC)


def perform_gradient_descent(pt_vector, expected_y_vector):
    global CUR_GRAD, CUR_ERR, PREV_ERR
    T = 100000
    global ITERS
    ITERS = 0
    try:
        while True:
            #
            tot_der_error_vector = calc_der_error_for_all_points(
                pt_vector, expected_y_vector)

            tot_avg_der_error_vec = [ss/len(pt_vector)
                                     for ss in tot_der_error_vector]

            s = sum(tot_avg_der_error_vec)
            tot_error = calc_total_error_square(pt_vector, expected_y_vector)
            PREV_ERR = CUR_ERR
            CUR_ERR = tot_error
            print("gradient: ", "%-22s" % s, "error:", tot_error)

            CUR_GRAD = s
            # input()
            ERR_VEC.append(tot_error)
            if(-1*STOP_DER_J < s < STOP_DER_J):
                final_analysis(pt_vector, expected_y_vector)
                raise StopIteration("Gradient is below threshold")

            ITERS += 1
            alter_weights(tot_avg_der_error_vec)
    except KeyboardInterrupt:
        try:
            final_analysis(pt_vector, expected_y_vector)
        except ValueError:
            ITERS -= 1
            final_analysis(pt_vector, expected_y_vector)
        raise StopIteration("Keyboard Interrupt!")


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
