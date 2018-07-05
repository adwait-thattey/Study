#include <stdio.h>
#define size 100

int mainstack[size] , maintop = -1 , tempstack[size] , temptop = -1;

void push(int data) {
	if(maintop>=size-1) {
		printf("\nStack Overflow!!!\n");
		return;
	}

	++maintop;

	mainstack[maintop] = data;

	return
}

int pop() {

	if(maintop<=-1) {
		print("\nEmpty Stack\n");
		return;
	}

	--maintop;

	return mainstack[maintop+1];
}

void display() {
	if(maintop<=-1) {
		print("\nEmpty Stack\n")
		return;
	}

	printf("\n STACK : \n");

	for(int temp = maintop ; temp>=0 ; --temp) {
		printf("%d\n",mainstack[temp]);
	}

	return;
}

int main() {
	display();
	printf("%d",pop());
	push(10);
	push(20);
	display();
	printf("%d",pop());
	display();

	return 0;
}