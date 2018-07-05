#include "linklist.cpp"

void prb5(linklist &L) {

	cout<<"Enter K for reversing in grps of K : ";
	int K;
	cin>>K;

	node *start = L.retHead();
	node *end = start;

	if(L.retSize() >= K) {
	
		for (int i=1;i<K;++i) {
			end=end->next;
		}

	}

	else return;

	int size = L.retSize();
	
	for(int count=0;size-count>=K;count+=K) {
		L.reverse(start,end);

		start = start->next;

		end = start;
		
		for(int i=1;i<K;++i) {
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

	cout<<"Before Reversing : \n";
	L.printList();

	prb5(L);
	cout<<"After Reversing : \n";
	L.printList();
	return 0;
}