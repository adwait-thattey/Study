#include "linklist.cpp"

linklist retUnion(linklist L1 , linklist L2) {

	node *h1 = L1.retHead() , *h2 = L2.retHead();

	linklist LU;

	for(;h1!=NULL;h1=h1->next) {

		if(LU.isPresent(h1->data)) {
			continue;
		}

		LU.addAtEnd(h1->data);


	}

	for(;h2!=NULL;h2=h2->next) {

		if(LU.isPresent(h2->data)) {
			continue;
		}

		LU.addAtEnd(h2->data);
	
		
	}

	return LU;

}


linklist retIntersection(linklist L1 , linklist L2) {

	node *h1 = L1.retHead();

	linklist IN;

	for(;h1!=NULL;h1=h1->next) {

		if(L2.isPresent(h1->data)) {
			
			IN.addAtEnd(h1->data);
		}

		
	}

	return IN;
	

}


int main() {

	linklist L1;

	L1.addAtEnd(1);
	L1.addAtEnd(2);
	L1.addAtEnd(3);
	L1.addAtEnd(4);
	L1.addAtEnd(5);
	
	linklist L2; 

	L2.addAtEnd(6);
	L2.addAtEnd(7);
	L2.addAtEnd(3);
	L2.addAtEnd(4);
	L2.addAtEnd(9);

	cout<<"List 1 : \n";

	L1.printList();

	cout<<"List 2 : \n";

	L2.printList();

	linklist Union = retUnion(L1,L2);
	linklist Intersection = retIntersection(L1,L2);

	cout<<"UNION : \n";

	Union.printList();

	cout<<"INTERSECTION : \n";

	Intersection.printList();

	return 0;
}