#include "Queue.cpp"
#include <iostream>
#include "stack.cpp"

using namespace std;

int main() {
	Queue Q;
	cout << "Enter Number of Elements : \n";
	int N;
	cin >> N;
	if(N%2) {
		cout<<"YOU MUST ENTER EVEN SIZE ONLY\n";
		return -1;	
	}
	cout << "\nEnter Elements :";
	while (N) {
		--N;
		int x;
		cin >> x;
		if(!Q.enqueue(x)) break;
	}
	stack S;

	int size = Q.retSize();
	int stemp = size/2;
	while (stemp) {
		--stemp;
		bool dechk;
		S.push(Q.dequeue(dechk));
	}

	while (!S.empty()) {
		int T = S.top();
		S.pop();
		Q.enqueue(T);
	}
	stemp = size / 2;
	while (stemp) {
		--stemp;
		bool dechk;
		Q.enqueue(Q.dequeue(dechk));
	}
	if (!S.empty()) {
		cout << "STACK STILL NOT EMPTY!!";
		exit(-1);
	}
	stemp = size / 2;
	while (stemp) {
		--stemp;
		bool dechk;
		S.push(Q.dequeue(dechk));
	}

	while (!S.empty()) {
		int T = S.top();
		bool fchk;
		cout << T << " "<<Q.dequeue(fchk)<<" ";
		S.pop();
	}
	return 0;
}