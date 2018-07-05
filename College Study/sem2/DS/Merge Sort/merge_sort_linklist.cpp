#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* newNode(int);
void printList(node*);

node* merge(node* head1 , node* head2) {
    node* original_head;
    if(head1->data < head2->data) {
        original_head = head1;
    }
    else {
        original_head = head2;
        node *temp = head2->next;
        head2->next = head1;
        head1 = head2;
        head2 = temp;
    }
    
    while(head1->next != NULL && head2 !=NULL) {
        
        if(head2->data < head1->next->data) {
            node* temp = head2;
            head2 = head2->next;
            temp->next = head1->next;
            head1->next = temp;
            head1 = head1->next;
        }
        else {
            head1 = head1->next;
        }
        
    }
    if(head2!=NULL) {
        head1->next= head2;
    }


    return original_head;

}

void mergeSort(node* &head) {
    if(head==NULL || head->next==NULL) return;
    
    node *slow=head , *fast=head;
    while(1) {
        if(fast){
            fast = fast->next;
            if(fast) fast = fast->next;
            else break;
        }
        else break;
        if(fast)slow = slow->next;
        
    }

    node *head2 = slow->next;
    slow->next = NULL;

    mergeSort(head);
    mergeSort(head2); 
    head = merge(head,head2);

    
}

int main() {

    cout<<"How many elements do u wanna enter?";
int N;
cin>>N;

cout<<"start entering elements:\n";

int x;
cin>>x;	
node *head = newNode(x);
node *temp = head;
for(int i=1;i<N;++i) {
	
	cin>>x;
	temp->next = newNode(x);
temp = temp->next;
}

    printList(head);
    mergeSort(head);
    printList(head);

}

void printList(node* head) {
    if(head==NULL) {
        cout<<"\n";
        return;
    }    
    cout<<head->data<<" ";
    printList(head->next);
}

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
}
