//(Build tree form Inorder and Preorder)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
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

void createmapping(map<int, int> &nodeToindex, int in[], int n){
    for(int i = 0; i < n; i++){
        nodeToindex[in[i]] = i;
    }
}

// passing of index (reference by) is very important:
node* solve(int in[], int pre[], int &index,
            int in_start, int in_end, int n, map<int, int> &nodeToindex){

    if(index >= n || in_start > in_end){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);
    // mapping makes finding the element fast:
    int position = nodeToindex[element];

    root->left = solve(in, pre, index, in_start, position-1, n, nodeToindex);
    root->right = solve(in, pre, index, position+1, in_end, n, nodeToindex);

    return root;
}

node* Buildtree(int in[], int pre[], int n){
    int preorderIndex = 0;

    map<int, int> nodeToindex;
    createmapping(nodeToindex, in, n);

    node* ans = solve(in, pre, preorderIndex, 0, n-1, n, nodeToindex);
    return ans;
}

void postorder(node* root)
{
    if( root = NULL ){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}

int main()
{
    int in[6] = {3, 1, 4, 0, 5, 2};
    int pre[6] = {0, 1, 3, 4, 2, 5};

    node* root = Buildtree(in, pre, 6);

    postorder(root);
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Build tree from Inorder and Postorder)//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<map>
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

void createmapping(map<int, int> &nodeToindex, int n, int in[]){
    for(int i = 0; i < n; i++){
        nodeToindex[in[i]] = i;
    }
}

node *solve(int in[], int post[], int &index, 
            int in_start, int in_end, map<int, int> nodeToindex)
{
    if(index < 0 || in_start > in_end){
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);
    int position = nodeToindex[element];

    root->right = solve(in, post, index, position+1, in_end, nodeToindex); // right comes first here:
    root->left = solve(in, post, index, in_start, position - 1, nodeToindex);

    return root;
}

node *Buildtree(int in[], int post[], int n)
{
    int postorder = n-1;

    map<int, int> nodeToindex;
    createmapping(nodeToindex, n, in);
 
    node* ans = solve(in, post, postorder, 0, n-1, nodeToindex);

    return ans;
}

void postorder(node* root){
    if( root == NULL ){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}

int main()
{
    int in[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[8] = {8, 4, 5, 2, 6, 7, 3, 1};

    node* root = Buildtree(in, post, 8);

    postorder(root);

    return 0;
}