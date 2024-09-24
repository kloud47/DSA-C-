///(Insertion in Binary search tree)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<queue>
using namespace std;

class node
{
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

void LOT(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if( temp == NULL ){
            cout<<endl;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data <<" ";
            if( temp->left ){
                q.push(temp->left);
            }
            if( temp->right ){
                q.push(temp->right);
            }
        }
    }
}

node *insertintoBST(node *&root, int d)
{
    if (root == NULL)// root is only formed when it meets a NULL:
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        // Insert at rigth part:
        root->right = insertintoBST(root->right, d);
    }
    else
    {
        // Insert at left part:
        root->left = insertintoBST(root->left, d);
    }

    return root;
}

void takeinput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertintoBST(root, data);
        cin >> data;
    }
}

int main()
{
    node* root = new node(7);
    root->left = new node(5);
    root->right = new node(9);

    cout<< "Insert in BST." <<endl;
    takeinput(root);

    LOT(root);

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Search in Binary search tree)/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;

class node
{
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

void LOT(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if( temp == NULL ){
            cout<<endl;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data <<" ";
            if( temp->left ){
                q.push(temp->left);
            }
            if( temp->right ){
                q.push(temp->right);
            }
        }
    }
}
// Using recursion:
bool searchinBST(node* root, int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k){
        return true;
    }

    if(k > root->data){
        searchinBST(root->right, k);
    }
    else{
        searchinBST(root->left, k);
    }
}

// Using iteration:(Space complexity reduces)
bool searchBST(node* root, int k)
{
    node* temp = root;

    while(temp != NULL)
    {
        if(temp->data == k){
            return true;
        }
        else if( temp->data > k){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

int main()
{
    node *root = new node(7);
    root->left = new node(5);
    root->right = new node(9);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->left->right = new node(5);
    root->right->left = new node(8);
    root->right->right = new node(10);
    root->right->right->right = new node(11);

    LOT(root);
    cout<< "\nSearch in BST." <<endl;

    cout<< searchBST(root, 3);

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//(Min and Max value in BST)////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

void LOT(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int minBST(node* root){
    while( root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int maxBST(node* root){
    while( root->right != NULL ){
        root = root->right;
    }
    return root->data;
}

int main()
{
    node *root = new node(7);
    root->left = new node(5);
    root->right = new node(9);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->left->right = new node(4);
    root->right->left = new node(8);
    root->right->right = new node(10);
    root->right->right->right = new node(11);

    LOT(root);
    cout<<"\nMin value in BST."<< minBST(root);
    cout<< endl <<"Max value in BST."<< maxBST(root);
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Deletion in BST)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
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

void LOT(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if( !q.empty() ){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

 miniVal(node* root)
{
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

node* BST_delete(node* root, int val){
    if( root == NULL ){
        return NULL;
    }

    if(root->data == val){
        // 0 child:
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child:
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 child:
        if(root->left != NULL && root->right != NULL){
            int mini = miniVal(root->right);
            root->data = mini;
            root->right = BST_delete(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = BST_delete(root->left, val);
        return root;
    }
    else{
        root->right = BST_delete(root->right, val);
        return root;
    }
}

int main()
{
    node* root = new node(50);
    root->left = new node(40);
    root->right = new node(60);
    root->left->left = new node(30);
    root->left->right = new node(45);
    root->left->right->left = new node(42);
    root->left->right->right = new node(47);
    root->left->right->right->left = new node(46);
    root->right->right = new node(80);
    root->right->right->left = new node(75);

    LOT(root);cout<<endl;

    inorder(root);

    BST_delete(root, 70); BST_delete(root, 50);
    
    cout<<endl;cout<<endl;

    LOT(root);

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
