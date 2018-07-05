#include <iostream>
#include "stack.cpp"
using namespace std;


void disp(stack S) {
	if(S.empty()) {
	 
	 cout<<"-------\nEmpty Queue...!!!\n----------\n";
	 return;

	}
	
	cout<<"----------\n";
	cout<<"  <-- Queue Direction  ----<\n";

	while(!S.empty()) {
		cout<<S.top()<<" ";
		S.pop();
	}

	cout<<"\n----------\n";

}

void enq(stack &S1 , int data){
	stack S2;
	while(!S1.empty()) {
		S2.push(S1.top());
		S1.pop();
	}

	S1.push(data);

	while(!S2.empty()) {
		S1.push(S2.top());
		S2.pop();
	}
}

int deq(stack &S1){
	if(S1.empty()) {
		cout<<"-------\nEmpty Queue...!!!\n----------\n";
	 	return -1;
	}
	int T = S1.top();
	S1.pop();
	return T;
}
int main() {
	stack S;

	while(1) {
		cout<<"\nPress 1 to Enque , 2 to Deque , 3 to Display , any other number to exit\n";

		int choice;
		cin>>choice;

		switch(choice) {

			case 1 : cout<<"Enter Number to enque... \n";
					 int number;
					 cin>>number;
					 enq(S,number);
					 break;	
			case 2 : deq(S);break;
			case 3 : disp(S);break;
			default : return 0;
		}

	}
	return 0;

}