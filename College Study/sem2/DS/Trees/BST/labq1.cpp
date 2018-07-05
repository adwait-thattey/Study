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
    else if (root->data == data)
    {
        cout << "Duplicate insertion not allowed";
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

void printPostTree(int *In ,int *Pre , int start , int end)
{   static int preIndex = 0;
    int pos = start;

    if(end<start) return;

    for(int i=start;i<end;++i) {
        if(In[i]==Pre[preIndex]) {
            pos = i;
            break;
        }
    }
    ++preIndex;
    printPostTree(In,Pre,start,pos-1);
    printPostTree(In,Pre,pos+1,end);
    cout<<In[pos];
    
    

}

void quickSort(int *Arr, int low, int high)
{

    /* Assumes last element as pivot */
    if (low >= high)
    {
        return;
    }
    int j = low;

    for (int i = low; i < high; ++i)
    {
        if (Arr[i] < Arr[high])
        {
            swap(Arr[i], Arr[j]);
            ++j;
        }
    }

    swap(Arr[j], Arr[high]);

    quickSort(Arr, low, j - 1);
    quickSort(Arr, j + 1, high);
}
int main()
{
    node *root = NULL;

    cout << "How no of elements in preorder ?";
    int N;
    cin >> N;
    cout << "ENter Preorder";
    int Pre[N];
    int In[N];
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> Pre[i];
        In[i] = Pre[i];
       
    }

    quickSort(In,0,N-1);

    cout << "\nPost Order : \n";
   
    printPostTree(In,Pre,0,N-1);

    return 0;
}
