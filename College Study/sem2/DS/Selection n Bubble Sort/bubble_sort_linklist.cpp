#include "linklist.cpp"

void bubble_sort(linklist &L) {

    node *sorted = L.retTail();
    while(L.retHead()!=sorted) {
        
        node *ptr = L.retHead();
        while(ptr!=sorted->previous) {
            if(ptr->data > ptr->next->data) {
                L.swap(ptr,ptr->next);
                ptr = ptr->previous;
            }
            ptr = ptr->next;
        }

        if(ptr->data > ptr->next->data) {
            L.swap(ptr,ptr->next);
            sorted = sorted->next;
            
        }

        sorted = sorted->previous;
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

    bubble_sort(list);

    list.printList();
    return 0;
}
