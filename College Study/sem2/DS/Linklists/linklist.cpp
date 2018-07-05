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
		bool change(node *ptr , int data);
		void printList(node* start , node* end, bool reverse);
		void printList(bool reverse);
		bool clearList();
		node pop(int pos);
		bool isPresent(int data , node* start , node* end);
		int min(node* start , node* end);
		int max(node* start , node* end);
		int countTill(node *point);
		bool reverse();
		bool reverse(node *start , node *end);
		bool deleteAt(node *pointer);
		bool insertAt(node *ptr , int data);


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

int linklist::countTill(node *point) {
	int count=1;
	node *temp = head;
	while(temp!=point) {
		temp=temp->next;
		++count;
	}

	return count;
}

bool linklist::deleteAt(node *pointer) {
	if(pointer==NULL) {
		return false;
	}

	if(pointer->previous) {
		pointer->previous->next = pointer->next;
	}
	else {
		head = pointer->next;
	}

	if(pointer->next) {
		pointer->next->previous = pointer->previous;
	}
	else {
		tail = pointer->previous;
	}

	--size;

	return true;
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

bool linklist::change(node *ptr , int data) {

	if(ptr==NULL) {
		return false;
	}
	node *temp = ptr;
	
	if(ptr==head) {
		deleteAt(ptr);
		addAtStart(data);
		return true;

	}

	if(ptr==tail) {

		deleteAt(ptr);
		addAtEnd(data);
		return true;

	}
	ptr = ptr->previous;
	deleteAt(temp);
	insertAt(ptr,data);

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

bool linklist::insertAt(node *ptr , int data) {

	if(ptr==NULL){
		return false;
	}
	
	node *temp = new node;
	temp->data = data;
	temp->next = ptr->next;
	temp->previous = ptr;
	if(ptr->next) {
		ptr->next->previous = temp;
	}

	ptr->next = temp;
	++size;
	return true;

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


bool linklist::reverse(){
	
	node *pos = tail;
	tail = head;
	while(pos->previous!=NULL) {
		node *temp = head;
		temp->next->previous = NULL;
		
		head = temp->next;
		temp->next = pos->next;
		temp->previous = pos;
		pos->next = temp;
			
	}

	return true;

}

bool linklist::reverse(node *start , node *end=NULL) {
	int hflag=0 , tflag=0;
	if (end==NULL) {
		end = tail;
	}

	if(countTill(start) > countTill(end)) {
		return false;
	}

	if (start==head) hflag=1;
	if (end==tail) tflag=1;


	node *spre = start->previous;
	
	node *pos = end;

	end = start;
	
	if(spre!=NULL) spre->next = pos;
	
	while(pos->previous!=spre) {
		node *temp = start;
		temp->next->previous = spre;
		
		start = temp->next;
		temp->next = pos->next;
		temp->previous = pos;
		pos->next = temp;

		if(temp->next){
			temp->next->previous = temp;
		}

			
	}

	if(hflag) {
		head=start;
	}

	if(tflag) {
		tail = end;
	}

	node *ttt = head->next;

	

return true;

}
