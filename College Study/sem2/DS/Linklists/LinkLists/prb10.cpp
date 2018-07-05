#include "linklist.cpp"

void prb10(linklist &L) {

	node *head = L.retHead();
	while(head) {

		node *temp = head->next;

		while(temp) {

			if(temp->data==head->data) {

				node *temp2 = temp;
				temp=temp->next;
				L.deleteAt(temp2);
				continue;
			}

			temp=temp->next;
		}

		head = head->next;
	}
}


int main() {

	linklist L;

	L.addAtEnd(1);
	L.addAtEnd(2);
	L.addAtEnd(2);
	L.addAtEnd(4);
	L.addAtEnd(5);
	L.addAtEnd(6);
	L.addAtEnd(4);
	L.addAtEnd(1);
	L.addAtEnd(9);
	L.addAtEnd(6);

	cout<<"Before Removing Duplicates : \n";

	L.printList();

	prb10(L);

	cout<<"After Removing Duplicates : \n";

	L.printList();

	return 0;
}