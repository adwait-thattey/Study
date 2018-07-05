#include <iostream>
#include <queue>

using namespace std;
queue<int> Q;
void enq() {
	cout << "\n Enter the element you want to enqueue :";
	int x;
	cin >> x;
	int S = Q.size();
	int enqFlag = 1;
	for (int i = 0; i < S; ++i) {
		if (enqFlag && Q.front() > x) {
			Q.push(x);
			enqFlag = 0;
		}
		Q.push(Q.front());
		Q.pop();
	}

	if (enqFlag) {
		Q.push(x);
	}
}

void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front()<<" ";
		q.pop();
	}

	cout << "\n";
}

int main() {	

	while (true) {
		cout << "What do you wanna do ? \n";
		cout << "(1) Enqueue \n (2) Dequeue \n (3)Print Queue \n (4) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
			case 1 : enq(); break;
			case 2 : Q.pop(); break;
			case 3 : printQueue(Q); break;
			case 4 : return 0;
			default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	return 0;
}
