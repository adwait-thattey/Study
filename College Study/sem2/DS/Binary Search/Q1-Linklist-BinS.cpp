#include <iostream>
using namespace std;

struct node {
	int element;
	node *next;
};
class linklist {
private:
	int size;
	node *head;
	node *tail;

public:
	linklist() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	int retSize() {
		return size;
	}
	bool insert(int element);
	bool pop();
	node* retHead();
	node* retTail();
	node* binSearch(node *start, node *end, int gap, int element);
	void dispLL();

};

bool linklist::insert(int element) {
	node *temp = new node;
	if (temp == NULL) {
		return false;
	}
	temp->element = element;
	temp->next = NULL;
	++size;
	if (head == NULL) {
		head = temp;
		tail = temp;
		return true;
	}

	if (head->element > element) {
		temp->next = head;
		head = temp;
		return true;
	}

	if (tail->element < element) {
		tail->next = temp;
		tail = temp;
		return true;
	}

	node *travel = head;
	while (travel->next->element <= element) {
		travel = travel->next;
	}
	temp->next = travel->next;
	travel->next = temp;
	return true;

}

bool linklist::pop() {
	if (head == NULL) {
		return false;
	}

	node *temp = head;
	head = head->next;
	delete temp;
	--size;

	return true;
}

void linklist::dispLL() {
	node *ftemp = head;
	cout << "\n------------------\n";
	while (ftemp != NULL) {
		cout << ftemp->element<< "   ";
		ftemp = ftemp->next;
	}
	cout << "\n------------------\n";
}

node* linklist::retHead()
{
	return head;
}

node* linklist::retTail()
{
	return tail;
}

node* linklist::binSearch(node *start , node *end ,int gap ,int element) {
	if (gap <= 0) {
		if (start == NULL) {
			cout << "\n Empty List..\n";
			node *temp = NULL;
			return NULL;
		}
		
		if (start->element == element) {
			//cout << "\nelement found.\n";
			return start;
		}
		else if (end->element == element) {
			//cout << "\nelement found.\n";
			return end;
		}
		//cout << "\nElement Not Found!!!\n";
		node *temp = NULL;
		return NULL;
	}
	
	node *mid = start;
	for (int i = 0; i < gap / 2; ++i) {
		mid = mid->next;
	}

	if (mid->element == element) {
		//cout << "Element found.";
		return mid;
	}

	else if (mid->element < element) {
		return binSearch(mid->next, end, gap/2 -1 +gap%2, element);
	}

	else if (mid->element > element) {
		return binSearch(start, mid,gap/2 - 1 , element);
	}

	else {
		cout << "CRITICAL CORNER CASE IN SEARCH!!!";
		cin.get();
		exit(-1);
	}
}

int main() {
	linklist L;
	node *find;
	while (true) {
		cout << "What do you wanna do ? \n";
		cout << "(1) Insert into Linklist \n (2) Pop from linklist \n (3)Print linklist \n (4) Search for an Element in linklist \n (5) Exit \n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: cout << "\nEnter the element you want to insert \n";
				int element;
				cin >> element;
				L.insert(element);
				break;
		case 2: L.pop(); break;
		case 3: L.dispLL(); break;
		case 4: cout << "\nEnter the element that you want to search :\n";
				int elem;
				cin >> elem;
				find = L.binSearch(L.retHead(),L.retTail(),L.retSize()-2,elem);
				if (find == NULL) {
					cout << "\nSorry!!. Element Not Found \n";
				}
				else {
					cout << "\nYippee... Element Found!!\n";
				}
				break;
		case 5: return 0;
		default: cout << "\nWrong Choice. Enter Again \n"; break;

		}
	}
	cin.get();
	return 0;
}