#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long unsigned int comb(long unsigned int n , long unsigned int r)
{   unsigned int i,j;
	long unsigned int temp=1;
	
	i = (n-r > r)? n-r : r;
	j=n-i;

	
	for(++i;i<=n;++i)
		temp*=i;
	
	for(;j>=1;--j)
		temp/=j;
  
    return temp;
    
}

int main() {
//long unsigned count=0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
   long unsigned int n , k;
    long unsigned int Sum = 0;
    scanf("%lu %lu",&n,&k);
    while(k<=n)
    {	//++count;
		//printf("%lu\n",count);
        Sum+=comb(n,k);
        Sum = Sum%(long unsigned int)(pow(10,9)+7);
        ++k;
    }
	
	 Sum = Sum%(long unsigned int)(pow(10,9)+7);
	//printf("%lu",comb(1000,2));
   
    printf("%lu",Sum);
    return 0;
}