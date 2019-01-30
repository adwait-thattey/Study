#include <stdio.h>
// #include <stdlib.h>

int main()
{
    FILE *inputFile = fopen("inp.txt", "r");
    int n;
    while (!feof(inputFile))
    {
        fscanf(inputFile, " %d", &n);
        printf("%d", n);
        fscanf(inputFile, " %d", &n);
        printf("%d", n);
        fscanf(inputFile, " %d", &n);
        printf("%d\n", n);
    }
}