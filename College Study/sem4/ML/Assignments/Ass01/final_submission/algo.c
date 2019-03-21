#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int NO_OF_FEATURES = 0;
int NO_OF_CLASSES = 0;
int CLASS_OFFSET = 0;
int FOLDS = 5;
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

neighbour *getKNearestNegihbours(point *points, point point, int size, int k, int p, int t_start, int t_end)
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
        if (i >= t_start && i < t_end)
        {
            continue;
        }
        float dist = getMinkowskiDistance(point, points[i], p);
        keepNearestK(neighbours, points[i], dist, k);
    }

    return neighbours;
}

bool classifyAndValidate(point *points, point point, int size, int k, int p, int t_start, int t_end)
{
    int class_vector[NO_OF_CLASSES];
    for (int i = 0; i < NO_OF_CLASSES; ++i)
    {
        class_vector[i] = 0;
    }

    neighbour *n = getKNearestNegihbours(points, point, size, k, p, t_start, t_end);

    for (int i = 0; i < k; ++i)
    {
        class_vector[n[i].class - CLASS_OFFSET]++;
    }

    int max = 0;

    for (int i = 0; i < NO_OF_CLASSES; ++i)
    {
        // printf("%d\n", class_vector[i]);
        if (class_vector[i] > class_vector[max])
        {
            max = i;
        }
    }

    max += CLASS_OFFSET;
    // printf("%d %d", max, max == point.class);

    return max == point.class;
}

double classifyAndValidateSet(point *training_set, int training_size, int k, int p, int t_start, int t_end)
{
    int correct = 0, wrong = 0;

    for (int i = t_start; i < t_end; ++i)
    {
        bool check = classifyAndValidate(training_set, training_set[i], training_size, k, p, t_start, t_end);
        if (check)
            ++correct;
        else
            ++wrong;
    }

    // printf("\n");
    // printf("%d %d", correct, wrong);

    double accuracy = (double)correct / (double)(correct + wrong);

    return accuracy;
}

// void makeAndForwardSet(point *point_set, int size, int start, int end, int k, int p)
// {

//     point *train_set, *test_set;
//     int test_size = end - start;

//     int i = 0;
//     while (i < start)
//     {

//         train_set[i] = point_set[i];
//         ++i;
//     }
//     while (i < end)
//     {
//         printf("\n not here \n");
//         printf("\n i= %d \n", i);
//         test_set[i - start] = point_set[i];

//         ++i;
//     }

//     while (i < size)
//     {

//         train_set[i - test_size] = point_set[i];

//         ++i;
//     }
//
// classifyAndValidateSet(train_set, size - test_size, test_set, test_size, k, p);
// }

void performRFoldCrossValidation(point *point_set, int size, int k, int p)
{
    float fold_size = (float)size / (float)FOLDS;
    int folds[FOLDS];
    for (int i = 0; i < FOLDS; ++i)
    {
        folds[i] = (int)(i * fold_size);
    }

    double accuracy = 0;

    for (int i = 0; i < FOLDS - 1; ++i)
    {
        accuracy += classifyAndValidateSet(point_set, size, k, p, folds[i], folds[i + 1]);
    }

    accuracy += classifyAndValidateSet(point_set, size, k, p, folds[FOLDS - 2], size);

    accuracy /= (double)FOLDS;
    printf("accuracy: %lf", accuracy);
}

int get_lines(char *file_name)
{
    char ch;
    int lines = 1;
    FILE *inputFile = fopen(file_name, "r");
    while (!feof(inputFile))
    {
        ch = fgetc(inputFile);
        if (ch == '\n')
        {
            lines++;
        }
    }

    fclose(inputFile);
    return lines;
}

point *read_from_file(char *file_name, point *point_set)
{
    FILE *inputFile = fopen(file_name, "r");
    int cls;
    double feature;

    int point_iter = 0;
    while (!feof(inputFile))
    {
        double farr[NO_OF_FEATURES];
        int class;
        for (int i = 0; i < NO_OF_FEATURES; ++i)
        {
            fscanf(inputFile, " %lf", &farr[i]);
        }

        fscanf(inputFile, " %d", &class);

        point_set[point_iter++] = init_point(farr, 0, class);
    }

    fclose(inputFile);

    return point_set;
}

int main()
{
    /* For dataset 1 - seeds, use the following parameters */
    // Dataset 1
    NO_OF_FEATURES = 7;
    NO_OF_CLASSES = 3;
    CLASS_OFFSET = 1;
    char *file_name = "rand_seeds_dataset.txt";

    /* Comment the above parameters and use the following for 2nd dataset */

    // Dataset 2
    /*
    NO_OF_FEATURES = 64;
    NO_OF_CLASSES = 10;
    CLASS_OFFSET = 0;
    char *file_name = "spaced_optdigits.txt";
    */

    int lines = get_lines(file_name);
    point *point_set = malloc(lines * sizeof(point));

    point *pset = read_from_file(file_name, point_set);

    point base = point_set[0];

    int K = 4, P = 1;
    // bool b = classifyAndValidate(pset, base, lines, K, P);

    printf("started. This may take a while depending on the dataset.\n\n");
    for (int k = 1; k <= 10; ++k)
    {
        for (int p = 1; p <= 10; ++p)
        {
            printf("\n k:%d p:%d ", k, p);
            performRFoldCrossValidation(point_set, lines, k, p);
        }
    }
    // for (int i = 0; i < K; ++i)
    // {
    //     printf("%lf %d \n", neighbours[i].dist, neighbours[i].class);
    // }

    // double fv1[] = {3.0, 0.0}, fv2[] = {0.0, 4.0};

    // p1 = init_point(fv1, 1);
    // p2 = init_point(fv2, 2);

    // printf("%lf", getMinkowskiDistance(p1, p2, 2));
    return 0;
}
