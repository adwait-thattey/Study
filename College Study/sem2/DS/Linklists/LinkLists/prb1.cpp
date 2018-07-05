#include "linklist.cpp"

void printMiddle(linklist L) {

	if (L.retSize() <=0) {
		cout<<"Empty List";
		return;
	}
	
	node *start = L.retHead() , *end = L.retTail() ;

	while( start!=end && start->next!=end) {
		start = start->next;
		end = end->previous;
	}

	if (start==end) {
		cout<<"Middle Element : "<<start->data;
		return;
	}

	else if (start->next==end) {
		cout<<"2 middle elements : \n\t"<<start->data<<"\n\t"<<end->data;
		return;
	}

	cout<<"CORNER CASE!!!!";
	exit(-1);

}

int main() {

	linklist L;

	L.addAtEnd(1);
	L.addAtEnd(2);
	L.addAtEnd(3);
	L.addAtEnd(4);
	L.addAtEnd(5);
	L.addAtEnd(6);
	L.addAtEnd(7);
	L.addAtEnd(8);
	L.addAtEnd(9);
	L.addAtEnd(10);

	printMiddle(L);

	return 0;
}