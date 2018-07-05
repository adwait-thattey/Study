#include "linklist.cpp"

using namespace std; 
class tempList{
public :
	linklist L;

	void selctionSort() {
		node *swapPointer = L.retHead(); 
		node *minPointer = L.retHead() , *temp;
		temp = L.retHead();
		while (swapPointer->next) {
			
			minPointer = swapPointer;
			temp = swapPointer;
			while (temp) {
			
				if (temp->data < minPointer->data)
					minPointer = temp;
				temp = temp->next;
			}
			
			temp = swapPointer;
			swapPointer = swapPointer->next;
			L.swap(temp, minPointer);
		}

	}
};


int main() {
	tempList T;
	cout<<"How many elements do u wanna enter?";
int N;
cin>>N;

cout<<"start entering elements:\n";

for(int i=0;i<N;++i) {
	int x;
	cin>>x;
	T.L.addAtEnd(x);
}

	T.L.printList();
	
	T.selctionSort();

	T.L.printList();

	cin.get();
	
	return 0;

}
