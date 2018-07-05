#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrix(long long int N)
{

	int Mat1[1][N], Mat2[N][1];

	for (int i = 0; i < N; ++i)
	{

		Mat1[0][i] = 1;
		Mat2[i][0] = 1;
	}

	int Mat3[1][1];

	Mat3[0][0] = 0;
	for (int k = 0; k < N; ++k)
	{
		Mat3[0][0] += Mat1[0][k] * Mat2[k][0];
	}
}

int main()
{
	FILE *F;
	F = fopen("data.csv", "w");
	fputs("Memory , Time\n", F);
	printf("%7s  %15s msec \n", "N", "Time Required");
	long int N;
	for (N = 1; N < 250000; N += 1024)
	{
		
		clock_t begin = clock();
		
		multiplyMatrix(N);

		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		char strtime[100];

		snprintf(strtime, 100, "%ld,%lf\n", 8 * N + 16, time_spent);

		fputs(strtime, F);

		printf("%7ld  %8lf sec \n", N, time_spent);
	}
	fclose(F);
	return 0;
}
