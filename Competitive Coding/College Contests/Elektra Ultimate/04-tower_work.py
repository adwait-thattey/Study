#!/bin/python3

# Complete the towerColoring function below.


def towerColoring(n):
    return (3**(3**n)) % (1000000007)


if __name__ == '__main__':

    n = int(input())

    result = towerColoring(n)

    print(result)