#include <iostream>

using namespace std;
int queue[2][100];
int front = -1;
int rear = 0;
void enq() {
	if (front == -1)
	{
		front = 0;
	}
	cout << "\n Enter the element you want to enqueue :";
	int element,priority;
	cin >> element;
	cout << "\n Enter the priority of the element you want to enqueue :"; 
	cin >> priority;

	int rtemp = rear-1;

	while(rtemp>=front && queue[1][rtemp]>priority)  {
		queue[1][rtemp+1] = queue[1][rtemp];
		queue[0][rtemp + 1] = queue[0][rtemp];
		--rtemp;
	}
	queue[1][rtemp+1] = priority;
	queue[0][rtemp+1] = element;
	++rear;
	

/* 	int S = Q.size();
	int enqFlag = 1;
	for (int i = 0; i < S; ++i) {
		if (enqFlag && Q.front().priority > priority) {
			Q.push(element);
			enqFlag = 0;
		}
		Q.push(Q.front());
		Q.pop();
	}

	if (enqFlag) {
		Q.push(element);
	} */
}

void printQueue() {
	int ftemp = front;
	cout<<"\n------------------\n";
	if(front<0) return;
	while(ftemp<rear) {
		cout<<"("<<queue[0][ftemp]<<","<<queue[1][ftemp]<<")"<<"   ";
		++ftemp;
	}
	cout << "\n------------------\n";
}

int main() {

	while (true) {
		cout << "What do you wanna do ? \n";
		cout << "(1) Enqueue \n (2) Dequeue \n (3)Print Queue \n (4) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: enq(); break;
		case 2:	if (front==-1 || front==rear) {
				cout << "\n\nEmpty Queue\n\n";
				break;
				}
				++front;
				break;
		case 3: printQueue(); break;
		case 4: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	return 0;
}
