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

node* newNode(int);
node* insert_in_bst(node* root , int data);
void printInTree();
void printPostTree();
void printPreTree();
vector<int> convert_to_int_vector(string S);
vector<string> split_string(string str);
void print_tree(node* root , int depth = 0);
template <class T>
void printVector(vector<T> X);

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

vector<int> convert_to_int_vector(string S) {

    vector<string> seperated_string = split_string(S);
    vector<int> input(seperated_string.size());
    for(int i=0;i<seperated_string.size();++i) {
        input[i] = stoi(seperated_string[i]);
    }

    return input;
    
}

vector<string> split_string(string str) {

    stringstream S(str);
    string word;
    vector<string> V;
    
    while(S>>word) {
        V.push_back(word);
    }

    return V;
}

template <class T>
void printVector(vector<T> X) {
    cout<<"\n";
    
    for(typename vector<T>::iterator I = X.begin();I!=X.end();++I) {
        cout<<*I<<" ";
    }
    cout<<"\n";
}

void print_tree(node* root , int depth) {
    if(root==NULL) {
        return;
    }
    printf("%4d->",root->data);
    
    print_tree(root->left,depth+1);
    cout<<endl;
    for(int i=0;i<depth+1;++i) {
        cout<<"      ";
    }
    print_tree(root->right,depth+1);
}

node* make_bst(vector<int> pre_order) {
    
    vector<int>::iterator I = pre_order.begin();

    node *root = insert_in_bst(NULL,*I);
    ++I;
    while(I!=pre_order.end()) {
       insert_in_bst(root,*I);
       ++I; 
    }

    return root;
}

bool validate_pre_order(vector<int> pre_order , int start , int end) {

    if(start>=end) return true;
    int i;
    for(i=start+1;i<=end && pre_order[i]<pre_order[start];++i);
    int pos = i;
    while(i<=end) {
        if(pre_order[i]<pre_order[start]) return false;

        ++i;
    }

    bool left = validate_pre_order(pre_order,start+1,pos-1);
    bool right = validate_pre_order(pre_order,pos,end);

    if(left)
        if(right)
            return true;
            
    return false;
}

int main()
{
    vector<int> pre_order;
    string input;
    cout << "Enter sequence of integers to make the bst \n";
    getline(cin, input);
    pre_order = convert_to_int_vector(input);

    bool check = validate_pre_order(pre_order,0,pre_order.size()-1);
    if(!check) {
        cout<<"Invalid Pre-Order Sequence";
        return 0;
    } 
    node *bst = make_bst(pre_order);

    cout<<"\n Pre Order : \n";
    printPreTree(bst);

    cout << "\n In Order : \n";
    printInTree(bst);

    cout << "\n Post Order : \n";
    printPostTree(bst);

    

    return 0;
}

/*
1 2 4 5 3 6
4 2 5 1 6 3

*/