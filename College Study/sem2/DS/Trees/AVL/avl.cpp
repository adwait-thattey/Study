#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

struct node {
    int data;
    
    node* right;
    node* left;    
};

node* newNode(int key) {
    node* temp = new node;
    temp->data = key;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

int calc_height(node* root) {
    if(root==NULL) {return -1;}

    int l = calc_height(root->left);
    int r = calc_height(root->right);
    if(l>r) return 1+l;
    else return 1+r;
}

node* insert_as_bst(node* root , int key) {

    
}

int get_least(node* root) {
    if(root->left==NULL) {
        return root->data;
    }
    return get_least(root->left);
}

node* delete_as_bst(node* root , int key) {
    
}

class avl_tree {
    private :
        node* root;
        node* insert_pointer;
    public :
        avl_tree() {
            root = NULL;
            insert_pointer = NULL;
        }
        node* ret_root() {
            return root;
        }

        node* insert_in_avl(node* point, int key) {
            if (point == NULL)
            {
                point = newNode(key);
                
            }
            else if (point->data == key)
            {
                cout << "Duplicate entries not allowed!\n";
                
            }
            else if (point->data > key)
                point->left = insert_in_avl(point->left, key);
            else
                point->right = insert_in_avl(point->right, key);
            

            point = balance_node(point);
            return point;
        }

        void insert_in_avl(int key) {
            root = insert_in_avl(root , key);
        }

        node* delete_from_avl(node* point , int key) {
            if (point == NULL)
            {
                cout << "\nKey not found!\n";
                return NULL;
                
            }
            else if (point->data == key)
            {
                if (point->left == NULL)
                {
                    if (point->right == NULL)
                    {
                        // node *nullpt = NULL;
                        //Leaf node. No children
                        delete point;
                        
                        return NULL;
                        
                    }
                    else
                    {   // node with only right child
                        node *new_point = point->right;
                        delete point;
                        return new_point;
                    }
                }
                else if(point->right == NULL) {
                    // Node with only left child
                    node* new_point = point->left;
                    delete point;
                    return new_point;
                }
                else
                {   // Leaf with 2 children
                    int new_data = get_least(point->right);
                    point->right = delete_from_avl(point->right, new_data);
                    point->data = new_data;
                    return point;
                    
                }
            }

            else if (point->data < key)
            {
                point->right = delete_from_avl(point->right, key);
                point = balance_node(point);
                return point;
            }
            else
            {
                point->left = delete_from_avl(point->left, key);
                point = balance_node(point);
                return point;
            }
            
        }

        void delete_from_avl(int key) {
            root = delete_from_avl(root , key);
            root = balance_node(root);
        }

        node* balance_node(node* point){
            int diff = calc_height(point->left) - calc_height(point->right);
            if(diff>=2) {
                // left node more weight
                int subdiff = calc_height(point->left->left) - calc_height(point->left->right);
                if(subdiff>0) {
                    //left-left case
                   
                    point = right_rotate(point);
                }
                else {
                    //left-right case
                 
                    point->left = left_rotate(point->left);
                    point = right_rotate(point);
                }
            }

            else if(diff<=-2) {

                int subdiff = calc_height(point->right->left) - calc_height(point->right->right);
                if(subdiff<0) {
                    //right-right case
                
                    point = left_rotate(point);
                }
                else {
                    //right-left case
                    point->right = right_rotate(point->right);
                    point = left_rotate(point);
                }
            }

            return point;
        }


        node* right_rotate(node* x) {
            node* y = x->left;
            x->left = y->right;
            y->right = x;
            return y;
        }

        node* left_rotate(node* x) {
            node* y = x->right;
            x->right = y->left;
            y->left = x;

            return y;
        }
};

void print_tree(node *root, int depth=0)
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

int main() {

    avl_tree AT;
    cout<<"How much do u wanna insert ?";
    int N;
    cin>>N;
    for(int i=0;i<N;++i) {
        int x;
        cin>>x;
        // node* R = AT.ret_root();
        AT.insert_in_avl(x);
        print_tree(AT.ret_root());
        cout<<"\n\n";

    }

    cout << "How much do u wanna delete ?";
    //int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        cout<<"\ndelete?\n";
        int x;
        cin>>x;
        AT.delete_from_avl(x);
        print_tree(AT.ret_root());
    }
    

    return 0;
}

/* Geeks for Geeks snapshot of insertion */
int balance = getBalance(node);
 // getBalance computes left-height - right height

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;