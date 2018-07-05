#include <stdio.h>
#include <math.h>
long unsigned int calc(int A[] , unsigned int N)
{	long unsigned int TotSum=0,SumCur=0;
	int i,j,k;
	for(i=1;i<N;++i)
	{	TotSum+=A[0]*A[i]*pow(2,N-i);
		SumCur=0;
		for(j=i+1,k=0;j<N;++j,++k)
			SumCur+=A[i]*A[j]*pow(2,N-2-k);
		
		TotSum+=SumCur;	
	}
	
	
	return TotSum%(int)(pow(10,9) + 7);
}

int main()
{long unsigned int Answer;
	int T,i,Ans=0;
	unsigned int N;
	
	scanf("%d",&T);
	long int Cases[T];
	while(T-->0)
	{	scanf("%ud",&N);
		++N;
		int A[N];
		for(i=0;i<N;++i)
			scanf("%d",&A[i]);
	
		Answer = calc(A,N);
		Cases[Ans]=Answer;
		++Ans;
		
	}
	
	for(i=0;i<Ans;++i)
		printf("%ld\n",Cases[i]);
	
 return 0;
}


	