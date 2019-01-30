#include <stdio.h>
#include <stdlib.h>

typedef struct ABC
{
    int *x;
} abc;

abc init_abc(int a, int b, int c)
{
    abc g;
    g.x = malloc(3 * sizeof(int));
    g.x[0] = a;
    g.x[1] = b;
    g.x[2] = c;

    return g;
}

abc *filter(abc *arr)
{
    abc *farr;
    farr[0] = arr[0];
    farr[1] = arr[1];
    farr[2] = arr[2];

    return farr;
}

void check_add(abc *x)
{
    printf("%p", x);
}
int main()
{
    abc *arr = malloc(10 * sizeof(abc));
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = init_abc(i, 2 * i, 3 * i);
    }
    abc *farr = filter(arr);
    // for (int i = 0; i < 4; ++i)
    // {
    //     printf("%d %d %d\n", farr[i].x[0], farr[i].x[1], farr[i].x[2]);
    // }

    printf("%p \n", &arr[0]);
    check_add(&arr[0]);

    return 0;
}