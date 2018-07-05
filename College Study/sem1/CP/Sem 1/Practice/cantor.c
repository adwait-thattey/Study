#include <stdio.h>
#include <stdlib.h>
#define LINE struct line
#define crline (LINE *)malloc(sizeof(LINE))
#define la LINE *line
struct line {

	float start;
	float end;
	LINE *next;

};


void printLines(la){

if(line==NULL) return;

printf("%4.2f  %4.2f\n",line->start , line->end);

if(line->next !=NULL) printLines(line->next);

}

void split(la) {

	if(line==NULL) return;

	LINE *temp = crline;
	float length = line->end - line->start;

	temp->end = line->end;
	temp->start = line->end - length/3;
	temp->next = line->next;
	line->end = line->start + length/3;
	if(line->next!=NULL) split(line->next);

	line->next = temp;

}

void createCantorITER(la , int k) {

	while(k>0) {
		--k;
		split(line);
	}

}
int main(int agc , char *agv[]) {

la;
line = crline;
line->start = (agc>1)? (float)atoi(agv[1]) : 0.0;
line->end = (agc>2)? (float)atoi(agv[2]) : 10;
int k = (agc>3)? atoi(agv[3]) : 2;
line->next = NULL;
createCantorITER(line , k);
printLines(line);
return 0;
}


