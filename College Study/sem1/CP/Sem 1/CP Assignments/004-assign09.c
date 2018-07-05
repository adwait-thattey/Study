/*
Name	: Adwait Thattey
Roll Number : 201701004
File Name  : 004-assign09.c
Last Modified : 22 October 2017 , 22:00 hrs
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question1();
void question2();
void question3();
void question4();
void subtask_q1(int * , int);
int gcd(int ,int);
int retSum(int , int);
int returnIndexOf(int * , int , int , int);
int isRequiredSubMatrix(int* , int);
int rowSum(int* , int);
int colSum(int* , int);

int size_4 = 6;
int main()
{	
	srand((unsigned int)time(NULL));
	question1();
	question2();
	question3();
	question4();
	return 0;
	
}

void question1()
{
	printf("\n\n Question 1 \n\n");
	
	int size = rand()%11 + 20;
	int Arr[size];

	for(int i=0;i<size;++i)
		Arr[i]=rand()%100;
	
	printf("\n Array :\n\n");
	for(int i=0;i<size;++i)
		printf("%3d",Arr[i]);
	
	printf("\n\nConsective odd elements , their sum and gcd\n\n");
	subtask_q1(Arr,size);
	
	
	
}

void question2()
{	
		printf("\n\n Question 2 \n\n");

	int size=50,Arr[size];
	for(int i=0;i<size;++i)
		Arr[i]=rand()%100;
	
	printf("Array : \n");
	
	for(int i=0;i<size;++i)
		printf(" %2d",Arr[i]); 
	printf("\n\n Consective Pair of elements whose sum is also present are : \n\n");
	int count=0;
	for(int i=0;i<size-1;++i)
	{	int Sum = retSum(Arr[i],Arr[i+1]);
		int temp = returnIndexOf(Arr,size,Sum,0);
		
		if(temp==-1) continue;
		++count;
		printf("\n%2d  &  %2d  :  Sum = %3d",Arr[i],Arr[i+1],Arr[temp]);
		
		
		
	}
	
	if(count==0) printf("No Occurences... Please Try Again");
}

void question3()
{
	
	printf("\n\n Question 3 \n\n");
	
	
	int Arr[]={1,3,4,5,6,2,3,8,7,6,5,4,3,2,3,4,2,5,1,8,9,4,3,2,1,5,2,6,7,8} , size=30;
	
	printf("Array :\n");
	
	for(int i=0;i<size;++i)
		printf("%2d",Arr[i]);
	
	printf("\n\n Subarrays of lenth 3 whose reflexive image is also present in the Array are  :\n");
	for(int i=2;i<=size-4;++i)
	{	
		for(int start=i+1;start<=size-3;)
		{	
			int index = returnIndexOf(Arr,size,Arr[i],start);
			//printf("\n%d  %d  ",i,index);
			if(index==-1) break;
			
			if(Arr[i-1]==Arr[index+1])
			{	if(Arr[i-2]==Arr[index+2])
				{  printf("\n%2d%2d%2d  & %2d%2d%2d    at    %2d-%-2d   &  %2d-%-2d",Arr[i-2],Arr[i-1],Arr[i],Arr[index],Arr[index+1],Arr[index+2],i-2,i,index,index+2);
					break;
				}
				
				else
				{start=index+1;
					continue;
				}	
			}
			else start=index+1;
		}
		
	}
	
}

void question4()
{		
		printf("\n\n Question 4  \n\n");
		
		
		size_4=rand()%4+5;
		int Arr[size_4*size_4];
		
		printf("Matrix that is stored as an 1-D  Array  :  \n\n");
		for(int i=0;i<size_4*size_4;++i)
			Arr[i]=rand()%21+10;
		
		for(int i=0;i<size_4;++i)
		{	for(int j=0;j<size_4;++j)
			{	printf("%3d ",Arr[i*size_4 + j]);
			}
			printf("\n");
		}
		
		printf("\n\n Submatrices of order 3 whose center element is even and their row and column Sum  : \n");
		for(int i=0;i<size_4-2;++i)
			for(int j=0;j<size_4-2;++j)
			{
				if(isRequiredSubMatrix(Arr,i*size_4 + j))
				{ printf ("\n\n");
					printf(" %3d %3d %3d \n %3d %3d %3d \n %3d %3d %3d ",Arr[i*size_4 + j],Arr[i*size_4 + j + 1],Arr[i*size_4 + j + 2],Arr[(i+1)*size_4 + j],Arr[(i+1)*size_4 + j + 1],Arr[(i+1)*size_4 + j + 2],Arr[(i+2)*size_4 + j],Arr[(i+2)*size_4 + j + 1],Arr[(i+2)*size_4 + j + 2]);
					printf("\n \n  Sum of Row 1 = %d  ,  Sum of Row 2 = %d  ,  Sum of Row 3 = %d  \n  Sum of Column 1 = %d  ,  Sum of Column 2 = %d  ,  Sum of Column 3 = %d",rowSum(Arr,i*size_4 + j),rowSum(Arr,(i+1)*size_4 + j),rowSum(Arr,(i+2)*size_4 + j),colSum(Arr,i*size_4 + j),colSum(Arr,i*size_4 + j + 1),colSum(Arr,i*size_4 + j + 2)); 
				}
				
			}
			
}

void subtask_q1(int Arr[] , int size)
{		int odd1 , odd2;
		for(int i=0;i<size;++i)
			if(Arr[i]%2) {odd1=i; break;}
			
		for(int i=odd1+1;i<size;++i)
		{	if(Arr[i]%2 == 0) continue;
			odd2=i;
			printf("\n %2d  & %2d  :   Sum  = %3d \t GCD = %2d",Arr[odd1],Arr[odd2],Arr[odd1] + Arr[odd2],gcd(Arr[odd1],Arr[odd2]));				
			
			odd1=odd2;
		
		}
		
}

int gcd(int a , int b)
{
	while(a%b !=0)
	{	int temp = a%b;
		a = b;
		b = temp;
	}
	
	return b;
}

int returnIndexOf(int Arr[] , int size ,  int n , int start)
{	/* This Function returns the Index of first 'n' that it encounters in the given array. It starts searching for the 'n' from the start. */
	/* It returns -1 if element is not found*/
	
	for(;start<size;++start)
	{	if(Arr[start]==n) return start;		
	}
	
	return -1;
}	

int isRequiredSubMatrix(int Arr[] ,  int k)
{	int center = k + size_4 + 1;
	if(Arr[center]%2==0) return 1;
	return 0;
}

int rowSum(int Arr[] , int x)
{	int sum = Arr[x] + Arr[x+1] + Arr[x+2];
	return sum;
}

int colSum(int Arr[] , int x)
{	int sum = Arr[x] + Arr[x + size_4] + Arr[x + 2*size_4];
	return sum;	
}
int retSum(int a,int b)	
{return a+b;
}	