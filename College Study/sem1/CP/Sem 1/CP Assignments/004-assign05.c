/* Program     : Assignment 5
   Roll No     : 201701004
   Name        : Adwait Thattey
   File        : 004-assign05.c
   Last modified  : 21 September 2017 17:45 hrs	 


*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{ 
  /* Problem 1*/
  
  printf("Problem 1..\n\n");
  int size1 , i1;
  int arr1[20];
  
  printf("Problem 1...\n\n");
  srand((unsigned int) time(NULL));
  size1 = rand()%9 + 12;
  printf("\n Random number generated is : %d \n This is the size of array. \n",size1);
  srand((unsigned int) time(NULL));
  
  for(i1=0;i1<size1;++i1)
  	arr1[i1]=(rand()%100);
  	
  printf("\n Random numbers generated inside array\n\n Current Array is :");
  
  for(i1=0;i1<size1;++i1)
  	printf("%d  ",arr1[i1]);
  	
  printf("\n\n Array after performing required tasks is :\n\n");
  
  for(i1=0;i1<size1;++i1)
  {	if((i1%2) == 0) arr1[i1]*=arr1[i1];
     else arr1[i1]*=3;
  }	
  
  for(i1=0;i1<size1;++i1)
  	printf("%d  ",arr1[i1]);
  	
  	
  /* Problem 1 End */
  
  /* Problem 2  */
  
  printf("\n\n\n Problem 2 \n\n");
  int arr2[10] = {4,9,3,8,17,96,44,97,68,51};
  int i2,j2,flag2;
  printf("\n Current array is \n\n");
  
   for(i2=0;i2<10;++i2)
  	printf("%d  ",arr2[i2]);
  	
   printf("\n \nPrime numbers and their positions are :\n\n");	
  
  for(i2=0;i2<10;++i2)
  {	flag2=0;
  	
  	for(j2=2;j2<=arr2[i2]/2;++j2)
  	{ if((arr2[i2]%j2)==0)
  		{flag2=1;break;}
  	}
  	
  	if(flag2==0)
  	{ printf(" %d  at position %d  \n",arr2[i2],i2); }
  	
  }	
  
  
  
  /* Problem 2 End */
  
  /* Problem 3  */
  	
  printf("\n\nProblem 3...\n\n");	
  int size3 , i3;
  float arr3[20] , temp3;
  srand((unsigned int) time(NULL));
  size3=rand()%11 + 10;
  
  for(i3=0;i3<size3;++i3)
  	arr3[i3]= rand()%100 + rand()/123456789.0;
  	
  	
  printf(" Randomly generated size is %d \n Random float numbers generated inside array\n Current array is :\n\n ",size3);
  
  
  for(i3=0;i3<size3;++i3)
  printf("%.2f  ",arr3[i3]);
  
  for(i3=0;i3< size3/2;++i3)
  {  temp3 = arr3[i3];
  	arr3[i3] = arr3[size3 - i3 - 1];
  	arr3[size3 - i3 - 1] = temp3;
  
  }
  
  printf("\n\n Array after performing required task is.. \n\n");
  
  
  for(i3=0;i3<size3;++i3)
  printf("%.2f  ",arr3[i3]);
  
  /* Problem 3 End  */
  
  
  
  
  /* Problem 4  */
  
  printf("\n\nProblem 4....\n\n");
  
  char arr4[20] = "PREETHI KEERTHI" , temp4;
  int i4;
  printf("Initial String is: \n\n");
  printf("%s",arr4);
 
  for(i4=0;i4<=6;++i4)
  { temp4 = arr4[i4];
    arr4[i4] = arr4[8+i4];
    arr4[8+i4] = temp4;
  }
  
  printf("\n\nAfter Swapping string is : \n\n");
  
  printf("%s \n\n",arr4);
  
 
 /* Bonus String   */
 
 
 char arr5[51] , temp5;
 int l1,l2,i5,j5,size5,n5,d5,flag=0;
 printf("\n\n Enter your First Name and Last Name seperated by a space.  (Example: Adwait Thattey) .  Max total characters allowed = 50 \n ");

 scanf("%[^\n]arr5",arr5);
   
 for(i5=0;i5<50;++i5)
 { if(arr5[i5]==' ') l1 = i5;
   else if (arr5[i5]=='\0') {l2 = i5 - l1 - 1;break;}
 }
 
 size5 = i5;
 
 if(l1>l2)
 {  for(j5=0;j5<size5/2;++j5)
     {  temp5 = arr5[j5];
  	   arr5[j5] = arr5[size5 - j5 - 1];
  	   arr5[size5 - j5 - 1] = temp5;
  	   flag=1;
  
     }
     
      l1 = l1 + l2;
  	   l2 = l1 - l2;
  	   l1 = l1 - l2;
 } 
 
  
   
 for(i5=l2 + 1,j5=0;i5<size5;++i5,++j5)
 { temp5 = arr5[i5];
   arr5[i5] = arr5[j5];
   arr5[j5] = temp5;
 
 }
  
  n5 = size5 - l1;
 d5 = l2 - l1;
 
 

 
 for(;d5>0;--d5)
  { temp5 = arr5[n5-1];
     for(i5=n5-1;i5>0;--i5)
       arr5[i5]=arr5[i5-1];
  
    arr5[0] = temp5;
  
  
  }
 
 
  
  
  if(flag==1)
  {      for(j5=0;j5<size5/2;++j5)
          {  temp5 = arr5[j5];
  	        arr5[j5] = arr5[size5 - j5 - 1];
  	         arr5[size5 - j5 - 1] = temp5;
  	          
          }
  	   
  
  }
  
   printf("Reverse is : %s",arr5);
  
  	
  
  
 

 return 0;
}
