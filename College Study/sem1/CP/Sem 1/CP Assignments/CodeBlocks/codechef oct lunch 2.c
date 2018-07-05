#include <stdio.h>
#include <math.h>

int getsum(int n)
{int temp,sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }

    return sum;
}

int length(int n) {
    int i=0;

    while(n>0)
    {
        ++i;
        n/=10;
    }
    return i;
}

int main()
{
    int A;
    scanf("%d",&A);
    int l=length(A);
    int temp=A,pos;
    for(pos=1;pos<=l;++pos)
    {   int remain=(temp%((long unsigned int)pow(10,pos-1)));
        temp/=pow(10,pos);
        temp=temp*pow(10,pos-1) + remain;
        printf("%d\n",temp);
        temp=A;

    }

    return 0;
}


