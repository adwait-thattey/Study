/* *Program : Assignment 3
   *Name    : Adwait (004)
   *File     : 004-assign01.c
   *Last Modified : August 31 2017 (17:38 hrs)

*/

#include <stdio.h>




int main()
{

			// Problem 1

printf("\n\nProblem 1\n\n");

printf("Values Assigned :\n");
int x=2,y=5,z=1,k;

printf("x = %d\n y = %d \n z = %d \n",x,y,z);
k = ++x/3*y++ - --z * 2/y++ * ++x;

printf("\n\n Values after execution of first statement\n\n x = %d , y = %d , z = %d , k = %d \n\n",x,y,z,k);

printf("Output of second expression = %d\n value of x = %d",x++*x++ + ++x,x);


			// Problem 2
printf("Problem 2..\n\nEnter a positive Integer less than or equal to 255\n");

int g,temp,count=0,count2=0;

scanf("%d",&g);
temp=g;
for(int i=0;i<8;++i)
{  
  if((temp&1)==1)
	++count;
  else if((temp&1)==0) ++count2;
   
   temp = temp>>1;
}

if(count>4)
printf("%d",g);

else printf("number of 0 bits = %d",count2);




		// Problem 3
printf("\n\nProblem 3..\n\n");

int n=7,k1=1,temp2,t3; // k1 is used as k is already declared for prb 1


printf("Enter 2 numbers n & k \n");
scanf("%d %d",&n,&k1);
temp2 = 1<<k1;
t3 = temp2^n;
printf("Number with %dth bit inverted is %d",k1,t3);

		// Problem 4

printf("\n\nProblem 4...\n\n");

printf("Enter a number \n");
int m,n3,k3;

scanf("%d",&m);

n3 = m<<1;
k3 = ~n3;

printf("\n\n m = %d\n n =  %d\n k3 =  %d",m,n3,k3);



		//Problem 5

int x1,y1;

printf("\n\nProblem 5...\n\n");



printf("Enter 2 numbers x and y\n");
scanf("%d %d",&x1,&y1);

y1 = y1^x1;
x1 = x1^y1;
y1 = y1^x1;

printf("\nSwapped values of x and y are : %d %d",x1,y1);





return 0;

  
}



