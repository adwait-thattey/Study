#include <bits/stdc++.h>
using namespace std;

struct node {

	int data;
	node *next;
	node *previous;

	node() {

		next = NULL;
		previous = NULL;
	}
};

class linklist {

	private : 
		node *head , *tail;
		int size;

	public :

		linklist() {
			size=0;
			head=NULL;
			tail=head;
		} 
		node* retHead() {
			return head;
		}

		node* retTail() {
			return tail;
		}

		int retSize() {
			return size;
		}

		
		bool addAtEnd(int data);
		bool addAtStart(int data);
		//bool addAt(int data , int pos);
		bool change(int pos , int data);
		void printList(node* start , node* end, bool reverse);
		void printList(bool reverse);
		bool clearList();
		node pop(int pos);
		bool isPresent(int data , node* start , node* end);
		int min(node* start , node* end);
		int max(node* start , node* end);


};

bool linklist::clearList() {

	while(head) {
		node *temp = head;
		head = head->next;
		delete temp;
	}

	if(head!=NULL) return false;

	return true;
}

bool linklist::isPresent(int data , node* start = NULL , node* end = NULL) {

	if (head==NULL) {
		return false;
	}
	
	if(start==NULL) {
		start = head;
	}

	if(end==NULL) {
		end = tail;
	}

	while (start!=NULL) {

		if (start->data==data) {
			return true;
		}

		start = start->next;

	}

	return false;

}

int linklist::min(node* start=NULL , node* end=NULL){
	
	if(head==NULL) {
		cout<<"\n ERROR : list::min() Falied!!!. EMPTY LIST!!\n";
		return -1;
	}

	if(start==NULL) start=head; 
	
	if(end==NULL) end=tail;

	int M = start->data;

	start=start->next;
	while(start) {

		if(start->data<M) M=start->data;

		start=start->next;
	}

	return M;

}

int linklist::max(node* start=NULL , node* end=NULL){
	
	if(head==NULL) {
		cout<<"\n ERROR : list::max() Falied!!!. EMPTY LIST!!\n";
		return -1;
	}

	if(start==NULL) start=head; 
	
	if(end==NULL) end=tail;

	int M = start->data;

	start=start->next;
	while(start) {

		if(start->data>M) M=start->data;

		start=start->next;
	}

	return M;

}

bool linklist::addAtEnd(int data) {
	if(head==NULL) {
		head = new node;
		head->data = data;
		head->previous = NULL;
		head->next=NULL;
		tail = head;
		++size;
		return true;
	}

	node *temp = NULL;
	temp = new node;
	if (temp==NULL) {
		return false;
	}
	temp->data = data;
	temp->previous = tail;
	temp->next = NULL;
	tail->next = temp;
	tail=temp;
	++size;
	return true;

}

bool linklist::change(int pos , int data) {

	if(pos>size){
		return false;
	}

	int count=1;

	node *temp = head;

	while(count<pos){
		temp=temp->next;
		++count;
	}	

	temp->data=data;

	return true;

}
void linklist::printList(bool reverse=false) {
	if(head==NULL) {
		cout<<"Empty List!!";
		return;
	}
	node *start = head;
	node *end = tail;

	cout<<"\n--------\n";
	
	if (reverse==true)
		while(end!=start->previous && end!=NULL) {
		cout<<end->data<<"\n";
		end=end->previous;
	}		

	else
		while(start) {
			cout<<start->data<<"\n";
			start=start->next;
			
		}
	
	cout<<"---------\n";
	return;



}

void linklist::printList(node* start, node* end = NULL, bool reverse=false) {

	if(start==NULL) {
		cout<<"Empty Sequence!!";
		return;

	}
	
	if(end==NULL) {
		end=tail;
	}
	cout<<"\n---------\n";
	if (reverse==true)
		while(end!=start->previous && end!=NULL) {
		cout<<end->data<<"\n";
		end=end->previous;
	}		

	else
		while(start!=NULL && start!=end->next) {
			cout<<start->data<<"\n";
			start=start->next;
		}
	
	cout<<"\n --------- \n";
	return;
}

bool linklist::addAtStart(int data) {

	if (head==NULL) {
		head = new node;
		tail=head;
		head->data = data;
		head->next = NULL;
		head->previous = NULL;
		return true;
		++size;
	}

	node *temp = NULL;
	temp = new node;
	
	if (temp==NULL) {
		return false;
	}

	temp->data = data;
	temp->next = head;
	temp->previous = NULL;
	head->previous = temp;
	head = temp;
	++size;
	return true;

}

node linklist::pop(int pos = 1) {

	node toreturn;

	if (pos>size) {
		cout<<"Position greater than size";
		return toreturn;
	}
	
	node *temp = head;

	while(pos>1) {
		temp=temp->next;
		--pos;
	}
	
	if(temp->previous){
	temp->previous->next = temp->next;
	}
	else{
		head = head->next;
	}

	toreturn.data = temp->data;
	toreturn.next = temp->next;
	toreturn.previous = temp->previous;
	--size;

	delete temp;
	return toreturn;



}