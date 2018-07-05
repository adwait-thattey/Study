/*
Name	: Adwait Thattey
Roll Number : 201701004
File Name  : 004-assign09.c
Last Modified : 21 October 2017 , 23:10 hrs
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question1();
void question2();
void question3();
void subtask_q1(int * , int);
int gcd(int ,int);
int main()
{
	question1();	
	return 0;
	
}

void question1()
{
	printf("\n\n Question 1 \n\n");
	srand((unsigned int)time(NULL));
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