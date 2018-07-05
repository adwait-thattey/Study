#include <stdio.h>

int main()
{unsigned int N,T,P,diff,cake,Pcur;

	scanf("%d",&T);
	
	while(T>0)
	{--T;
	 diff=0;
	 cake=0;
	 scanf("%d %d",&N,&P);
		while(N>0)
		{	--N;
			scanf("%d",&Pcur);
			if(Pcur>=(P/2)) {++cake;continue;}
			if(Pcur<=(P/10)) {++diff;continue;}
			
			
		}
		
		if((cake==1)&&(diff==2)) printf("yes\n");
		else printf("no\n");
		
		
	}
	
}