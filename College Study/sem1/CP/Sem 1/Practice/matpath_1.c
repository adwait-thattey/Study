#include<stdio.h>

void permutate(char str[] , int , int);
void swap(char str[] , int , int);

int main()
{
    unsigned int x=5;
    printf("%u",(unsigned int)~x);


    /*char str[]="DDRR";
    //swap(str,1);
	//printf("%s",str);

 permutate(str,0,4);
    return 0;*/


}

void permutate(char str[] , int start , int end)
{
    int range = end - start;

	if(range==1)printf("%s\n",str);

	else
	{
		for(int i=0;i<range;++i)
		{
			swap(str , start , start+i);
			//if(str[start]==str[start+i]) ++start;
			permutate(str , start+1 , end);
			swap(str , start , start+i);
		}
	}

}

void swap (char str[] , int start , int i)
{
    char temp = str[start];
    str[start] = str[i];
    str[i]=temp;
}
