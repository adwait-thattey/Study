#include "linklist.cpp"

void prb9(linklist &L) {

	node *start = L.retHead();
	node *end = start;

	if(L.retSize() >= 2) {
	
		for (int i=1;i<2;++i) {
			end=end->next;
		}

	}

	else return;

	int size = L.retSize();
	
	for(int count=0;size-count>=2;count+=2) {
		L.reverse(start,end);

		start = start->next;

		end = start;
		
		for(int i=1;i<2;++i) {
			if(!end) break;
			end=end->next;
		}
	}	

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

	cout<<"Before reversing Pairs : \n";

	L.printList();	

	prb9(L);

	cout<<"After Reversing : \n";

	L.printList();
	return 0;
}