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

void prb2(linklist &L) {

	node *pt1 = L.retHead();
	
	while(pt1) {
		int flag=0;
		node *pt2 = pt1->next;

		while(pt2) {

			if((pt1->data + pt2->data) == 0) {
				node *temp = pt2;
				pt2=pt2->next;
				L.deleteAt(temp);
				temp = pt1;
				pt1 = pt1->next;
				L.deleteAt(temp);
				flag=1;
				break;
			}
			pt2=pt2->next;
		}

		if(flag) {
			continue;
		}

		pt1=pt1->next;
	}
	

}

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

/*	linklist L1;

	L1.addAtEnd(1);
	L1.addAtEnd(2);
	L1.addAtEnd(2);
	L1.addAtEnd(4);
	L1.addAtEnd(1);
	L1.addAtEnd(3);
	L1.addAtEnd(3);
	L1.addAtEnd(4);

	L1.printList();	
	node *h = L1.retHead() , *t = L1.retTail();

	prb8(L1);

	L1.printList();

*/

	linklist L2;

	L2.addAtEnd(1);
	L2.addAtEnd(1);
	L2.addAtEnd(1);
	L2.addAtEnd(3);
	L2.addAtEnd(1);
	L2.addAtEnd(2);
	L2.addAtEnd(1);
	L2.addAtEnd(1);
	L2.addAtEnd(4);
	L2.addAtEnd(1);

	L2.printList();

	prb8(L2);

	L2.printList();





}
