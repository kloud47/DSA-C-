/////(Height of a Binary Tree)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Btree(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root "<<endl;
    int d; cin>>d;
    root = new node(d);
    q.push(root);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data for left of "<<temp->data<<endl;
        int leftnode;
        cin>>leftnode;

        if(leftnode != -1){
            temp->left = new node(leftnode);
            q.push(temp->left);
        }

        cout<<"Enter the data for right of "<<temp->data<<endl;
        int rightnode;
        cin>>rightnode;

        if(rightnode != -1){
            temp->right = new node(rightnode);
            q.push(temp->right);
        }
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main()
{
    node* root = NULL;
    Btree(root);

    cout<<height(root);

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Diameter of tree)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        this->left = NULL;
        this->right = NULL;
    }
};

void Btree(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root "<<endl;
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<< temp->data <<endl;
        int leftdata; cin >> leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<< temp->data <<endl;
        int rightdata; cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int diameter(node* root)
{
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->right) + height(root->left) + 1;

    return max(op1, max(op2, op3));
}

int main()
{
    node* root = NULL;
    Btree(root);

    cout<< diameter(root);

    return 0;
}*/
///(Diameter of tree)(Approach -2)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Btree(node* root)
{
    queue<node*> q;
    cout<<"Enter the data of root "<<endl;
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<< temp->data <<endl;
        int leftdata; cin >> leftdata;

        if(leftdata != -1){
            temp->left =  new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<< temp->data <<endl;
        int rightdata; cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

pair<int, int> diameterFast(node* root)
{
    if( root == NULL ){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node* root)
{
    return diameterFast(root).first;
}

int main()
{
    node* root = NULL;
    Btree(root);
    cout<< diameter(root);

    return 0;
}*/
////(check for Balanced tree)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Btree(node* &root){
    queue<node*> q;
    cout<<"Enter the data of root node "<<endl;
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<< temp->data <<endl;
        int leftdata; cin >> leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<< temp->data <<endl;
        int rightdata; cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

bool isBalanced(node* root){
    if( root == NULL ){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(diff && left && right){
        return 1;
    }

    else{
        return 0;
    }
}

int main()
{
    node* root = NULL;
    Btree(root);
    cout<< isBalanced(root);

    return 0;
}*/
////(Approach - 2)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Btree(node* &root){
    queue<node*> q;
    cout<<"Enter the data of the node "<<endl;
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter the data to the left of " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data to  the right of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

pair<bool, int> isBalanced(node* root){
    if( root == NULL ){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftans && rightans && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool balanced(node* root){
    return isBalanced(root).first;
}

int main()
{
    node* root = NULL;
    Btree(root);

    cout<< balanced(root);

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////(Determine if two trees are identical or not)/////////////////////////////////////////////////////////////////
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
        right =  NULL;
    }
};

void Brtree(Node* root){
    queue<node*> q;
    cout<<"Enterr the data for root "<<endl;
    int d; cin>>d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<< temp->data <<endl;
        int leftdata; cin >> leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<< temp->data <<endl;
        int rightdata; cin >> rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

bool isIdentical(node* r1, node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if((r1 == NULL && r2 != NULL) ||  (r1 != NULL && r2 == NULL)){
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;//Using relational operation:


    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main()
{

}*/
//(Sum tree)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Btree(node* &root)
{
    queue<node*> q;
    cout<<"Enter the root data "<<endl;
    int d; cin >> d;
    root = new node(d);
    q.push(root);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<< temp->data <<endl;
        int leftdata; cin >> leftdata;

        if( leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<< temp->data <<endl;
        int rightdata; cin >> rightdata;

        if( rightdata != -1 ){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

pair<bool, int> isSumTreefast(node* root){
    if( root == NULL ){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if( root->left == NULL && root->right == NULL ){// check leaf node:
        pair<bool, int> p = {true, root->data};
    }

    pair<bool, int> left = isSumTreefast(root->left);
    pair<bool, int> right = isSumTreefast(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool condn = root->data == left.second + right.second;

    pair<bool, int> ans;

    if(leftans && rightans&& condn){
        ans.first = true;
        ans.second = 2*(root->data);
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(node* root){
    return isSumTreefast(root).first;
}

int main()
{
    node* root = NULL;
    Btree(root);

    cout<< isSumTree(root);
    cout<< isSumTreefast(root).second;


    return 0;
}