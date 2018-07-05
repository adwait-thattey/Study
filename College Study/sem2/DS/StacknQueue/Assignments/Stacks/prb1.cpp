#include <iostream>
#include <string.h>
#include <stdio.h> 
#define size 1000
using namespace std;

char stack[1000];
int cursize = 0;

void push(char c) {

	if(cursize==size) {
		cout<<"Stack Overflow!!!";
		return;
	}

	stack[cursize] = c;
	++cursize;
	return;
}

char pop() {

	if(cursize<=0) {
		cout<<"Stack Underflow!!!";
		return 'x';
	}

	--cursize;
	char c = stack[cursize];

	return c;
}


int main() {

	 cout<<"Enter Required String : \n";
	 char S[1000];

	 scanf("%[^\n]s",S);

	 for(int i=0;S[i]!='\0';++i){
		
		if(S[i]==' ') {
			while(cursize>0) {
				cout<<pop();
			}
			cout<<" ";
		}
		else
			push(S[i]);
	 }

	 while(cursize>0) {
				cout<<pop();
			}
			cout<<" ";

return 0;

}
