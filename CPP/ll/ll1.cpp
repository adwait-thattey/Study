#include <bits/stdc++.h>


using namespace std;

typedef struct NODE {
	int data;
	NODE *next , *prev;
	
} NODE;

void clrscr(){

	for(int i=0;i<100;++i){
		cout<<"\n";
	}
}


struct linkList {
	NODE *start=NULL;
	NODE *end=NULL;
	int size = 0;

	int printList(){

		if(start==NULL){
			cout<<"Empty List!!!";
			return -1;
		}
		NODE *temp = start;
		cout<<"\n\n---LIST START---\n";
		while(temp){
			cout<<temp->data<<"\n";
			temp=temp->next;
		}
		cout<<"---LIST END---\n\n";
		return 0;
	}

	int insertAtEnd(int data){
		if(start==NULL){
			start = new NODE;
			start->data = data;
			start->next=end;
			start->prev = NULL;
			++size;
			return 0;
		}

		if(end==NULL) {
			end = new NODE;
			end->data = data;
			end->next = NULL;
			end->prev = start;
			start->next = end;
			++size;
			return 0;
		}

		NODE *temp = NULL;
		temp = new NODE;
		if(temp==NULL){
			cout<<"Memory Exhausted!!!";
			return -1;
		}
		temp->data = data;
		temp->next = NULL;
		temp->prev = end;
		end->prev->next = temp;
		end->next=temp;
		end = temp;
		++size;
		return 0;

	}

	int del(int pos){
		if(pos>size){
			cout<<"Entered position is more than size of list";
			return -1;
		}

		NODE *temp = start;
		while(pos>1){
			temp=temp->next;
		}

		if(temp==start) {
			temp=temp->next;
			delete temp;
			--size;
			return 0;
		}

		temp->prev->next = temp->next;
		cout<<"Deleted Data is : "<<temp->data;
		delete temp;
		--size;
		return 0;

	}

	int freeList(){
		NODE *temp = start;

		while(start!=NULL){
			temp=temp->next;
			delete start;
			start = temp;

		}
		size=0;
	}
	

};


int main() {

	linkList List;
	
	cout<<"\nNew List Is Created.\n";

	while(true){
	cout<<"Current List Size = "<<List.size<<endl<<"\nWhat do you want to do???\n\n";
	cout<<"(1)Insert New Element\n(2)Print List\n(3)Delete An Existing Element\n(4)Exit\n\nEnter Your Option :";
	int choice;
	cin>>choice;
	if(choice==1){
		cout<<"\nEnter Data:";
		int data;
		cin>>data;
		clrscr();
		List.insertAtEnd(data);
	}

	else if(choice==2){
		clrscr();
		List.printList();
		cout<<"Press Any Key!";
	
		clrscr();
	}
	else if(choice==3) {
		int pos;
		cout<<"Enter the position of Element You Wanna Delete :";
		cin>>pos;
		clrscr();
		List.del(pos);
	}

	else if(choice==4) {
		List.freeList();
		cout<<"GoodBye..";
		exit(0);
	}

	else {
		clrscr();
		cout<<"Invalid Choice";

	}
	
	}

	return 0;
}






/*int printList(NODE*);
int insertAtEnd(NODE* , NODE*);

int main(int argc, char const *argv[])
{
	NODE *start=new NODE , *end=NULL;
	start->data=10;
	start->next=end;	
	cout<<"starting...";
	printList(start);
	cout<<"...\n";
	insertAtEnd(start , end);
	cout<<"...\n";
	printList(start);

	return 0;
}

int printList(NODE *start) {

	if(start== NULL){
		cout<<"List Empty";
		return -2;
	}

	
	cout<<"LIST:\n\n";

	while(start){
		cout<<start->data<<"\n";
	}
}

int insertAtEnd(NODE *end){

	NODE *temp = NULL ;
	temp = new NODE;
	if(temp==NULL) {
		cout<<"No More Meory Available!!";
		return -1;
	}

	cout<<"Enter Data?";
	cin>>temp->data;

	if(end==NULL){
		end=temp;
		start->next=end;
		end->prev=start;
		end->next=NULL;
		return 0;
	}

	end->prev->next=

	temp->next = end;
	end->prev->next = temp;
	temp->prev = end->prev;
	end->prev = temp; 
	return 0;

}

*/