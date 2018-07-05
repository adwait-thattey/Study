#include <iostream>
#include <stdlib.h>
#define MaxQSize 100

using namespace std;


class Queue {
	//Implemented Using An Array

private: int Arr[MaxQSize];
		 int rear, front;
public:
	Queue();
	void printdet();
	bool enqueue(int data);
	int dequeue(bool &chk);
	void dispQ();
	int retSize();

};
Queue::Queue() {
		rear = 0;
		front = -1;
	}
void Queue::printdet() {
		cout << "\nrear = " << rear << " front = " << front << "\n";
	}
	
void Queue::dispQ() {
	cout << "\n----------\n";
	if (front == -1 ) {
		cout << "Empty Queue";
	}

	else {
		 cout<<">-- Queue Direction--> \n";
		int rtemp = rear;
		do{
			
			if (rtemp <= 0) {
				rtemp = MaxQSize;
				continue;
			}

			else {
				cout << Arr[rtemp-1] << " ";
			}

			--rtemp;
			
		}while (rtemp != front);
	}

	cout << "\n----------\n";
	return;

}

int Queue::dequeue(bool &chk) {

	if (front == -1) {
		cout << "Queue Underflow!!\n";
		chk = false;
		return -1;
	}

	if (front<rear) {
		int T = Arr[front];
		if ((front + 1) == rear) {
			front = -1;
			rear = 0;
		}
		else ++front;
		chk = true;
		return T;
	}

	if (front >= rear) {
		if (front == MaxQSize) {
			front = 0;
			if (rear == 0) {
				rear = 0;
				front = -1;
				cout << "Empty Queue";
				chk = false;
				return -1;
			}
			else {
				int T = Arr[front];
				++front;
				if (front == rear) {
					front = -1;
					rear = 0;
				}
				chk = true;
				return T;
			}
		}

		else {
			int T = Arr[front];
			if ((front + 1) == rear) {
				front = -1;
				rear = 0;
			}
			else ++front;
			chk = true;
			return T;
		}


	}


}
bool Queue::enqueue(int data) {

	if (rear>MaxQSize) {
		cout << "CORNER CASE !!!!";
		cin.get();
		exit(-1);
	}
	else if (rear == 0) {
		Arr[rear] = data;
		++rear;
		front = 0;
		return true;
	}
	else if (rear == MaxQSize) {
		if (front>0) {
			rear = 0;
			Arr[rear] = data;
			++rear;
			return true;
		}

		else {
			cout << "Queue Overflow!!";
			return false;
		}
	}

	else {

		if (rear == front) {
			cout << "Queue Overflow!!";
			return false;
		}

		else {
			Arr[rear] = data;
			++rear;
			return true;
		}
	}


}

int Queue::retSize() {

	if (front < rear) {
		return (rear - front);
	}

	else {
		return ((MaxQSize - front) + rear);

	}
}
