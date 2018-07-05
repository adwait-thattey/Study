#include "linklist.cpp"

void sum(linklist A , linklist B) {

	node *t1 = A.retTail() , *t2 = B.retTail();
	
	linklist S;

	int carry = 0;

	while(t1!=NULL && t2!=NULL){

		int num = t1->data + t2->data + carry;

		carry = num/10;
		

		S.addAtStart(num%10);
		
		t1 = t1->previous;
		t2 = t2->previous;

	}
	node *head = S.retHead();

	if(t1!=NULL){
		while(t1!=NULL){
			int num = t1->data + carry;

			carry = num/10;
		

			S.addAtStart(num%10);
		
			t1 = t1->previous;
		}
	}

	else {

		while(t2!=NULL){
			int num = t2->data + carry;

			carry = num/10;
		

			S.addAtStart(num%10);
		
			t2 = t2->previous;
		}	
	}

	if(carry) S.addAtStart(carry);

	
	head = S.retHead();
	cout<<"\n\n";
	while(head){
		cout<<head->data;
		head=head->next;
	}



}

int main() {

	linklist A,B;
	
	int a,b;

	cout<<"Enter Numbers";
	cin>>a>>b;

	while(a){
		A.addAtStart(a%10);
		a/=10;
	}

	while(b){
		B.addAtStart(b%10);
		b/=10;
	}

	
	linklist S;

	sum(A,B);



	

	
}
