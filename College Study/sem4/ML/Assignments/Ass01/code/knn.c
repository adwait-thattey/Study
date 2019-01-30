#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int NO_OF_FEATURES = 0;
const double inf = 9999999999.99;

typedef struct POINT
{
    int id;
    double *fv;
    int class;
} point;

typedef struct NEIGHBOUR
{
    int class;
    double dist;
} neighbour;

point init_point(double *fv, int id, int class)
{

    point p;
    p.id = id;
    p.fv = malloc(NO_OF_FEATURES * sizeof(double));
    p.class = class;
    for (int i = 0; i < NO_OF_FEATURES; ++i)
    {
        p.fv[i] = fv[i];
    }

    return p;
}

neighbour init_neighbour(int class, double dist)
{
    neighbour n;
    n.class = class;
    n.dist = dist;

    return n;
}

double getMinkowskiDistance(point p1, point p2, int p)
{
    double sum = 0;
    for (int i = 0; i < NO_OF_FEATURES; ++i)
    {
        double val = fabs(p1.fv[i] - p2.fv[i]);
        sum += pow(val, p);
    }

    double dist = pow(sum, ((double)1 / (double)p));

    return dist;
}

void shift_and_delete_nn(neighbour *neighbours, neighbour n, int pos, int size)
{
    if (pos < 0 || pos >= size)
    {
        return;
    }

    for (int i = size - 1; i >= pos + 1; --i)
    {
        neighbours[i] = neighbours[i - 1];
    }

    neighbours[pos] = n;
}
void keepNearestK(neighbour *nearest_neighbours, point p, double dist, int size)
{
    neighbour n;
    n.dist = dist;
    n.class = p.class;

    for (int pos = size - 1; pos >= 0; --pos)
    {
        if (nearest_neighbours[pos].dist < dist)
        {

            shift_and_delete_nn(nearest_neighbours, n, pos + 1, size);
            return;
        }
    }

    // No position was found. Correct position is 0
    // If position was found, function would have returned.
    shift_and_delete_nn(nearest_neighbours, n, 0, size);
}

neighbour *getKNearestNegihbours(point *points, point point, int size, int k, int p)
{
    neighbour *neighbours = malloc(k * sizeof(neighbour));

    neighbour inf_neigh;
    inf_neigh.class = -1;
    inf_neigh.dist = inf;

    // set the first k members of points as infinite neighbours
    for (int i = 0; i < k; ++i)
    {
        neighbours[i] = inf_neigh;
    }

    for (int i = 0; i < size; ++i)
    {
        float dist = getMinkowskiDistance(point, points[i], p);
        keepNearestK(neighbours, points[i], dist, k);
    }

    return neighbours;
}

int main()
{
    NO_OF_FEATURES = 2;

    int N;
    scanf("%d %d", &NO_OF_FEATURES, &N);

    point *p = malloc(N * sizeof(point));

    int K, P;
    scanf("%d %d", &K, &P);

    for (int i = 0; i < N; ++i)
    {
        double arr[2];
        int c;
        scanf("%lf %lf %d", &arr[0], &arr[1], &c);

        p[i] = init_point(arr, 0, c);
    }

    point base = p[0];

    neighbour *neighbours = getKNearestNegihbours(p, base, N, K, P);

    for (int i = 0; i < K; ++i)
    {
        printf("%lf %d \n", neighbours[i].dist, neighbours[i].class);
    }

    // double fv1[] = {3.0, 0.0}, fv2[] = {0.0, 4.0};

    // p1 = init_point(fv1, 1);
    // p2 = init_point(fv2, 2);

    // printf("%lf", getMinkowskiDistance(p1, p2, 2));
    return 0;
}