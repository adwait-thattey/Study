#include "linklist.cpp"
#include <math.h>


void prb2_2(linklist &L) {
	
	for(unsigned int i=1;i<pow(2,L.retSize());++i) {
		node *tail = L.retTail();
		int sum = 0;
		unsigned int temp = i;
		while(temp) {
			if(temp%2) {
				sum+=tail->data;
			}
			tail = tail->previous;
			temp = temp>>1;
		}
		
		if(sum==0) {
			unsigned int temp = i;
			node *t2 = L.retTail();
			
			while(temp) {
				node *temppos = t2;
				t2 = t2->previous;
				if(temp%2) {
					L.deleteAt(temppos);
				}
				
				temp = temp>>1;
			}

		}

	}

}




int main() {

	linklist L;

	L.addAtStart(-2);
	L.addAtStart(3);
	L.addAtStart(2);
	L.addAtStart(-5);
/*	L.addAtStart(-5);
	L.addAtStart(-1);
	L.addAtStart(-2);
	L.addAtStart(1);
	L.addAtStart(-4);
*/	cout<<"Before Deletion!!\n";
	L.printList();
	prb2_2(L);

	cout<<"After Deletion!!\n";
	L.printList();

	

	return 0;
}