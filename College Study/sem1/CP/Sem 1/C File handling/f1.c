#include <stdio.h>


int main() {

	FILE *ftemp;

	ftemp = fopen("Addy.txt","r");
	char str[1024];
	while(fgets(str,1024,ftemp)) {
		
		printf("%s",str);
	}
	return 0;


}
