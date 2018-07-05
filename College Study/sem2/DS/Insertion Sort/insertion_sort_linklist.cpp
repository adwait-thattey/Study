#include "linklist.cpp"

void insertion_sort(linklist &L) {
    
    node *element = L.retHead()->next;

    while(element!=NULL) {

        node *swap_ptr = element->previous;

        while(swap_ptr!=NULL && swap_ptr->data > element->data) {
            swap_ptr = swap_ptr->previous;
        }
        node *temp = element->next;
        L.move(element, swap_ptr);
        
        element=temp; 
    }

}


int main() {

	linklist list;
    cout<<"How many elements do u wanna enter?";
int N;
cin>>N;

cout<<"start entering elements:\n";

for(int i=0;i<N;++i) {
	int x;
	cin>>x;
	list.addAtEnd(x);
}

    list.printList();

    insertion_sort(list);

    list.printList();

    return 0;
}
