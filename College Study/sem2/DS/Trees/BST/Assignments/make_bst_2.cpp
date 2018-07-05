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
void printLevelOrder(node *root);
int find_height(node *root);
void printLevel(node *root, int level);

template <class T>
void printVector(vector<T> X);

int in_search(vector<int> , int ,int ,int);
node *make_tree_pre_in(vector<int> pre_order, vector<int> in_order, int in_start, int in_end);
node *make_tree_post_in(vector<int> post_order, vector<int> in_order, int in_start, int in_end);
node* make_tree_pre_pos(vector<int> pre_order , vector<int> post_order , int pre_start , int pre_end);

node *newNode(int data)
{
    node *point = new node;
    point->data = data;
    point->left = point->right = NULL;

    return point;
}

node *make_tree_pre_in(vector<int> pre_order, vector<int> in_order, int in_start, int in_end)
{
    static int pre_pos = 0;
    if (in_start > in_end)
        return NULL;
    if (pre_pos >= pre_order.size())
        return NULL;

    node *temp = new node;
    temp->data = pre_order[pre_pos];
    temp->left = NULL;
    temp->right = NULL;

    int pos = in_search(in_order, in_start, in_end, pre_order[pre_pos]);
    ++pre_pos;

    temp->left = make_tree_pre_in(pre_order, in_order, in_start, pos - 1);
    temp->right = make_tree_pre_in(pre_order, in_order, pos + 1, in_end);

    return temp;
}

node *make_tree_post_in(vector<int> post_order, vector<int> in_order, int in_start, int in_end) {

    static int post_pos = post_order.size() - 1;

    if(in_start > in_end) return NULL;

    if(post_pos < 0) return NULL;

    node *temp = newNode(post_order[post_pos]);

    int in_pos = in_search(in_order , in_start , in_end , post_order[post_pos]);

    --post_pos;

    temp->right = make_tree_post_in(post_order , in_order , in_pos+1 , in_end);
    temp->left = make_tree_post_in(post_order , in_order , in_start , in_pos-1);

    return temp;
}

node* make_tree_pre_pos(vector<int> pre_order, vector<int> post_order, int pre_start, int pre_end) {

    if(pre_start>pre_end)
        return NULL;

    node* temp = newNode(pre_order[pre_start]);

    if(pre_start==pre_end) return temp;

    int post_pos = in_search(post_order , 0 , post_order.size()-1,pre_order[pre_start] );
    int pre_pos = in_search(pre_order , pre_start , pre_end , post_order[post_pos-1]);

    temp->left = make_tree_pre_pos(pre_order , post_order , pre_start+1 , pre_pos-1);
    temp->right = make_tree_pre_pos(pre_order , post_order , pre_pos , pre_end);

    return temp;
}

int in_search(vector<int> V, int start, int end, int element)
{

    for (; start <= end; ++start)
    {
        if (V[start] == element)
            return start;
    }
    cout << "Invalid Sequence";
    exit(-1);
    return -1;
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
    printf("%4d", root->data);

    print_tree(root->left, depth + 1);
    cout << endl;
    for (int i = 0; i < depth + 1; ++i)
    {
        cout << "    ";
    }
    print_tree(root->right, depth + 1);
}

void print_level_order_tree(node* root) {

}

bool validate_in_order(vector<int> Arr) {

    for(int i=1;i<Arr.size();++i) {
        if(Arr[i]<Arr[i-1]) return false;
    }
    

    return true;
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

int get_choice() {
    cout<<"\n\n";
    cout<<" Press 1 to make a tree using pre-order and in-order \n";
    cout << " Press 2 to make a tree using post-order and in-order \n";
    cout<<" Press 3 to make a tree using pre-order and post-order \n";
    cout<<" Press any other number to exit\n";

    int choice;
    cin>>choice;

    return choice;
}

node* call_pre_in() {

    vector<int> pre_order, in_order;
    string input,temp;
    cout << "Enter pre order sequence \n";
    getline(cin,input);
    if(input.size()<=0) getline(cin, input);
    
    pre_order = convert_to_int_vector(input);

    if(!validate_pre_order(pre_order,0,pre_order.size()-1)) {
        cout<<"Invalid Pre-order Sequence";
        return NULL;
    }
    cout << "Enter in order sequence \n";

    getline(cin,input);
    if(input.size()<=0) getline(cin, input);

    in_order = convert_to_int_vector(input);

    if (!validate_in_order(in_order))
    {
        cout << "Invalid In-order Sequence";
        return NULL;
    }
    node *tree = make_tree_pre_in(pre_order, in_order, 0, in_order.size() - 1);

    return tree;
}

node* call_post_in() {
    vector<int> post_order , in_order;
    string input;
    cout << "Enter post order sequence\n";
    getline(cin,input);
    if(input.size()<=0) getline(cin, input);
    post_order = convert_to_int_vector(input);

    cout<<"Enter in order sequence\n";

    getline(cin,input);
    if(input.size()<=0) getline(cin, input);

    in_order = convert_to_int_vector(input);

    if (!validate_in_order(in_order))
    {
        cout << "Invalid In-order Sequence";
        return NULL;
    }

    node* tree = make_tree_post_in(post_order , in_order , 0 , in_order.size()-1);

    return tree;
}

node* call_pre_post() {

    vector<int> pre_order, post_order;
    string input;
    cout << "Enter pre order sequence\n";
    getline(cin,input);
    if(input.size()<=0) getline(cin, input);
    pre_order = convert_to_int_vector(input);

    if (!validate_pre_order(pre_order, 0, pre_order.size() - 1))
    {
        cout << "Invalid Pre-order Sequence";
        return NULL;
    }
    cout << "Enter post order sequence\n";

    getline(cin,input);
    if(input.size()<=0) getline(cin, input);

    post_order = convert_to_int_vector(input);

    node *tree = make_tree_pre_in(pre_order, post_order, 0, pre_order.size() - 1);

    return tree;
}

node* menu() {
    int choice = get_choice();
    node* root = NULL;
    switch(choice) {

        case 1: root = call_pre_in(); break;
        case 2: root = call_post_in();break;
        case 3: root = call_pre_post();break;
        default : exit(-1);break;
    }

    return root;
}

int main()
{
    
    node* tree = menu();
    cout<<"\n\nTree Using Level Order : \n\n";
    printLevelOrder(tree);
    /* cout << "\n\nActual Tree Order : \n\n";
    print_tree(tree);
 */
    return 0;
}

void printLevelOrder(node *root)
{
    int h = find_height(root);
    int i;
    for (i = 1; i <= h; i++){
        printLevel(root, i);
        cout<<"\n";
    }    
}

void printLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout<<root->data<<" ";
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int find_height(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = find_height(root->left);
        int rheight = find_height(root->right);

        return ((lheight+1)>(rheight+1))? (lheight+1) : (rheight+1);
    }
}

/*
1 2 4 5 3 6
4 2 5 1 6 3

*/
