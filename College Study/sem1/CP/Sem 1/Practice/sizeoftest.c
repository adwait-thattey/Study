#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int a;
 int b;
char Name[20];
struct Node *next;
struct Node *previous;
} Node;

int main() {
Node *n1;
Node *n2;
n1 = (Node *)malloc(sizeof(Node)); 

n2 = (Node *)malloc(sizeof(Node)); 

n1->a=10;
n2->b = 20;
n1->next = n2;
n1->previous = NULL;
n2->previous = n1;
n2->next = NULL;

printf("%d   %d   %d   %d   %d",sizeof(Node),sizeof(n1),sizeof(n1->next),sizeof(n2->next),n1->next->b);

return 0;

}
