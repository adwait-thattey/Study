#include <iostream>
#include <string.h>
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

	 cout<<"Enter String Consisting of \'(\'\')\'{\'\'}\'\'[\'\']\' \n ";
	 char S[1000];

	 cin>>S;

	 for(int i=0;i<strlen(S);++i) {

	 	switch (S[i]) {

	 		case '(' :
	 		case '[' :
	 		case '{' : push(S[i]);break;
	 		case ')' : if(pop() != '(') {
	 						cout<<"NOT BALANCED!!";
	 						return -1;
	 				   }
	 				   else break;
	 		case ']' : if(pop() != '[') {
	 						cout<<"NOT BALANCED!!";
	 						return -1;
	 				   }
	 				   else break;
	 		case '}' : if(pop() != '{') {
	 						cout<<"NOT BALANCED!!";
	 						return -1;
	 				   }
	 				   else break;

	 	}
	 }

	 cout<<"Balanced";
	 return 0;
}