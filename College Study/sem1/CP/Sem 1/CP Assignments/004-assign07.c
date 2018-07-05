#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{	printf("\n ***Problem 1*** \n\n");
	int i1,j1,k1,n1,size1=3,trace1=0;
	for(n1=1;n1<=10;++n1)
	{	int A1[3][3];
		srand(RAND_MAX/n1); 
		trace1=0;
		for(i1=0;i1<size1;++i1)
		{	for(j1=0;j1<size1;++j1)
			{		
				A1[i1][j1]=rand()%99+1;
				
				if(i1+j1==size1-1)
				{ A1[i1][j1]-=A1[i1][j1]%3;
				
				  if(A1[i1][j1]%2==0) A1[i1][j1]+=3;
				
				}
				
				if(i1==j1) trace1+=A1[i1][j1];
			
			}
		
		}
		
		printf("Matrix %d \n",n1);
		
		for(i1=0;i1<size1;++i1)
		{	for(j1=0;j1<size1;++j1)
			{		
				printf("%3d ",A1[i1][j1]);
			
			}
			
			printf("\n");
		
		}
		printf("\n\tTrace = %d",trace1);
		printf("\n\n");
		
		
		
		
		
	
	}
	
	
	printf("\n\n***Problem2***\n\n");
	
	int size2=rand()%4 + 7;
	int A2[size2][size2];
	int a2,b2,i2,j2,k2,sum2,count=0;
	
	srand((unsigned int)time(NULL));
	printf("Main Matrix :\n\n");
	for(a2=0;a2<size2;++a2)
	{	for(b2=0;b2<size2;++b2)
			{	A2[a2][b2]=rand()%100;
				printf(" %3d",A2[a2][b2]);
			}
		printf("\n");		
	}			
	
	printf("\nSub-Matrices of order 3 having odd diag sum are: \n");
	
do{
	
	for(a2=0;a2<=size2-3;++a2)
	{	for(b2=0;b2<=size2-3;++b2)
		{	sum2=0;
			
			for(i2=a2;i2<=a2+2;++i2)
			{	int temp2=0;
				for(j2=b2;j2<=b2+2;++j2)
				{	
					if(i2==a2+temp2){sum2+=A2[i2][j2];}	
					++temp2;	
				
				}
				
											
			}
			
			
			if(sum2%2)
			{	printf("\nSum=%d\n",sum2);
				++count;
				for(i2=a2;i2<=a2+2;++i2)
					{	for(j2=b2;j2<=b2+2;++j2)
						{	printf(" %3d",A2[i2][j2]);
						}
						printf("\n");							
					}
			}
			
			
			
			
			
			
		
		}
	
	}
	
}while(count==0);

printf("\n\n ***Problem 3*** \n\n");

char tempc,name3[5][16]={"Xiang Wu" , "Raymond Chow" , "Adrian Grozaria" , "Pinar Ozturk" , "Rakesh Ohja"};
int i3,j3,k3,li3[5],s1,s2,temp; // li3 store the position of the first character of last name of each string
//s1,s2 are the strings to be swapped
printf("\nBefore Sorting: \n\n");
for(i3=0;i3<5;++i3) 
{	printf("\n %s",name3[i3]);
}

for(i3=0;i3<5;++i3) 
{	for(j3=0;name3[i3][j3]!='\0';++j3)
		if(name3[i3][j3]==' '){li3[i3]=j3+1;}
	
}

for(s1=0;s1<4;++s1)
{	
	for(s2=s1+1;s2<5;++s2)
	{	//printf("%d %d",s1,s2);
		int tli1=li3[s1],tli2=li3[s2];
		while(name3[s1][tli1]==name3[s2][tli2])
		{++tli1;
		 ++tli2;
		}
	
	
		if(name3[s1][tli1]>name3[s2][tli2])
		{	temp=li3[s1];
			li3[s1]=li3[s2];
			li3[s2]=temp;
			
			for(int cur=0;cur<=16;++cur)
			{ tempc=name3[s1][cur];
			  name3[s1][cur]=name3[s2][cur];
			  name3[s2][cur]=tempc;
			
			}
		
		}
		
		
	
	}

}

printf("\n\nAfter Sorting Lexicographically: \n");
for(i3=0;i3<5;++i3) 
{	printf("\n %s",name3[i3]);
}


printf("\n\n ***Problem 4*** \n\n");

srand((unsigned int)time(NULL));
float A[20][7];
int i4,j4,k4;
for(i4=0;i4<20;++i4)
	A[i4][0]=rand()%900+100;
	
for(i4=0;i4<20;++i4)
	for(j4=1;j4<7;++j4)
		A[i4][j4]=(float)(rand()%100) + (float)(rand()/RAND_MAX);
		
for(i4=0;i4<20;++i4)
	A[i4][6]=(A[i4][1] + A[i4][2] + A[i4][3] + A[i4][4] + A[i4][5])/5.0;

printf("%12s %6s %6s %6s %6s %6s %6s \n","Roll Number","m1","m2","m3","m4","m5","Avg");

for(i4=0;i4<20;++i4)
	printf("%12d %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f \n",(int)A[i4][0],A[i4][1],A[i4][2],A[i4][3],A[i4][4],A[i4][5],A[i4][6]);	
	
	
	printf("\n\n\n ***Bonus Problem*** \n\n");
int a4,b4;	
for(i4=0;i4<19;++i4)
	for(j4=i4+1;j4<20;++j4)
		if(A[j4][6]>A[i4][6])
			for(a4=0;a4<7;++a4)
			{	temp=A[i4][a4];
				A[i4][a4]=A[j4][a4];
				A[j4][a4]=temp;
			}


printf("%12s %6s %6s %6s %6s %6s %6s \n","Roll Number","m1","m2","m3","m4","m5","Avg");

for(i4=0;i4<20;++i4)
	printf("%12d %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f \n",(int)A[i4][0],A[i4][1],A[i4][2],A[i4][3],A[i4][4],A[i4][5],A[i4][6]);			
		
	
	
	

	
	
	
	


	
	
	
	
	return 0;

}
