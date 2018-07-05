/*  * Program : Assignment 2
    * Name    : Adwait Thattey (004)
    * File    : 004-assign02.c
    * Last Modified : August 24 2017 (16:53 hrs)
*/


#include<stdio.h>


int main()
{
   /*  Problem 1 */
  printf("\nProblem 1 : \n\n");
  float cl , fr;
  printf("Enter the temprature in degree Fahrenheit\n");
  scanf("%f",&fr);
  
  cl = (5.0/9.0)*(fr-32);
  printf("\n\nTemprature in degree celcius is : %f \n",cl);





   /* Problem 2  */



printf("\n\nProblem 2 :\n\n");
 int x,y,z;
printf("Enter the value of x , y , z\n");
scanf("%d %d %d",&x,&y,&z);
printf(" \n\n  Before Evaluation : \n x = %d \n y = %d \n z = %d \n\n",x,y,z);

if(y==1)
{ x = y+1;
  z = x++;
}
else z=x++;

printf("After Evaluation : \n x = %d \n y = %d \n z = %d \n\n",x,y,z);





   /* Problem 3  */


printf("\n\nProblem 3 :\n\n");
 
int x1,y1,z1; 
printf("Enter the values of x,y,z\n");  // Names are x1,y1,z1 as x,y,z are already declared in problem 2
scanf("%d %d %d",&x1,&y1,&z1);
z1 = x1+y1+z1/4%++x1*2-1; 

int s,l;
if((x1>y1)&&(x1>z1)) l=x1;
if((y1>x1)&&(y1>z1)) l=y1;
if((z1>x1)&&(z1>y1)) l=z1;
if((x1<y1)&&(x1<z1)) s=x1;
if((y1<x1)&&(y1<z1)) s=x1;
if((z1<x1)&&(z1<y1)) s=x1;
if((x1==y1)&&(y1==z1)) s=l=-3;

if(s!=-3)
{ printf(" \n\n Largest number is %d and smallest number is %d ",l,s);}
else printf(" \nAll are equal ");




       /* Problem 4  */


printf("\n\nProblem 4 :\n\n");
int a,b,c,a1;
printf("Enter the values of a,b,c\n");
scanf("%d %d %d",&a,&b,&c);
a1 = ++a;
++a + ++a + b-- - c--;
printf("\nThe Values of a , b , c are : %d %d %d",a,b,c);



             /* Problem 5  */




printf("\n\nProblem 5 :\n\n");
int d;
float f=2.3543;
d=1256;
int sd = sizeof(d);
int sf = sizeof(f);
int i = (int)f;

printf(" Size of 1256 is %d bytes , Size of 2.3543 is %d bytes \n The decimal part of 2.3543 is %f \n",sd,sf,f-i); 

char str[14];

printf("\n Enter a String of length 13 characters...\n");
scanf("%s",str);

printf("\n The first 5 characters are : %.5s \n\n",str);




   /* Problem 6  */




printf("\n\nProblem 6 :\n\n");

int a2=20,b2=10,c2=15,d2=5,e2; //   a2,b2,c2,d2,e2 are used as a,b,c already exist

a2 = 5*3 + 2 - 4;
a2 = 2+4+3*5/3-5;
e2 = a2+b2*c2/d2;
a2 = 5*3%6-8+3;
e2 = a2+b2*c2/d2;
b2 = 3%4*1-4/2;
e2 = a2+b2*c2/d2;


printf(" values of a,b,c,d,e are : %d %d %d %d %d \n\n",a2,b2,c2,d2,e2);



          /* End   */








 return 0;
}
