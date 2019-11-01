#include<iostream>
#include<math.h>

using namespace std;

typedef struct node
{
    int val;
    struct node* left = NULL;
    struct node* right = NULL;
    int ht;
} node;

node* const nullNode = new node;

/* Hackerrank problem starts */

node* balanceNode(node* root) {
    
    
    if (abs(root->right->ht - root->left->ht) > 1) {
        // unbalanced tree
        
        node *rt=root->right, *lt=root->left;

        if(rt->ht > lt->ht) {
            // right--? case
            if(rt->left->ht > rt->right->ht) {
                // right--left case
                // convert to right--right
                /*
                    1                       1
                   / \                     / \ 
                  A   3       ---->       A   2
                     / \                     / \
                    2   B                   C   3
                   / \                         / \
                  C   D                       D   B
                 */

                node* rtlt = rt->left;
                rt->left = rtlt->right;
                rtlt->right = rt;
                root->right = rtlt;

                // update heights
                rt->ht = max(rt->left->ht, rt->right->ht);
                rtlt->ht = max(rtlt->left->ht, rtlt->right->ht);
                root->ht = max(root->left->ht, root->right->ht);
                // change rt
                rt = root->right;

            

            }
            
            // right--right case
            
            node* shiftedSubTree = rt->left;
            rt->left = root;
            root->right = shiftedSubTree;

            root->ht = max(root->left->ht, shiftedSubTree->ht) + 1;
            rt->ht = max(rt->right->ht, root->ht) + 1;

            root = rt;

        }
        else {
            // left--? case

            if(lt->right->ht > lt->left->ht) {
                // left--right case
                // convert to left--left

                /*
                    1                       1
                   / \                     / \ 
                  3  A                    2   A 
                / \                      / \
               B   2                    3   D
                  / \                  / \
                 C   D                B  C
                */
            
            

                node *ltrt = lt->right;
                lt->right = ltrt->left;
                ltrt->left = lt;
                root->left = ltrt;    

                lt->ht = max(lt->left->ht, lt->right->ht);
                ltrt->ht = max(ltrt->left->ht, ltrt->right->ht);
                root->ht = max(root->left->ht, root->right->ht);
                // change lt
                lt = root->left;    
            }


            // left--left case

            node* shiftedSubTree = lt->right;
            lt->right = root;
            root->left = shiftedSubTree;

            root->ht = max(shiftedSubTree->ht, root->right->ht) + 1;
            lt->ht = max(lt->left->ht, root->ht) + 1;

            root = lt;
        }
    }

    // cout<<"\n balance end";
    return root;
}

node * insert(node * root,int val)
{   
    if(root == nullNode) {
        root = new node;
        root->val = val;
        root->ht = 0;
        root->right = nullNode;
        root->left = nullNode;
        return root;
    }

	if(root->val >= val) {
        // insert left
        root->left = insert(root->left, val);
        root->ht +=1;
    }
    else {
        // insert right
        root->right = insert(root->right, val);
        root->ht +=1;

    }

    root = balanceNode(root);
    
    return root;
}

void printinorder(node *n){
    if(n==nullNode) {
        return;
    }


    printinorder(n->left);

    cout<<" ("<<n->val<<","<<n->ht<<")";

    printinorder(n->right);
}

void printpreorder(node *n){
    if(n==nullNode) {
        return;
    }

    cout<<" ("<<n->val<<","<<n->ht<<")";
    printpreorder(n->left);

    printpreorder(n->right);
}
/* Hackerrank problem ends */

int main() {

    nullNode->val = 0;
    nullNode->ht = -1;

    cout << "Enter n \n";
    int n;
    cin >> n;

    
    cout << "Start entering values to insert into tree";
    node *root = new node;
    cin >> root->val;
    root->ht = 0;
    root->left = nullNode;
    root->right = nullNode;

    for(int i=1; i<n;++i) {
        int val;
        cin >> val;

        root = insert(root, val);

    }
    
    cout<<"\n inorder";
    printinorder(root);
    cout <<"\n preorder";
    printpreorder(root);

    return 0;
}

/*
4(BF=0) 5(BF=-1) 10(BF=0) 11(BF=0) 27(BF=0)
5(BF=-1) 4(BF=0) 11(BF=0) 10(BF=0) 27(BF=0)
 */