#include <iostream>


using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *point = new node;
    point->data = data;
    point->left = point->right = NULL;

    return point;
}

node *insert(node* root , int data) {
    if(root==NULL) {
        root =  newNode(data);
    }
    else if(root->data==data) {
        cout<<"Duplicate insertion not allowed";

    }
    else if(root->data < data) {
        root->right = insert(root->right,data);
    }

    else if(root->data > data) {
        root->left = insert(root->left,data);
    }

    return root;
}

void printInTree(node *root) {
    if(root==NULL) return;

    printInTree(root->left);
    cout<<" "<<root->data;
    printInTree(root->right);
    

}

void printPreTree(node *root) {

    if (root == NULL)
        return;

    
    cout << " " << root->data;
    printPreTree(root->left);
    printPreTree(root->right);
}

void printPostTree(node *root)
{

    if (root == NULL)
        return;

    
    printPostTree(root->left);
    printPostTree(root->right);
    cout << " " << root->data;
}

/*
int main() {
    node *root=NULL;
    
    cout<<"How many elements do u wanna enter ?";
    int N;
    cin>>N;
    cout<<"ENter Elements";

    for (int i=0;i<N;++i) {
        int x;
        cin>>x;
        root = insert(root,x);
    }
    cout<<"\nPre order : \n";
    printPreTree(root);

    cout<<"\nIn Order : \n";
    printInTree(root);

    cout<<"\nPost Order : \n";
    printPostTree(root);

    return 0;
}
*/