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
		cout << q.front() << " ";
		q.pop();
	}

	cout << "\n";
}

void binS(queue<int> q , int element) {
	int S = q.size();
	queue<int> q2;
	if (S == 0) {
		cout << "\nNOT FUOUND!!\n";
		return;
	}
	if (S == 1) {
		if (q.front() == element) {
			cout << "FOUND";
			return;
		}
		cout << "\n NOT FOUND \n";
		return;
	}
	for (int i = 0; i < S / 2; ++i) {
		q2.push(q.front());
		q.pop();
	}

	if (q2.back() == element) {
		cout << "\nFound\n";
		return;
	}

	if (q2.back() < element) {
		binS(q, element);
		return;
	}

	if (q2.back() > element) {
		binS(q2, element);
		return;
	}

}

int main() {
	while (true) {
		cout << "What do you wanna do ? \n";
		cout << "(1) Enqueue \n (2) Dequeue \n (3)Print Queue \n (4) Search \n(5) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: enq(); break;
		case 2: Q.pop(); break;
		case 3: printQueue(Q); break;
		case 4: cout << "Enter The element you want to search.. :";
				int x;
				cin >> x;
				binS(Q, x);
				break;
		case 5: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	cin.get();

	return 0;
}
