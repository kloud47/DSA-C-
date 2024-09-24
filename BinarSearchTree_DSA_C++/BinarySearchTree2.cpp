//(Valid - BST)(Approach - 1)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<climits>
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

bool isBST(node* root, int min, int max)
{
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        isBST(root->left, min, root->data);
        isBST(root->right, root->data, max);
    }
    else{
        return false;
    }
}

bool validateBST(node* root)
{
    isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    cout << validateBST(root);

    return 0;
}*/
//(Valid - BST)(Approach - 2)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node
{
public: 
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<int> inorder(node* root, vector<int> v){
    if(root == NULL){
        return v;
    }

    inorder(root->left ,v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool check(node* root){
    static vector<int> v;
    v = inorder(root, v);

    vector<int> v1 = v;
    sort(begin(v1), end(v1));

    bool status = true;
    int j = 0;
    for(int i : v){
        if(i != v1[j++]);
        {
            status = false;
        }
    }
    return status;
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    cout<< check(root);

    return 0;
}*/
//(kth - smallest element)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
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

int solve(node* root, int &i ,int k)
{
    if(root == NULL){
        return -1;
    }
    //L
    int left = solve(root->left, i, k);

    if(left != -1){
        return left;
    }
    //N
    i++;
    if(i == k){
        return root->data;
    }
    //R
    solve(root->right, i , k);    
}

int k_smallest(node* root, int k){
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->left->right = new node(3);
    root->right->right = new node(10);
    root->right->left = new node(6);
    root->right->left->right = new node(7);

    inorder(root); cout<<endl;

    cout<< k_smallest(root, 4);

    return 0;
}*/
//(Inorder -> Successor & predecessor)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class node
{
public:b
    int data;
    node* left, *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

pair<int, int> pred_succ(node* root, int k)
{
    int pred = -1;
    int succ = -1;

    while(root->data != k){
        if(root->data > k){
            succ = root->data;
            root = root->left;
        }
        else{
            pred = root->data;
            root = root->right;
        }
    }

    //pred and succ:

    //pred:
    node* lefttree = root->left;
    while(lefttree != NULL){
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    //succ:
    node* righttree = root->right;
    while(righttree != NULL){
        succ = righttree->data;
        righttree = righttree->left;
    }

    //return make_pair(pred, succ);
    return {pred, succ};
}

void inorder(node* root)
{
    if( root == NULL ){
        return;
    }

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->left->right = new node(3);
    root->right->right = new node(10);
    root->right->left = new node(6);
    root->right->left->right = new node(7);

    inorder(root); cout<<endl;

    cout<< "Predecessor is : "<< pred_succ(root, 8).first <<endl;
    cout<< "Successor is : "<< pred_succ(root, 8).second;

    return 0;
}