///(2 sum in BST)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node* left, *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

void inorder(node* root, vector<int> &v){
    if( root == NULL ){
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool twosumBST(node* root, int target){
    vector<int> inorderV;
    //Store inorder -> sorted values:
    inorder(root, inorderV);

    int i = 0, j = inorderV.size()-1;

    while( i < j ){
        int sum = inorderV[i] + inorderV[j];

        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main()
{
    node* root = new node(10);
    root->left = new node(6);
    root->right = new node(12);
    root->left->left = new node(2);
    root->right->left = new node(11);
    root->right->right = new node(15);

    cout<<twosumBST(root, 19);

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Flatten BST - Sorted order)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node* left, *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

void inorder(node* root, vector<int> &v){
    if(root == NULL){
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

node* flatten(node* root){
    vector<int> inorderV;
    inorder(root, inorderV);

    int n = inorderV.size();

    node* LLnode = new node(inorderV[0]);
    node* curr = LLnode;

    for(int i = 1; i<n; i++){
        node* temp = new node(inorderV[i]);

        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return LLnode;
}

void print(node* root)
{
    while(root->right == NULL){
        cout<< root->data <<" ";
        root = root->right;
    }
}

int main()
{
    node* root = new node(10);
    root->left = new node(6);
    root->right = new node(12);
    root->left->left = new node(2);
    root->right->left = new node(11);
    root->right->right = new node(15);

    node* linked = flatten(root);
    print(linked);

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left, *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

void inorder(node* root, vector<int> &v){
    if(root == NULL){
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

node* inorderToBST(int s, int e, vector<int> v){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;

    node* BST = new node(v[mid]);

    BST->left = inorderToBST(s, mid-1, v);
    BST->right = inorderToBST(mid+1, e, v);

    return BST;
}

node* balancedTree(node* root){
    vector<int> inorderV;
    inorder(root, inorderV);

    return inorderToBST(0, inorderV.size()-1, inorderV);
}

void LOT(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
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

int main()
{
    node* root = new node(10);
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->left->left = new node(2);
    root->right->right = new node(16);
    root->right->right->right = new node(20);

    LOT(root); cout<<endl;

    root = balancedTree(root);

    LOT(root);

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//(BST from preorder)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left, *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* solve(vector<int> v, int mini, int maxi, int &i)
{
    if(i >= v.size()){
        return NULL;
    }
    if(v[i] < mini || v[i] > maxi){
        return NULL;
    }

    node* root = new node(v[i++]);
    root->left = solve(v, mini, root->data, i);
    root->right = solve(v, root->data, maxi, i);

    return root;
}

node* preorderToBST(vector<int> &preorder){
    int i = 0;
    return solve(preorder, INT_MIN, INT_MAX, i);
}

void LOT(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
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

int main()
{
    vector<int> v{20, 10, 5, 15, 13, 35, 30, 42};

    node* root = preorderToBST(v);

    LOT(root);

    return 0;
}