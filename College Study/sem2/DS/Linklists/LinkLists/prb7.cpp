#include <bits/stdc++.h>
using namespace std;

struct node {

	int data;
	node *next;
	

	node() {

		next = NULL;
		
	}
};

class linklist {

	private : 
		node *head;
		int size;

	public :

		linklist() {
			size=0;
			head=NULL;
		} 
		node* retHead() {
			return head;
		}

		int retSize() {
			return size;
		}

		bool addAtStart(int data);
		void printList();
		int countTill(node *point);
		bool reverse(node *start , node *end);
	
};

bool linklist::addAtStart(int data) {

	if (head==NULL) {
		head = new node;
		head->data = data;
		head->next = NULL;
		return true;
		size=1;
	}

	node *temp = NULL;
	temp = new node;
	
	if (temp==NULL) {
		return false;
	}

	temp->data = data;
	temp->next = head;
	head = temp;
	++size;
	return true;
}

void linklist::printList() {
	if(head==NULL) {
		cout<<"Empty List!!";
		return;
	}
	node *start = head;
	
	cout<<"\n--------\n";
	
	
	while(start) {
		cout<<start->data<<"\n";
		start=start->next;
	}
	
	cout<<"---------\n";
	return;



}


int linklist::countTill(node *point) {
	int count=1;
	node *temp = head;
	while(temp!=point) {
		temp=temp->next;
		++count;
	}

	return count;
}

bool linklist::reverse(node *start , node *end=NULL) {
	/* Actual Reversing starts from start->nxt */
	
	if(start!=NULL && countTill(start) > countTill(end)) {
		return false;
	}

	
	node *pos = end;

	
	if(start!=NULL) {
		
		node *T = start->next;
		start->next = pos;
		start = T;
	}
	else {
		start=head;
		head = pos;
	}	
	
	while(start!=pos) {
		node *temp = start->next;
		start->next = pos->next;
		pos->next = start;

		start = temp;
	
	}


return true;

}

void prb7(linklist &L) {

	cout<<"\n\n Enter K to skip K nodes , reverse K nodes , skip K nodes , so on... : ";
	int K;
	cin>>K;

	node *H = L.retHead();
	node *T;
	int finish = 0;
	do {

		for(int i=1;i<K;++i) {
			H = H->next;
			if(!H) {
				finish = 1;
				break;
			}
		}


		if(finish == 1) {
			break;
		}

		T = H;

		for(int i=0;i<K;++i) {
			T = T->next;
			if(!T) {
				finish = 1;
				break;
			}
		}

		if(finish == 1) {
			break;
		}

		node *temp = H->next;

		L.reverse(H,T);

		H = temp;

		H = H->next;

	}while(H && T);


}


int main() {

	linklist L;

	L.addAtStart(30);
	L.addAtStart(29);
	L.addAtStart(28);
	L.addAtStart(27);
	L.addAtStart(26);
	L.addAtStart(25);
	L.addAtStart(24);
	L.addAtStart(23);
	L.addAtStart(22);
	L.addAtStart(21);
	L.addAtStart(20);
	L.addAtStart(19);
	L.addAtStart(18);
	L.addAtStart(17);
	L.addAtStart(16);
	L.addAtStart(15);
	L.addAtStart(14);
	L.addAtStart(13);
	L.addAtStart(12);
	L.addAtStart(11);
	L.addAtStart(10);
	L.addAtStart(9);
	L.addAtStart(8);
	L.addAtStart(7);
	L.addAtStart(6);
	L.addAtStart(5);
	L.addAtStart(4);
	L.addAtStart(3);
	L.addAtStart(2);
	L.addAtStart(1);


	L.printList();
	prb7(L);	
	L.printList();

}