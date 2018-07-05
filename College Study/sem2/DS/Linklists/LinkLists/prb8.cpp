#include "linklist.cpp"

int findNextReq(linklist L , int x=0) {

	while(L.isPresent(++x));
	return x;
}

void prb8(linklist &L) {
	int X=0;
	int cur=1;
	
	node *h1 , *h2;
	h1=h2=L.retHead();
	while(h1) {
		
		h2=h1->next;

		while(h2) {

			if(h1->data == h2->data) {
				node *temp = h2;
				h2=h2->next;
				L.change(temp,findNextReq(L,X));
				continue;
			}

			h2 = h2->next;
		}


		h1=h1->next;
	}

	
}

int main() {

	linklist L;

	L.addAtEnd(1);
	L.addAtEnd(1);
	L.addAtEnd(1);
	L.addAtEnd(3);
	L.addAtEnd(1);
	L.addAtEnd(2);
	L.addAtEnd(1);
	L.addAtEnd(1);
	L.addAtEnd(4);
	L.addAtEnd(1);

	cout<<"Before Modifying : \n";

	L.printList();

	prb8(L);

	cout<<"After Modifying : \n";

	L.printList();

	return 0;
}