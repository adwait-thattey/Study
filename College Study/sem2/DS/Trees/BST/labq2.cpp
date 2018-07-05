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

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }

    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }

    return root;
}

void SortInTree(node *root ,int* Arr)
{   static int key=0;

    if (root == NULL)
        return;

    SortInTree(root->left,Arr);
    Arr[key++] = root->data;
    SortInTree(root->right,Arr);
}

int main()
{
    node *root = NULL;
    
    cout << "Enter size of Array ?";
    int N;
    cin >> N;
    int Arr[N];
    cout << "ENter Elements";

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    SortInTree(root, Arr);
    cout << "\nSorted Array : \n";

    for (int i=0;i<N;++i) {
        cout<<" "<<Arr[i];
    }    

  

    return 0;
}
