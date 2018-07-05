#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(unsigned int*)a - *(unsigned int*)b );
}

int main()
{
	unsigned int N,T,next,k,i;
	scanf("%u",&T);
	
	while(T>0)
	{	--T;
	
		scanf("%u %u ",&N,&k);
		unsigned int Arr[N];
		
		for(i=0;i<N;++i)
		{	scanf("%u",&Arr[i]);
		}
		
		qsort(Arr,N,sizeof(unsigned int),cmpfunc);
		next=0;
		int flag=0;
		
		for(i=0;i<N;++i)
			{	
				if((i>0)&&(Arr[i]==Arr[i-1])) continue;		
		
				while(next<Arr[i])
				{if(k==0){flag=1;break;}
				 ++next;
				 --k;	
				}
				
				if(flag==1) break;
				
				++next;
				
			}
		
		
		next+=k;
		printf("%u\n",next);
	
	
	}
	return 0;
}