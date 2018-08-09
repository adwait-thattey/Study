import random
import sys
def build_points(no_of_points=10,limit = 100):
    if no_of_points < 2:
        raise ValueError("No of points should be at least 2")
    points = list()
    while no_of_points > 0:
        
        new_point = (random.randint(0,limit),random.randint(0,limit))
        if new_point in points : 
            continue

        points.append(new_point)
        no_of_points-=1

    return points

def get_distance_square(point1, point2):
    xdiff = point1[0] - point2[0]
    ydiff = point1[1] - point2[1]

    return xdiff**2 + ydiff**2

def get_distance(point1, point2):
    return get_distance_square(point1, point2)**0.5


def find_naive_closest_pair(points):
    closest_pair_point1 = points[0]
    closest_pair_point2 = points[1]
    closest_distance = get_distance_square(closest_pair_point1,closest_pair_point2)
    
    for i in range(1,len(points)):
        for j in range(i+1,len(points)):
            cur_distance = get_distance_square(points[i], points[j])
            if cur_distance < closest_distance : 
                closest_pair_point1 = points[i]
                closest_pair_point2 = points[j]
                closest_distance = cur_distance

    return (closest_pair_point1, closest_pair_point2)


def find_efficient_closest_pair(Px, Py):
    if len(Px) <= 2:
        return (Px[0], Px[1])

    Lx = Px[:len(Px)//2]
    Rx = Px[len(Px)//2:]
    Ly = Py[:len(Py)//2]
    Ry = Py[len(Py)//2:]    

    left_pair = find_efficient_closest_pair(Lx, Ly)

if __name__=="__main__":
    try:
        POINTS = build_points(sys.argv[1])
    except IndexError:
        POINTS = build_points()
    
    Px = POINTS.sort(key = lambda p: p[0])
    Py = POINTS.sort(key = lambda p: p[1])

    
    
    closest_pair = find_naive_closest_pair(POINTS)
    print("Correct Answer : ")
    print(closest_pair[0])
    print(closest_pair[1])
    print("Distance : ", get_distance(closest_pair[0], closest_pair[1]))

        

