////////(Binary Tree)(Level order traversal)///////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

node* buildTree(node* root){
    cout<<"Enter the data => "<<endl;
    int d; cin>>d;
    root = new node(d);

    if(d == -1){
        return NULL;
    }

    cout<<"Enter the data for left of "<< d <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for rigth of "<< d <<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty() ){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){//This is our separator:
            cout<<endl;
            if(!q.empty()){
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
    node* root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Inorder Traversal)(Preorder Traversal)(Postorder Traversal)/////////////////////////////////////////////////////////////////////////////////////////
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
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data => "<<endl;
    int d; cin>>d;
    root = new node(d);

    if(d == -1){
        return NULL;
    }

    cout<<"Enter the data to the left of "<< d <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to the right of "<< d <<endl;
    root->right = buildTree(root->right);

    return root;
}

//Inorder traversal(LNR):
void Inorder(node* root){
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<< root->data <<" ";
    Inorder(root->right);
}

//Preorder traversal(NLR):
void Preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<< root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}


//Postorder traversal(LRN):
void Postorder(node* root){
    if(root == NULL){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<< root->data <<" ";
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<"Print Inorder traversal output."<<endl;
    Inorder(root);

    cout<<"\nPrint Preorder traversal output."<<endl;
    Preorder(root);

    cout<<"\nPrint Postorder traversal output."<<endl;
    Postorder(root);

    return 0;
}*/
////////(Building Binary Tree from level order traversal)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void Build_from_level_order(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root "<<endl;
    int d; cin>>d;
    root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the left of "<< temp->data <<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        
        cout<<"Enter the right of "<< temp->data <<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root = NULL;
    Build_from_level_order(root);
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Inorder postorder preorder traversal)(Iteration)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node
{
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

void Inorder(node* root){
    stack<node*> s;
    node* curr = root;

    while( curr != NULL || !s.empty() ){
        
        while( curr != NULL ){//traverse left till the end:
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout<< curr->data <<" ";

        curr = curr->right;
    }cout<<endl;
}

void Preorder(node* root)
{
    stack<node*> s;
    node* curr = root;

    while( curr != NULL || !s.empty() ){

        while(curr != NULL){

            cout<< curr->data <<" ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        curr = curr->right;
    }cout<<endl;
}

void Postorder(node* root){
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || !s.empty())
    {

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        if( curr != NULL ){
            curr = curr->right;
        }
        cout << curr->data << " ";
    }
    cout << endl;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    Inorder(root);
    Preorder(root);
    Postorder(root);
}