#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
    int n = 1000, type = 0;
    n = (argc > 1) ? atoi(argv[1]) : n;
    type = (argc > 2) ? atoi(argv[2]) : type;
    char *fs = (argc > 3) ? argv[3] : "inputdata.txt";
    printf("\nn = %d\nOutput = %s\n", n, fs);

    srand((unsigned int)time(NULL));

    FILE *infile = fopen(fs, "w+");

    int i = 0, max = RAND_MAX % 1000000;
    float num = 0.0f, val = 1.0f; 
    for (i = 1; i < n+1; i++ ) {
        if ( type == 2) { /* Reversely Sorted Sequence */
            num = max - val;
            val += rand() / 1234567890.;
        } else if (type == 1) { /* Randomly generated input sequence */
            num = 100 + rand() % (1000000 - 100) + rand() / 1234567890.;
        } else { /* Sorted Sequence */  
            num = 100 + (2 * i) + rand() / 1234567890.;
        }
        fprintf(infile, "%12.2f\n", num);
    }

    fclose(infile);

    return 0;
}

