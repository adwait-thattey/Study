#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

enum node_color {red,black,double_black};
struct node
{
    int data;
    node_color color;
    node *right;
    node *left;
    node *parent;
};

class red_black_tree {
    private : 
        node* root;
        node* null_node;
    public :
        red_black_tree() {
            null_node = new node;
            null_node->parent = null_node->left = null_node->right = NULL;
            null_node->color = black;
            root = null_node;
            
        }
        
        node* ret_root() {
            return root;
        }

        node *newNode(int key) {
            node *temp = new node;
            temp->data = key;
            temp->color = red;
            temp->right = null_node;
            temp->left = null_node;
            temp->parent = null_node;

            return temp;
        }

        int calc_height(node *point)
        {
            if (point == null_node)
            {
                return -1;
            }

            int l = calc_height(point->left);
            int r = calc_height(point->right);
            if (l > r)
                return 1 + l;
            else
                return 1 + r;
        }

        void print_tree(node* point , int depth);
        
        void print_tree() {
            print_tree(root,0);
        }

        void insert_in_tree(int key) {
            node* insert_position = insert_in_tree(root,key);
            if(insert_position!=null_node) {
                if(root==null_node) root = insert_position;
                repair_tree(insert_position);
            }    
        }
        node* insert_in_tree(node* point , int key);
        
        void delete_from_tree(int key) {
            node* delete_position = delete_from_tree(root,key);
            if(delete_position!=null_node) {
                //delete_position = fix_deletion(delete_position);
                if(delete_position->parent!=null_node){
                    if(delete_position->parent->left==delete_position) delete_position->parent->left = null_node;
                    else delete_position->parent->right = null_node;
                }
                delete delete_position;
            }
        }
        node* delete_from_tree(node* point , int key);
        node* fix_deletion(node* point);

        node* repair_tree(node* cur_pos);
        node* balance_node(node* point);
        node* right_rotate(node* x);
        node* left_rotate(node* x);
        node* get_min(node* point);
        
};

void red_black_tree::print_tree(node *point , int depth) {

    if (point == null_node)
    {
        return;
    }
    printf("%4d,%1d", point->data , point->color);

    print_tree(point->left, depth + 1);
    cout << endl;
    for (int i = 0; i < depth + 1; ++i)
    {
        cout << "      ";
    }
    print_tree(point->right, depth + 1);
}

node* red_black_tree::insert_in_tree(node* point , int key) {
    if(point == null_node) {
        point = newNode(key);
        return point;
    }

    else if(point->data==key) {
        cout<<"!DUPLICATE INSERTIONS NOT ALLOWED";
        return null_node;
    }

    else if(point->data < key) {
        if(point->right==null_node) {
            point->right = insert_in_tree(point->right,key);
            point->right->parent = point;
            return point->right;
        }
        else {
            return insert_in_tree(point->right,key);
        }
    }
    else {
        if(point->left==null_node) {
            point->left = insert_in_tree(point->left,key);
            point->left->parent = point;
            return point->left;
        }
        else {
            return insert_in_tree(point->left,key);
        }
    }

}

node* red_black_tree::repair_tree(node* cur_pos) {
    if(cur_pos->parent==null_node) {
        cur_pos->color = black;
    }
    else if(cur_pos->parent->color==red) {
        node* parent = cur_pos->parent;
        node* grand_parent = parent->parent;
        if(grand_parent->left==parent) { // parent is the left child. Uncle is right
            if(grand_parent->right->color==red) {
                grand_parent->right->color=black;
                parent->color=black;
                grand_parent->color = red;
                
            }
            else {
                swap(parent->color, grand_parent->color);
                grand_parent = balance_node(grand_parent);
            }
            repair_tree(grand_parent);
        }
        else { //parent is right child. uncle is left
            
            if(grand_parent->left->color==red) {
                grand_parent->left->color=black;
                parent->color=black;
                grand_parent->color = red;
                
            }
            else {
                
                swap(parent->color, grand_parent->color);
                grand_parent = balance_node(grand_parent);
            }
            repair_tree(grand_parent);
        }
    }
    else if(cur_pos->parent->color==black) {
        //no need to do anything
    }
    else {
        cout<<"double Black or colorless Exception for key";
        cout<<cur_pos->parent->data;
        exit(-1);
    }
}

node* red_black_tree::balance_node(node* point) {
    int diff = calc_height(point->left) - calc_height(point->right);
    if (diff >= 2)
    {
        // left node more weight
        int subdiff = calc_height(point->left->left) - calc_height(point->left->right);
        if (subdiff > 0)
        {
            //left-left case

            point = right_rotate(point);
        }
        else
        {
            //left-right case

            point->left = left_rotate(point->left);
            point = right_rotate(point);
        }
    }

    else if (diff <= -2)
    {

        int subdiff = calc_height(point->right->left) - calc_height(point->right->right);
        if (subdiff < 0)
        {
            //right-right case

            point = left_rotate(point);
        }
        else
        {
            //right-left case
            point->right = right_rotate(point->right);
            point = left_rotate(point);
        }
    }

    //if(point->parent==null_node) root = point;
    return point;
}

node* red_black_tree::right_rotate(node* x) {
    node* parent_of_x = x->parent;
    node* y = x->left;
    y->parent = x->parent;
    x->parent = y;
    x->left = y->right;
    if(y->right!=null_node) y->right->parent = x;
    y->right = x;
    if(parent_of_x==null_node) root = y;
    else {
        if(parent_of_x->left==x) parent_of_x->left=y;
        else parent_of_x->right=y;
    }
    return y;
}

node *red_black_tree::left_rotate(node* x)
{   node* parent_of_x = x->parent;
    node* y = x->right;
    y->parent = x->parent;
    x->parent = y;
    x->right = y->left;
    if(y->left!=null_node) y->left->parent = x;
    y->left = x;

    if(parent_of_x==null_node) root=y;
    else {
        if(parent_of_x->left==x) parent_of_x->left=y;
        else parent_of_x->right=y;
    }
    return y;
}

node* red_black_tree::delete_from_tree(node* point , int key) {
    if(point==null_node) {
        cout<<"key not found";
        return null_node;
    }
    else if(point->data == key) {
        if(point->left==null_node || point->right==null_node) {
            return point;
        }
        else {
            node* next = get_min(point->right);
            point->data = next->data;
            return next;
        }
    }

    else if(point->data > key) {
        return delete_from_tree(point->left , key);
    }
    else return delete_from_tree(point->right,key);

}


node* red_black_tree::get_min(node* point) {
    if(point->left==null_node) return point;
    else return get_min(point->left);
}

/*
* Main Function
*/

int main() {
    red_black_tree RBT;
    cout<<"How many nodes do u wanna insert ? ";
    int N;
    cin>>N;
    for(int i=0;i<N;++i) {
        int key;
        cin>>key;
        RBT.insert_in_tree(key);
        RBT.print_tree();
    }

    cout<<"How many nodes do u wanna delete ? ";
    
    cin>>N;
    for(int i=0;i<N;++i) {
        int key;
        cin>>key;
        RBT.delete_from_tree(key);
        RBT.print_tree();
    }

    return 0;
}



/*
* Utility Functions
*/
