#include <iostream>
using namespace  std;


template <class T>
struct node
{
    T data;
    node* left;
    node* right;
};


template<class T>
void printPreTree(node<T> *root) {

    if (root == NULL)
        return;

    
    cout << " " << root->data;
    printPreTree(root->left);
    printPreTree(root->right);
}

template<class T>
void printPostTree(node<T> *root)
{

    if (root == NULL)
        return;

    
    printPostTree(root->left);
    printPostTree(root->right);
    cout << " " << root->data;
}

template <class T>
node<T>* newNode(T data) {
    node<T> *temp = new node<T>;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

template <class T>
int get_tree_height(node<T> *root) {
    if(root==NULL) return 0;
        
    int lh = get_tree_height(root->left);
    int rh = get_tree_height(root->right);
    
    return (lh+1 > rh+1)?lh+1:rh+1; 
}

 template <class T>
node<T>* insert_in_random_tree(node<T>* root , T data) {
    if(root==NULL) {
        root = newNode(data);
        return root;
    }

    else if(get_tree_height(root->left) < get_tree_height(root->right)) root->left = insert_in_random_tree(root->left,data);
    else root->right = insert_in_random_tree(root->right,data);

    return root;
    
}


int main() {

    node<int> *root =NULL;
    
    root = insert_in_random_tree(root,10);
    cout<<get_tree_height(root)<<" ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";

    root = insert_in_random_tree(root, 10);
    cout << get_tree_height(root) << " ";


    printPostTree(root);
    printPreTree(root);

    return 0;
}