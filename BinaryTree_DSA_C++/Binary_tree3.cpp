/////(Zig zag traversal)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
#include<vector>
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

vector<int> zigzag(node* root)
{
    vector<int> result;

    if(root == NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while( !q.empty() )
    {
        int size = q.size();
        vector<int> ans(size);

        for(int i = 0; i < size; i++){
            
            node* frontnode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontnode->data;

            if(frontnode->left){
                q.push(frontnode->left);
            }

            if(frontnode->right){
                q.push(frontnode->right);
            }
        }

        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    vector<int> ans = zigzag(root);

    for (int i : ans)
    {
        cout<< i <<" ";
    }

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Boundary traversal in binary tree)/////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
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

void traversalleft(node* root, vector<int> &ans)
{
    if( root == NULL ){
        return;
    }

    if( root->left == NULL && root->right == NULL ){//leaf node not included:
        return;
    }

    ans.push_back(root->data);

    if( root->left ){
        traversalleft(root->left, ans);
    }
    else{
        traversalleft(root->right, ans);
    }
}

void traversalleaf(node* root, vector<int> &ans)
{
    if( root == NULL ){
        return;
    }

    if( root->left == NULL && root->right == NULL ){
        ans.push_back(root->data);
        return;
    }

    traversalleaf(root->left, ans);

    traversalleaf(root->right, ans);
}

void traversalright(node* root, vector<int> &ans)
{
    if( root == NULL ){
        return;
    }

    if( root->left == NULL && root->right == NULL ){
        return;
    }

    if(root->right){
        traversalright(root->right, ans);
    }
    else{
        traversalright(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> BoundaryTraversal(node* root)
{
    vector<int> ans;
    if( root == NULL ){
        return ans;
    }

    ans.push_back(root->data);

    traversalleft(root->left, ans);

    traversalleaf(root, ans);

    traversalright(root->right, ans);

    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right->right = new node(6);
    root->right->right->left = new node(9);

    for(int i : BoundaryTraversal(root)){
        cout<< i <<" ";
    }
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Vertical order traversal)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
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

vector<int> vertical_order(node* root)
{
    map<int, map<int, vector<int>>> nodes;
    queue< pair<node*, pair<int, int>>> q;
    vector<int> ans;

    if( root == NULL ){
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0))); // <root, <hd, lvl>>

    while( !q.empty() ){
        pair<node*, pair<int, int>> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);

        if(frontnode->left){
            q.push(make_pair(frontnode->left, make_pair(hd-1, lvl+1)));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right, make_pair(hd+1, lvl+1)));
        }
    }

    for( auto i : nodes ){
        for(auto j : i.second ){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    vector<int> ans = vertical_order(root);

    for( int i : ans ){
        cout<< i <<" ";
    }
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////(Top view of the Binary tree)//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

vector<int> Topview(node* root)
{
    map<int, int> topnode; // <hd , topnodes_data>
    queue< pair<node*, int>> q; // <node, hd>
    vector<int> ans;

    q.push( make_pair(root, 0));

    while( !q.empty() ){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        if( topnode.find(hd) == topnode.end() ){
            topnode[hd] = frontnode->data;
        }

        if( frontnode->left ){
            q.push(make_pair(frontnode->left, hd-1));
        }

        if( frontnode->right ){
            q.push(make_pair(frontnode->right, hd+1));
        }
    }

    for( auto i : topnode ){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    
    for(auto i : Topview(root) ){
        cout<< i <<" ";
    }
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////(Bottom view of the binary tree)///////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

vector<int> Bottomview(node* root)
{
    map<int, int> btnode;
    queue< pair<node*, int>> q;
    vector<int> ans;

    q.push(make_pair(root, 0));

    while( !q.empty() ){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        btnode[hd] = frontnode->data;

        if( frontnode->left ){
            q.push(make_pair(frontnode->left, hd-1));
        }
        if( frontnode->right ){
            q.push(make_pair(frontnode->right, hd+1));
        }
    }

    for( auto i : btnode ){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    for(int i : Bottomview(root) ){
        cout<< i <<" ";
    } 
}

    //      1      //
    //     / \     //
    //    2   3    //
    //   / \ / \   //
    //  4  5 6  7  //*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Left view of the binary tree)/////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
#include<stack>
#include<vector>
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

vector<int> leftview(node* root){
    map<int, int> leftnode;
    stack< pair<node*, int>> q;
    vector<int> ans;

    q.push(make_pair(root, 0));

    while( !q.empty() ){
        pair<node*, int> temp = q.top();
        q.pop();

        node* frontnode = temp.first;
        int lvl = temp.second;

        leftnode[lvl] = frontnode->data;

        if( frontnode->left ){
            q.push(make_pair(frontnode->left, lvl+1));
        }
        if( frontnode->right ){
            q.push(make_pair(frontnode->right, lvl+1));
        }
    }
    for( auto i : leftnode ){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    root->right->right->left = new node(8);

    for (int i : leftview(root))
    {
        cout << i << " ";
    }

    return 0;
}*/
///(Approach -2 )////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
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

void solve(node* root, vector<int> &ans, int lvl)
{
    if( root == NULL ){
        return;
    }

    if( lvl == ans.size() ){
        ans.push_back(root->data);
    }

    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
}

vector<int> leftview(node* root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    for( int i : leftview(root) ){
        cout<< i <<" ";
    }
}*/
