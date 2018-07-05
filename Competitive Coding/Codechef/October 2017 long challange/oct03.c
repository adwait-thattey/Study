#include <stdio.h>
#include <math.h>

int main()
{unsigned int T;
	long unsigned int N;
	int i;
	
	scanf("%u",&T);
	while(T>0)
	{	--T;
		scanf("%lu",&N);
		
		for(i=1;i<=N;++i)
		{if((i==1)){printf("%u ",(unsigned int)pow(2,31));continue;}
		 if((i==N)){printf("%u ",(unsigned int)0);continue;}
			
			printf("%u ",(unsigned int)2);
			
		}
		
	}
	
 return 0;	
	
}