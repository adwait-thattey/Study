#include <stdio.h>
#include <string.h>

void move(long unsigned int , int , int , int);
int length(int);
int count = 0;
int main()
{
    int MAT[3][3]={1,2,3,4,5,6,7,8,9};

    /*for(int i=0;i<3;++i)
    {    for(int j=0;j<3;++j)

            printf("%2d",MAT[i][j]);

         printf("\n");
    }*/

    int key=0;
    move(key,0,0,4);


    return 0;
}


void move(long unsigned int key , int curi , int curj , int n)
{
    if((curi<n-1)&&(length(key)<(2*(n-1))))
    {

        long unsigned int temp;
        temp = key*10 + 1;

        move(temp , curi + 1 , curj , n);
    }

    if(curj<n-1&&(length(key)<(2*(n-1))))
    {   long unsigned int temp;
        temp=key*10 + 2;

        move(temp, curi , curj + 1 , n);
    }

    if(length(key)>=(2*(n-1)))
      { ++count;
          printf("%d\t%d\n",count,key);

      }



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


