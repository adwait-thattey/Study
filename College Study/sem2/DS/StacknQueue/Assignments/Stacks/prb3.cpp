#include<iostream>
struct node {
	int data;
	node *next;
};

class stack {

	node *TOP;

	public :
		stack() {
			TOP = NULL;
		}

		bool empty() {
			if(TOP==NULL) return true;
			else return false;	
		}

		bool push(int x) {
			node *temp = NULL;
			temp = new node;
			if (temp==NULL) return false;

			temp->data = x;
			temp->next = TOP;
			TOP = temp;

		}

		int top() {
			return TOP->data;
		}

		bool pop() {
			if(TOP==NULL) return false;

			node *temp = TOP;
			TOP = TOP->next;
			delete temp;
		}

};


bool chkerr = 0;
using namespace std;
int getmin(stack s);
int getmax(stack s);
int main() {
	stack S;
	cout<<"Enter the number of Elements you are going to enter...";
	int N;
	cin>>N;
	cout<<"\nEnter "<<N<<" Elements to push into stack";
	while(N--) {
		int x;
		cin>>x;
		S.push(x);
	}
	cout << "\nMinimum is : "<<getmin(S)<<"\n"<<"Maximum is : "<<getmax(S);
	return 0;
}

int getmax(stack s) {

	stack Stemp;

	int max = s.top();
	Stemp.push(max);
	s.pop();
	while (!s.empty()) {
		int temp = s.top();
		Stemp.push(temp);
		if (temp > max)max = temp;
		//s2.push(temp);
		s.pop();
	}

	while(!Stemp.empty()) {
		s.push(Stemp.top());
		Stemp.pop();
	}

	return max;
}

int getmin(stack s) {

	stack Stemp;
	int min = s.top();
	s.pop();
	while (!s.empty()) {
		
		int temp = s.top();
		Stemp.push(temp);
		if (temp < min)min = temp;
		//s2.push(temp);
		s.pop();
	}

	while(!Stemp.empty()) {
		s.push(Stemp.top());
		Stemp.pop();
	}

	return min;
}

