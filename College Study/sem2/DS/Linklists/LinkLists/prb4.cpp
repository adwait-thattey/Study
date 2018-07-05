#include "linklist.cpp"

void prb4(linklist L) {
	cout<<"\nEnter the required sum to find pairs : ";
	int sum;
	cin>>sum;
	int count=0;
	node *start = L.retHead();	
	cout<<"\nThe pairs with the required sum are : \n ";
	while(start->next) {
		
		if(L.isPresent(sum-start->data , start->next)) {
			cout<<"("<<start->data<<" "<<sum-start->data<<") , ";
			++count;	
		}
		
		start=start->next;
	}

	if(!count) {
		cout<<"Sorry! no pairs found!! ";

	}

	cout<<"\n";

	return;
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

	prb4(L);

	return 0;
}