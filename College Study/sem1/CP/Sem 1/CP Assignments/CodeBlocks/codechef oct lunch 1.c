#include <stdio.h>

#include <math.h>

int main()
{	unsigned int T;
	scanf("%d",&T);
	while(T>0)
	{	--T;
			long unsigned int a,b;
			scanf("%lu %lu",&a,&b);
			long unsigned int ans=0,i=0;
			long unsigned int temp;
			while(a>0||b>0)
			{

				temp= (a+b)%10;
				ans+=temp*pow(10,i);
				++i;
				a/=10;
				b/=10;

			}

			printf("%lu\n",ans);
	}

	return 0;
}
