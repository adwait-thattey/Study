#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrix(long long int N) {


	int Mat1[1][N] , Mat2[N][1];

	for(int i=0;i<N;++i) {
		
			Mat1[0][i] = 1;
			Mat2[i][0] = 1;
	
	}

	int Mat3[1][1];

	
			Mat3[0][0] = 0;
			for(int k=0;k<N;++k) {
				Mat3[0][0]+=Mat1[0][k]*Mat2[k][0];
			}
}

int main(int argc , char* argv[]) {

	if(argc<2) {
		return -1;
	}
	long long int N = atoi(argv[1]);
	clock_t begin = clock();
	
	for(int x=0;x<1000;++x) {
		multiplyMatrix(N);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf",time_spent);
	FILE *F;
	F = fopen("test.bin","wb");

	double T = time_spent;

	fwrite(&T, sizeof(T), 1, F);

	fclose(F);	

	return 0;
}
