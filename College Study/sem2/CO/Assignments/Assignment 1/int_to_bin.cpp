
#include <time.h>
#include<bits/stdc++.h>
using namespace std;


void int_to_binary(unsigned int a){
	//unsigned int b=1;
	char len[32];
	for(int i=0;i<32;i++){
		//cout<<a%2<<endl;
		if(a%2==0)
			len[31-i]=48;
		else
			len[31-i]=49;
		a=a/2;
		
		
	}
	cout<<"your number is\n";
	for(int i=0;i<32;i+=8)
		
		cout<<len[i]<<len[i+1]<<len[i+2]<<len[i+3]<<len[i+4]<<len[i+5]<<len[i+6]<<len[i+7]<<" ";
}

void long_to_binary(unsigned long a){
	//unsigned int b=1;
	char len[64];
	for(int i=0;i<64;i++){
		//cout<<a%2<<endl;
		if(a%2==0)
			len[63-i]=48;
		else
			len[63-i]=49;
		a=a/2;
		
		
	}
	cout<<"your number is\n";
	for(int i=0;i<64;i+=8)
		
		cout<<len[i]<<len[i+1]<<len[i+2]<<len[i+3]<<len[i+4]<<len[i+5]<<len[i+6]<<len[i+7]<<" ";
}


void char_to_binary(int a){
	//unsigned int b=1;
	char len[8];
	for(int i=0;i<8;i++){
		//cout<<a%2<<endl;
		if(a%2==0)
			len[7-i]=48;
		else
			len[7-i]=49;
		a=a/2;
		
		
	}
	cout<<"your character is\n";
	for(int i=0;i<7;i+=8)
		
		cout<<len[i]<<len[i+1]<<len[i+2]<<len[i+3]<<len[i+4]<<len[i+5]<<len[i+6]<<len[i+7]<<" ";
}


int main(){
	
	cout<<"\nenter a number\n";
	
	int a;
	cin>>a;
	unsigned int c=a;
	
		int_to_binary(c);
	long a1;
	unsigned long c1;
	cout<<"\n\n\nenter a long number\n";
	cin>>a1;
	c1=a1;
	
	long_to_binary(c1);
	
	
	char a2;
	int c2;
	cout<<"\n\n\nenter a character\n";
	cin>>a2;
	c2=int(a2);
	
	char_to_binary(c2);
	return 0;
}


/*void binary(int num)
{
//1010            
    int rem;
 
    if (num <= 1)
    {
        cout << num;
        return;
    }
    rem = num % 2;
    binary(num / 2);
    cout << rem;
}*/


