/* Name: Adwait Thattey
	Roll No: 201701004
	File Name : 004-assign08.c
	Last Updated : 14/10/2017 23:08 hrs
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question1();
void question2();
void question3();
void question4_1();
void question4_2();
int isvovel(char c);
char CaseUp(char c);
int stringlength(char S[]);
int IsAlaphabetOrNumber(char c);
int CheckIfSameWord(char S1[] , char S2[]);

int main()
{
	printf("\n\n Question 1...\n\n");
	question1();
	printf("\n\n Question 2...\n\n");
	question2();
	printf("\n\n Question 3...\n\n");
	question3();
	printf("\n\n Question 4-1...\n\n");
	question4_1();
	printf("\n\n Question 4-2...\n\n");
	question4_2();
	
	
		
	return 0;	
}

void question1()
{	char st,st1,str[]="asdfgkjikuhygtfrdeasdferwqwfrasdfgvcxzsedwrfgvcxasdfghtyuiokjnb";
	int arr[35] ,count=1,max_length=2;
	
	printf("Given String is : \n %s\n\n",str);
	for(int i=0;i<stringlength(str)-1;++i)
	{  char cur_st=str[i];
	   // printf("-%c ",cur_st);
		int cur_count=1;
		for(int j=i+2;j<stringlength(str)-1;++j)
		{	if(str[j]==str[i])
				if(str[j+1]==str[i+ 1])
					++cur_count;	
		}
	
		if(cur_count>count)
		{	count=cur_count;
			st=cur_st;
			st1=str[i+1];
		}	
	}
	
	for(int i=0,j=0;i<stringlength(str)-1;++i)
		{	if(str[i]==st)
				if(str[i+1]==st1)
				{	arr[j]=i;
					++j;
				}	
		}
		
		for(int l=3;l<stringlength(str);++l)
		{	int new_count=1;
			for(int i=1;i<count;++i)
			{	if(str[arr[i]+l-1]==str[arr[0]+l-1])
					++new_count;				
			}
			if(new_count<count)
			{max_length=l-1;
				break;				
			}
			
		}
		
		char temp[max_length];
		for(int i=0;i<max_length;++i)
			temp[i]=str[arr[0]+i];
		temp[max_length]='\0';
		printf("The maximum occuring SubArray is %s of length %d and occurs %d times",temp,max_length,count);
	
		printf("\n The starting Index and Ending Index of each occurance are :\n");
		
		for(int i=0;i<count;++i)
		{printf("%3d  %3d\n",arr[i],arr[i]+max_length-1);
			
		}
	
	
}




void question2()
{	char Arr[]="Ram loves playing cricket and he is very much curious to know about cricket players. His cricket knowledge is far better than his friends and Ram never misses to watch any cricket match either it could be a one day match or test match or a T20 match";
	printf("\n\n");
printf("String : \n\n %s \n",Arr);
int n=stringlength(Arr);
char cur_word[20],temp1[20] , temp2[20];
int count =0;
for(int i=0;i<n;++i)
{	int j,k;
	count=1;
	if(!IsAlaphabetOrNumber(Arr[i])) continue;
	j=0;
	for(j=0;IsAlaphabetOrNumber(Arr[i]);++i,++j)
	{cur_word[j]=Arr[i];
		
	}
	cur_word[j]='\0';
	
	
	j=i;
	int zz;
	for(;j<n;++j)
	{	if(!IsAlaphabetOrNumber(Arr[j]))continue;
		k=0;
		zz=j;
		while(IsAlaphabetOrNumber(Arr[j]))
		{temp1[k]=Arr[j];
		 ++k;
		 ++j;
		}
		temp1[k]='\0';
		
		
		
		if(CheckIfSameWord(cur_word , temp1))
		{  ++count;
			while(zz<k)
			{Arr[zz]=' ';
				++zz;				
			}
		}
		
		
	
	} 
	
	printf("%s -> %d\n",cur_word,count);
	
}
	
	
}




void question3()
{	srand((unsigned int)time(NULL));
	char Arr[7][7] = {"irwtkuy" , "ovwegyr" , "hweijxy" , "tbfpdzm" , "ncvmnlv" , "rdcrusv" , "werwqas"};
		
		for(int i=0;i<7;++i)
		{	for(int j=0;j<7;++j)
				printf("%3c",Arr[i][j]);
		 printf("\n");	
		}
		printf("Index of Vovels is :\n");
		
		for(int i=0;i<7;++i)
		{	for(int j=0;j<7;++j)
			{	if(isvovel(Arr[i][j]))
				{	printf("%d %d \n",i,j);
					Arr[i][j] = CaseUp(Arr[i][j]);
				
				}
		   }
		}
		
		printf("\n\n");
		
		for(int i=0;i<7;++i)
		{	for(int j=0;j<7;++j)
				printf("%3c",Arr[i][j]);
		 printf("\n");	
		}
		
}

int isvovel(char c)
{	switch(c)
	{  case 'a' :
		case 'e' :
		case 'i' :
		case 'o' :
		case 'u' : return 1;
		default  : return 0;
	}
	return 0;

}

char CaseUp(char c)
{

return c-32;
}

void question4_1()
{
  int temp1=0,temp2=1,temp3;
  srand((unsigned int)time(NULL));
  int n=rand()%11 + 20;
  printf("randomly generated n= %d\n", n);
  printf("%d ",temp1);
  while(temp2<=n)
  { printf("%d ",temp2);
	temp3=temp2;
	temp2+=temp1;
	temp1=temp3;
  }
}


void question4_2()
{	 srand((unsigned int)time(NULL));
	unsigned int T,R = rand();
	while(R<100000000)
		R=rand();
		T=R;
	int odd=0;	
	while(R>0)
	{	if(R&1)++odd;
		R/=10;
	}
	printf("The number of odd digits in %u are %d",T,odd);
}

int IsAlaphabetOrNumber(char c)
{
if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'))return 1;

return 0;

}

int CheckIfSameWord(char S1[] , char S2[])
{
	int l1=stringlength(S1) , l2=stringlength(S2);
	if(l1!=l2) return 0;
	
	for(int i=0;i<l1;++i)
	{ if(S1[i]!=S2[i]) return 0;
	
	}

   return 1;
   

}


int stringlength(char S[])
{	int i;
	for(i=0;S[i]!='\0';++i);
	
	return i;
}
