#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};


node *newNode(int);
node *insert_in_bst(node *root, int data);
void printInTree();
void printPostTree();
void printPreTree();
vector<int> convert_to_int_vector(string S);
vector<string> split_string(string str);
void print_tree(node *root, int depth = 0);
template <class T>
void printVector(vector<T> X);
bool search_in_bst(node* root , int element);

node *newNode(int data)
{
    node *point = new node;
    point->data = data;
    point->left = point->right = NULL;

    return point;
}

node *insert_in_bst(node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (root->data == data)
    {
        cout << "Duplicate insertion not allowed";
        exit(-1);
    }
    else if (root->data < data)
    {
        root->right = insert_in_bst(root->right, data);
    }

    else if (root->data > data)
    {
        root->left = insert_in_bst(root->left, data);
    }

    return root;
}

void printInTree(node *root)
{
    if (root == NULL)
        return;

    printInTree(root->left);
    cout << " " << root->data;
    printInTree(root->right);
}

void printPreTree(node *root)
{

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

vector<int> convert_to_int_vector(string S)
{

    vector<string> seperated_string = split_string(S);
    vector<int> input(seperated_string.size());
    for (int i = 0; i < seperated_string.size(); ++i)
    {
        input[i] = stoi(seperated_string[i]);
    }

    return input;
}

vector<string> split_string(string str)
{

    stringstream S(str);
    string word;
    vector<string> V;

    while (S >> word)
    {
        V.push_back(word);
    }

    return V;
}

template <class T>
void printVector(vector<T> X)
{
    cout << "\n";

    for (typename vector<T>::iterator I = X.begin(); I != X.end(); ++I)
    {
        cout << *I << " ";
    }
    cout << "\n";
}

void print_tree(node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }
    printf("%4d->", root->data);

    print_tree(root->left, depth + 1);
    cout << endl;
    for (int i = 0; i < depth + 1; ++i)
    {
        cout << "      ";
    }
    print_tree(root->right, depth + 1);
}

node *make_bst(vector<int> pre_order)
{

    vector<int>::iterator I = pre_order.begin();

    node *root = insert_in_bst(NULL, *I);
    ++I;
    while (I != pre_order.end())
    {
        insert_in_bst(root, *I);
        ++I;
    }

    return root;
}

bool search_in_bst(node* root , int element) {
    if(root==NULL) return false;
    else if(root->data==element) return true;
    else if(root->data > element) return search_in_bst(root->left,element);
    else return search_in_bst(root->right,element);
}

int main()
{
    vector<int> pre_order;
    string input;
    cout << "Enter a sequence of integers to make the bst \n";
    getline(cin, input);
    pre_order = convert_to_int_vector(input);

    node *bst = make_bst(pre_order);

    cout<<"BST created. Enter the element that you want to search : ";
    int x;
    cin>>x;

    bool check = search_in_bst(bst,x);

    if(check==true) cout<<"\nElement Found in BST";
    else cout<<"\n Element not found in BST";

    return 0;
}

/*
1 2 4 5 3 6
4 2 5 1 6 3

*/