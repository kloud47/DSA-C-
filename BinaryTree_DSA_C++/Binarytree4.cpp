///(Sum of the longest path in tree)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        left = right = NULL;
    }
};

void solve(node* root, int len , int &maxlen, int sum, int &maxsum)
{
    if( root == NULL ){
        if(len > maxlen){
            maxlen = len;
            maxsum = sum;
        }

        else if(len == maxlen){
            maxsum = max(sum, maxsum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left, len+1, maxlen, sum, maxsum);
    solve(root->right, len+1, maxlen, sum, maxsum);
}

int sumOfLongPath(node* root)
{
    int len = 0, maxlen = 0, sum = 0, maxsum = INT_MIN;
    solve(root, len , maxlen, sum, maxsum);
    return maxsum;
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);

    cout<< sumOfLongPath(root);
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Lowest common Ancestor(LCA)  in a binary tree)////////////////////////////////////////////////////////////////////////////////
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

node* lca(node* root, int n1, int n2)
{
    if( root == NULL ){
        return NULL;
    }

    if( root->data == n1 || root->data == n2 ){
        return root;
    }

    node* leftans = lca(root->left, n1, n2);
    node* rightans = lca(root->right, n1, n2);

    if( leftans != NULL && rightans != NULL ){
        return root;
    }
    else if( leftans != NULL && rightans == NULL ){
        return leftans;
    }
    else if( leftans == NULL && rightans != NULL ){
        return rightans;
    }
    else{
        return NULL;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    node* common = lca(root, 5, 6);

    cout<< common->data;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(K sum paths)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void solve(node* root, int &count, vector<int> path, int k)
{
    if( root == NULL ){
        return;
    }

    path.push_back(root->data);

    solve(root->left, count, path, k);
    solve(root->right, count, path, k);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i >=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
}

int sum(node* root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, count, path, k);
    return count;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(2);
    root->left->left->left = new node(1);

    cout << sum(root, 5);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(kth ancestor in a tree)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
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

node* solve(node* root, int &k, int n)
{
    if( root == NULL ){
        return NULL;
    }

    if( root->data == n ){
        return root;
    }

    node* leftans = solve(root->left, k, n);
    node* rightans = solve(root->right, k, n);

    if(leftans != NULL && rightans == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftans;
    }

    if(leftans == NULL && rightans != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
}

int kth(node* root, int k, int n)
{
    node* ans = solve(root, k, n);
    if( ans == NULL || ans->data == n ){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);

    cout<< kth(root, 3, 6);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//(Maximum Sum of Non-adjacent nodes)//////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
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

pair<int, int> solve(node* root)
{
    if(root == NULL){
        pair<int, int> p = {0, 0};
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);

    return ans;
}

int getmaxsum(node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    root->right->right->right = new node(8);

    cout<< getmaxsum(root);


    return 0;
}