//Morris Traversal - (inorder)/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void morrisTraversal(node* root)
{
    node* curr, *prev;
    curr = root;

    if( root = NULL ){
        return;
    }

    while( curr != NULL ){
        if(curr->left == NULL){
            cout<< curr->data <<" ";
            curr = curr->right;
        }
        else{
            prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                cout<< curr->data <<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right=  new node(70);

    morrisTraversal(root);

    return 0;
}*/
//Morris Traversal - (preorder)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void morrisTraversal(node* root)
{
    node* curr, *prev;
    curr = root;

    if( root==NULL ){
        return;
    }

    while( curr != NULL ){
        if(curr->left == NULL){
            cout<< curr->data <<" ";
            curr = curr->right;
        }
        else{
            prev = curr->left;
             while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
             }
            if(prev->right == NULL){
                cout<< curr->data <<" ";
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->right = new node(6);

    morrisTraversal(root);

    return 0;
}*/
//Morris Traversal - (postorder)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    int data;
    node* left = NULL;
    node* right = NULL;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void morrisTraversal(node* root)
{
    stack<int> s;
    node* curr, *prev;

    if(root == NULL){
        return;
    }
    curr = root;

    while(curr != NULL){
        if(curr->right == NULL){
            s.push(curr->data);
            curr = curr->left;
        }
        else{
            prev = curr->right;
            while(prev->left != NULL && prev->left != curr){
                prev = prev->left;
            }
            if(prev->left == NULL){
                prev->left = curr;
                s.push(curr->data);
                curr = curr->right;
            }
            else{
                curr = curr->left;
                prev->left = NULL;
            }
        }
    }
    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    morrisTraversal(root);

    return 0;
}*/
///(Flatten Binary Tree)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void flatten(node* root)
{
    node* curr, * prev;
    curr = root;

    while(curr != NULL){
        if(curr->left != NULL){
            prev = curr->left;
            while(prev->right != NULL){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void print(node* root){
    while(root->right != NULL){
        cout<< root->data <<" ";
        root = root->right;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    flatten(root);

    print(root);

    return 0;
}