#include <iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node *right;
};

node* newNode(int data) {
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main() {
    int in[] = {4,2,5,1,6,3};
    int pre[] = {1,2,4,5,3,6};
}