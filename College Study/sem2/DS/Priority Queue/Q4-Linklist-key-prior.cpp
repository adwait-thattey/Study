#include <iostream>
using namespace std;

class priorityQueue {
private:	
	struct node {
		int key;
		int priority;
		node *next;
	};
	int size;
	node *front;
	node *rear;

public :
	priorityQueue() {
		front =NULL;
		rear = NULL;
		size = 0;
	}
	int retSize() {
		return size;
	}
	bool enque(int key , int priority);
	bool deque();
	int retFront();
	int retRear();
	void dispQ();

};

bool priorityQueue::enque(int key , int priority) {
	node *temp = new node;
	if (temp == NULL) {
		return false;
	}
	temp->key = key;
	temp->priority = priority;
	temp->next = NULL;
	++size;
	if (front == NULL) {
		front = temp;
		rear = temp;
		return true;
	}

	if (front->priority > priority) {
		temp->next = front;
		front = temp;
		return true;
	}

	if (rear->priority < priority) {
		rear->next = temp;
		rear = temp;
		return true;
	}

	node *travel = front;
	while (travel->next->priority <= priority) {
		travel = travel->next;
	}
	temp->next = travel->next;
	travel->next = temp;
	return true;

}

bool priorityQueue::deque() {
	if (front == NULL) {
		return false;
	}
	
	node *temp = front;
	front = front->next;
	delete temp;
	--size;

	return true;
}

void priorityQueue::dispQ() {
	node *ftemp = front;
	cout << "\n------------------\n";
	cout << "<--- Queue Direction ---<";
	cout << "\n------------------\n";
	while (ftemp != NULL) {
		cout << "(" << ftemp->key << "," << ftemp->priority << ")" << "   ";
		ftemp = ftemp->next;
	}
	cout << "\n------------------\n";
}

int priorityQueue::retFront()
{
	if (front == NULL) {
		cout << "EMPTY QUEUE";
		return -1;
	}
	return front->key;
}

int priorityQueue::retRear()
{

	if (rear == NULL) {
		cout << "EMPTY QUEUE";
		return -1;
	}
	return rear->key;

}

int main() {
	priorityQueue P;
	while (true) {
		cout << "What do you wanna do ? \n";
		cout << "(1) Enqueue \n (2) Dequeue \n (3)Print Queue \n (4) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: cout << "\nEnter the element you want to enqueue \n";
				int key;
				cin >> key;
				cout << "\nEnter the priority of the entered element \n";
				int priority;
				cin >> priority;
				P.enque(key, priority);
				break;
		case 2: P.deque(); break;
		case 3: P.dispQ(); break;
		case 4: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	return 0;
}