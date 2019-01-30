#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NO_OF_FEATURES;

typedef struct POINT
{
    int id;
    double *fv;
    int class;
} point;

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

void randomize_point_set(point *point_set, int lines)
{
    for (int i = lines; i > 0; --i)
    {
        int rand_pos = (rand() % i);
        point ptemp = point_set[rand_pos];
        point_set[rand_pos] = point_set[i - 1];
        point_set[i - 1] = ptemp;
        // printf("%d\n", rand_pos);
    }
}

void writeback(char *file_name, point *pset, int lines)
{
    FILE *fptr = fopen(file_name, "w");
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < NO_OF_FEATURES; ++j)
        {
            fprintf(fptr, "%lf ", pset[i].fv[j]);
        }

        fprintf(fptr, "%d\n", pset[i].class);
    }
    fclose(fptr);
}

int main()
{
    srand(time(0));

    NO_OF_FEATURES = 7;

    int lines = get_lines("seeds_dataset.txt");

    point *point_set = malloc(lines * sizeof(point));

    point *pset = read_from_file("seeds_dataset.txt", point_set);

    randomize_point_set(point_set, lines);

    // for (int i = 0; i < lines; ++i)
    // {
    //     for (int j = 0; j < NO_OF_FEATURES; ++j)
    //     {
    //         printf("%lf ", point_set[i].fv[j]);
    //     }
    //     printf("-> %d \n", point_set[i].class);
    // }

    writeback("small_rand_seeds_dataset.txt", point_set, lines);

    return 0;
}