#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{	srand((unsigned int)time(NULL));
	char mat[20][20],str[4];
	int i,j,k,a,b,c,flag,seq=20;
	
	for(i=0;i<20;++i)
	{	for(j=0;j<20;++j)
		{mat[i][j]=rand()%26+97;			
		}
	}
	printf("\nRANDOMLY GENERATED 20-20 MATRIX :\n\n");
	for(i=0;i<20;++i)
	{	printf("\n");
		for(j=0;j<20;++j)
		{printf("%c ",mat[i][j]);			
		}
	}
	printf("\n\n\tMATRIX INDEX START FROM 0 TO 19");
	
	
	while((seq--)>0)
	{	str[0]=rand()%26+97;
		str[1]=rand()%26+97;
		str[2]=rand()%26+97;
		str[3]='\0';
		flag=0;
		printf("\n \nRandomly generated string is %s",str);
		
		for(i=0;i<20;++i)
		{	
			//printf("\n %d",i);
			for(j=0;j<20;++j)
			{	//printf("%d ",j);
				if(mat[i][j]==str[0])
				{	int ct=0;
					for(a=i-1;a<=i+1;++a)
					{	//printf("\n %d",a);
						if((i!=0)&&(a<=0)) {ct+=3;continue;}
						if((i!=19)&&(a>=19)) {ct+=3; continue;}
						for(b=j-1;b<=j+1;++b,++ct)
						{	
							if((j!=0)&&(b<=0)) continue;
							if((j!=19)&&(b>=19)) continue;
							if(ct==4){++ct;continue;}
							//printf(" %d",b);
							
							if(mat[a][b]==str[1])
							{	
								if(mat[(2*a)-i][(2*b)-j]==str[2])
								{flag=1;printf("\n\t%s found at %d-%d , %d-%d , %d-%d\t {Index as Row-Column for each character of string}",str,i,j,a,b,(2*a)-i,(2*b)-j);}
							}
						}
						
					}
					
					
				}
				
			}
			
		}
		
		if(flag==0) printf("\n\t%s not found",str);
	}	
	
}	