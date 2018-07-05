#include <iostream>
#define MaxQSize 15

using namespace std;
class priorQueue {
	//Implemented Using An Array

private: int Arr[MaxQSize];
		 int rear, front;
public:
	priorQueue();
	void printdet();
	void insertAtPosition(int data);
	bool enqueue(int data);
	int dequeue(bool &chk);
	void dispQ();
	int retSize();

};

priorQueue::priorQueue() {
	rear = 0;
	front = -1;
}
void priorQueue::printdet() {
	cout << "\nrear = " << rear << " front = " << front << "\n";
}

void priorQueue::dispQ() {
	cout << "\n----------\n";
	if (front == -1) {
		cout << "Empty priorQueue";
	}

	else {
		cout << ">-- priorQueue Direction--> \n";
		int rtemp = rear;
		do {

			if (rtemp <= 0) {
				rtemp = MaxQSize;
				continue;
			}

			else {
				cout << Arr[rtemp - 1] << " ";
			}

			--rtemp;

		} while (rtemp != front);
	}

	cout << "\n----------\n";
	return;

}

int priorQueue::dequeue(bool &chk) {

	if (front == -1) {
		cout << "priorQueue Underflow!!\n";
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
				cout << "Empty priorQueue";
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

void priorQueue::insertAtPosition(int data) {
	int insertPos = front;
	int rtemp = rear;
	
	while (insertPos != rtemp) {
		if (insertPos >= MaxQSize) {
			insertPos = 0;
			continue;
		}
		if (Arr[insertPos] <= data) {
			++insertPos;
			continue;
		}
		else if (Arr[insertPos] > data) {
			break;
		}

		else {
			cout << "CORNER CASE";
			cin.get();
			exit(-1);
		}
	}

	int shiftPos = insertPos;
	while (shiftPos < rtemp) {
		int temp = Arr[shiftPos];
		Arr[shiftPos] = data;
		data = temp;

		++shiftPos;
	}

	Arr[shiftPos] = data;

}
bool priorQueue::enqueue(int data) {

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
			insertAtPosition(data);
			++rear;
			return true;
		}

		else {
			cout << "priorQueue Overflow!!";
			return false;
		}
	}

	else {

		if (rear == front) {
			cout << "priorQueue Overflow!!";
			return false;
		}

		else {
			insertAtPosition(data);
			++rear;
			return true;
		}
	}


}

int priorQueue::retSize() {

	if (front < rear) {
		return (rear - front);
	}

	else {
		return ((MaxQSize - front) + rear);

	}
}

int main() {
	priorQueue P;

	while (true) {
		bool chk;
		cout << "What do you wanna do ? \n";
		cout << "(1) Enqueue \n (2) Dequeue \n (3)Print Queue \n (4) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: cout << "\n Enter the element you want to enqueue :";
				int x;
				cin >> x;
				P.enqueue(x);
				break;
		case 2: P.dequeue(chk);
				if (chk == false) {
					cout << "\nEMPTY QUEUE\n";
				}
				break;
		case 3: P.dispQ(); break;
		case 4: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	cin.get();
	return 0;
}
