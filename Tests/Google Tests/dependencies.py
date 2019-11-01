test_cases = int(input())
dependencies = dict()
delayed_projects = list()
while test_cases > 0:
    test_cases -=1
    K,J = [int(i) for i in input().split()]
    for k in range(K):
        X,Y = [int(i) for i in input().split()]
        if Y not in dependencies:
            dependencies[Y] = list()

        dependencies[Y].append(X)

        delayed_projects = [int(i) for i in input().split()]


