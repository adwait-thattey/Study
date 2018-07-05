#include <stdio.h>
#define size 100

int mainstack[size] , maintop = -1 , tempstack[size] , temptop = -1;

void main_push(); // Function to push into main stack
void temp_push(); // Function to push into a temporary stack
int main_pop(); //function to pop from the main stack
int temp_pop(); //function to pop from the temporary stack
void display(); //Function to display all elements of the main stack
void sortStack(); //Function to sort the main stack


int main() {

	main_push(10);
	main_push(20);
	main_push(100);	
	main_push(50);
	main_push(5);
    main_push(50);
	main_push(75);
	main_push(1023);



	printf("\n\nINITIAL STACK : \n");
	display();
	sortStack();
	printf("\nSTACK AFTER SORTING : \n");
	display();


	return 0;
}




void main_push(int data) {
	if(maintop>=size-1) {
		printf("\nStack Overflow!!!\n");
		return;
	}

	++maintop;

	mainstack[maintop] = data;

	return;
}

void temp_push(int data) {
	if(temptop>=size-1) {
		printf("\nStack Overflow!!!\n");
		return;
	}

	++temptop;

	tempstack[temptop] = data;

	return;
}

int main_pop() {

	if(maintop<=-1) {
		printf("\nEmpty Stack\n");
		return 0;
	}

	--maintop;

	return mainstack[maintop+1];
}

int temp_pop() {

	if(temptop<=-1) {
		printf("\nEmpty Stack\n");
		return 0;
	}

	--temptop;

	return tempstack[temptop+1];
}

void display() {
	if(maintop<=-1) {
		printf("\nEmpty Stack\n");
		return;
	}

	printf("\n STACK : \n");

	for(int temp = maintop ; temp>=0 ; --temp) {
		printf("%d\n",mainstack[temp]);
	}

	return;
}

void sortStack() {

	for (int pos = maintop ; pos>=0 ; --pos) {

		
		
		while(maintop>pos) {
			int temp = main_pop();
			temp_push(temp);
		}

		int current = main_pop();
		int flag=0;
		while(temptop>-1) {
			int temp = temp_pop();

			if(flag==0 && temp<current) {
				main_push(current);
				flag=1;
			}

			main_push(temp);
		}

		if(flag==0) {
			main_push(current);
		}

	}

}
