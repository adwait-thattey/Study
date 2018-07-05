#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// #include <iomanip>

using namespace std;

template <class T>
void printVector(vector<T> X);
vector<int> convert_to_int_vector(string S);
vector<string> split_string(string str);

struct node
{
    int data;
    node *left;
    node *right;
};

int in_search(vector<int>, int, int, int);
void validate_tree(vector<int> pre_order, vector<int> in_order, int in_start, int in_end);
void print_tree(node *, int depth = 0);
node *new_node(int data);

int main()
{

    vector<int> pre_order, in_order;
    string input;
    cout << "Enter Pre Order Sequence \n";
    getline(cin, input);
    pre_order = convert_to_int_vector(input);

    cout << "\n Enter In Order Sequence \n";
    getline(cin, input);
    in_order = convert_to_int_vector(input);

    validate_tree(pre_order, in_order, 0, in_order.size() - 1);

    //print_tree(tree);

    return 0;
}

node *new_node(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void validate_tree(vector<int> pre_order, vector<int> in_order, int in_start, int in_end)
{
    static int pre_pos = 0;
    if (in_start > in_end)
        return;
    if (pre_pos >= pre_order.size())
        return;

    node *temp = new node;
    temp->data = pre_order[pre_pos];
    /* temp->left =;
    temp->right = NULL; */

    int pos = in_search(in_order, in_start, in_end, pre_order[pre_pos]);
    if(pos==-1) {
        cout<<"Invalid Tree";
        return;
    }
    ++pre_pos;

    validate_tree(pre_order, in_order, in_start, pos - 1);
    validate_tree(pre_order, in_order, pos + 1, in_end);

    return;
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

/*
1 2 4 5 3 6
4 2 5 1 6 3

*/