#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void question1();
void question2();
void arrayPrint(int* , int);
void arrayReverse(int* , int);
int checkPrime(int);
int getPrimeSum(int , int);
void question3();
void question4();
void subtask_3_1(int* , int , int , int);
int move(int* , long unsigned int , int , int , int , int ,int ,int);
int checkMoveFeasibility(int* , long unsigned int , int , int);
int length(int);


int q4_size;
int main()
{   srand((unsigned int)time(NULL));
	question1();
    question2();
   question3();
    question4();

	return 0;
}

void question1() {

     printf("Question 1....\n\n");
	int Arr[] = {1, 3, 4 ,5 ,6 ,2, 3, 8, 7, 6, 5, 4, 3, 2, 3, 4, 2, 5, 1, 8, 9, 4, 3, 2, 1, 5, 2 ,6, 7, 8};

	int size = 30;
	printf("Array : \n");
	arrayPrint(Arr , size-1);
	printf("\n\nReversed Array : \n");
	arrayReverse(Arr , size-1);
    arrayPrint(Arr , size - 1);


}

void question2() {
printf("\n\nQuestion2...\n\n");
int min=rand()%11 + 10 , max=rand()%11 + 30;
int sum = getPrimeSum(min , max);
printf("\nSum of Prime numbers between %2d and %2d is %3d",min,max,sum);


}

void question3()
{   printf("\n\nQuestion 3 ...\n\n");
    int Arr[] = {18, 11, 5, 15, 10, 3, 14, 8, 1, 12, 7};
    int size = 11;
    subtask_3_1(Arr , size , 0 , 0);


}

void question4()
{   printf("\n\nProblem 4..\n\n");
    int n=4;  //size of the matrix
    int s = 0 , t=11; //start and end index according to the question
    int Arr[n*n];
    for(int i=0;i<n*n;++i)
        Arr[i]=rand()%10;
    printf("%d x %d Matrix (stored as 1-D Array) :\n\n",n,n);



     for(int i=0;i<n;++i)
      {
          for(int j=0;j<n;++j)
            printf("%2d ",Arr[i*n + j]);

        printf("\n");
      }
    int Si,Sj,Ti,Tj;
    Si=s/n;
    Sj=s%n;
    Ti=t/n;
    Tj=t%n;
     printf("\nTaking start position as %d - %d in Matrix = %dth position in Array\n",Si,Sj,s);
     printf("\nTaking end position as %d - %d in Matrix = %dth position in Array\n",Ti,Tj,t);
     printf("\nThe total number of possible moves according to given question are:");

     int D=Ti-Si , R=Tj - Sj;
     long unsigned int key=0;
     q4_size=n;
     int pathCount = move(Arr,key,0,0,D,R,s,t);
     printf("%d\n\n",pathCount);

}

void subtask_3_1(int Arr[] , int size , int i , int k)
{
    static int count=0;

    if(count>=11) return;

    printf("%d ",Arr[(i+k*3)%11]);
    ++count;

    subtask_3_1(Arr , size , i , k+1);
}

void arrayPrint(int Arr[] , int n) {
	if(n<0) return;
	arrayPrint(Arr , n-1);
	printf("  %d",Arr[n]);

}

void arrayReverse(int Arr[] , int n) {
 static int i = 0;
 int temp = Arr[i];
 Arr[i]=Arr[n-i];
 Arr[n-i]=temp;

    if((2*i)>=n-1) return;

     else
     { ++i;
        arrayReverse(Arr , n);

     }
}

int getPrimeSum(int min , int max) {

    static int sum = 0;

    if(min>max) return sum;

    else
    {
        if(checkPrime(min))
            sum+=min;


        getPrimeSum(min+1 , max);
    }


}

int checkPrime(int n)
{   if(n==0 || n==1) return 0;

    int flag=0;
    for(int i=2;i<=n/2;++i)
    {
        if((n%i)==0)  {
            flag=1;
            break;
        }

    }

    if(flag==0) return 1;

    return 0;
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

int move(int Arr[] , long unsigned int key , int curi , int curj , int D , int R , int s , int t)
{   static unsigned int pathCount = 0;
    if((curi<D)&&(length(key)<D+R))
    {

        long unsigned int temp;
        temp = key*10 + 1;

        move(Arr , temp , curi + 1 , curj , D , R ,s ,t);
    }

    if(curj<R&&(length(key)<D+R))
    {   long unsigned int temp;
        temp=key*10 + 2;

        move(Arr ,temp, curi , curj + 1 , D , R,s,t);
    }

    if(length(key)>=(D+R))
      {

          int chk;
          chk = checkMoveFeasibility(Arr,key,s,t);

          if(chk==1)
           ++pathCount;


      }

    return pathCount;

}

int checkMoveFeasibility(int Arr[] , long unsigned int key , int s , int t)
{

    int primect=0;
    if(checkPrime(Arr[t])) {primect++;}
    while(key>0)
    {
        int temp=key%10;
        if(temp==1){
            if(checkPrime(Arr[t-q4_size])) ++primect;
            t-=q4_size;


        }

        else if(temp==2){
            if(checkPrime(Arr[t-1])) ++primect;
            t-=1;

        }
        key/=10;
    }

    if(primect>=2)
       {

           return 1;
       }

     else return 0;
}




