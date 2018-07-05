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

void travelInOrder(node *Tree);
void travelPreOrder(node* Tree);
void travelPostOrder(node* Tree);

int main() {
    node *Tree = newNode(7);
    Tree->left = newNode(9);
    Tree->right = newNode(4);
    Tree->left->left = newNode(1);
    Tree->left->right = newNode(7);
    Tree->right->left = newNode(2);
    Tree->right->right = newNode(5);

    cout << "Tree : \n";
    cout << "\t\t\t"<<Tree->data<<"\n";
    cout << "\t\t"<<Tree->left->data<<"\t\t"<<Tree->right->data<<"\n";
    cout << "\t"<<Tree->left->left->data<<"\t"<<Tree->left->right->data<<"\t\t"<<Tree->right->left->data<<"\t"<<Tree->right->right->data<<"\n";

    cout<<"\n\n Inorder : ";

    travelInOrder(Tree);

    cout<<"\n PreOrder : ";

    travelPreOrder(Tree);

    cout<<"\n Post Order : ";
    travelPostOrder(Tree);
    return 0;
}
void travelPreOrder(node* Tree) {
    if(Tree==NULL) return;

    cout<<" "<<Tree->data;

    travelPreOrder(Tree->left);
    travelPreOrder(Tree->right);

}

void travelPostOrder(node *Tree)
{
    if (Tree == NULL)
        return;


    travelPostOrder(Tree->left);
    travelPostOrder(Tree->right);

    cout << " " << Tree->data;
}
void travelInOrder(node *Tree) {
    if(Tree==NULL) return;

    travelInOrder(Tree->left);

    cout<<Tree->data<<" ";

    travelInOrder(Tree->right);
}