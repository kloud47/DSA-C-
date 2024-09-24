//(Merge 2 BST)(Approach - 1)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void inorder(node* root, vector<int> &v)
{
    if(root == NULL){
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> merged(v1.size() + v2.size());

    int i = 0, j = 0, k = 0;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            merged[k++] = v1[i++];
        }
        else{
            merged[k++] = v2[j++];
        }
    }

    while(i < v1.size()){
        merged[k++] = v1[i++];
    }

    while(j < v2.size()){
        merged[k++] = v2[j++];
    }

    return merged;
}

node* inorderToBST(int s, int e, vector<int> v)
{
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;

    node* root = new node(v[mid]);

    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);

    return root;
}

node* mergedBST(node* root1, node* root2){
    vector<int> vec1, vec2;
    inorder(root1, vec1); inorder(root2, vec2);

    vector<int> mergedArray = merge(vec1, vec2);

    node* root = inorderToBST(0, mergedArray.size()-1, mergedArray);

    return root;
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
    system("color 02");
    node* root1 = new node(10);
    root1->left = new node(8);
    root1->right = new node(13);
    root1->left->left = new node(4);
    root1->left->left->left = new node(1);
    root1->right->right = new node(16);
    root1->right->right->right = new node(20);

    node* root2 = new node(10);
    root2->left = new node(6);
    root2->right = new node(12);
    root2->left->left = new node(2);
    root2->right->left = new node(11);
    root2->right->right = new node(15);

    node* root3 = mergedBST(root1, root2);
    LOT(root3);

    system("pause");
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//(Merge 2 BST)(Approach - 2)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
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



int main()
{

}