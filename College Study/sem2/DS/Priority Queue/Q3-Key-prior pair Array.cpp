#include <iostream>
#include <queue>
using namespace std;
struct node {
	int key;
	int priority;
};

queue<node> Q;
void enq() {
	node element;
	cout << "\n Enter the element you want to enqueue :";
	cin >> element.key;
	cout << "\n Enter the priority of the element you want to enqueue :"; 
	cin >> element.priority;
	int S = Q.size();
	int enqFlag = 1;
	for (int i = 0; i < S; ++i) {
		if (enqFlag && Q.front().priority > element.priority) {
			Q.push(element);
			enqFlag = 0;
		}
		Q.push(Q.front());
		Q.pop();
	}

	if (enqFlag) {
		Q.push(element);
	}
}

void printQueue(queue<node> q) {
	while (!q.empty()) {
		cout << q.front().key << "-"<<q.front().priority<<"\t";
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
		case 1: enq(); break;
		case 2:	if (Q.empty()) {
				cout << "\n\nEmpty Queue\n\n";
				break;
				}
				Q.pop();
				break;
		case 3: printQueue(Q); break;
		case 4: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	return 0;
}
