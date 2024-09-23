///(Minimum time to Burn Tree)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<map>
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
        left = right = NULL;
    }
};

node *mappingparent(node *root, int target, map<node *, node *> nodetoparent)
{
    node *res = NULL;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *frontnode = q.front();
        q.pop();

        if (frontnode->data == target)
        {
            res = frontnode;
        }

        if (frontnode->left)
        {
            nodetoparent[frontnode->left] = frontnode;
        }
        if (frontnode->right)
        {
            nodetoparent[frontnode->right] = frontnode;
        }
    }
    return res;
}

int Burn(node* target, map<node*, node*> nodetoparent){
    map<node*, bool> visited;
    queue<node*> q;

    int time = 0;

    q.push(target);
    visited[target] = true;

    while( !q.empty() ){
        int size = q.size();
        bool flag = 0;

        for(int i = 0; i<size; i++){
            node *frontnode = q.front();
            q.pop();

            if(frontnode->left && !visited[frontnode->left]){
                flag = 1;
                q.push(frontnode->left);
                visited[frontnode->left] = 1;
            }
            if(frontnode->right && !visited[frontnode->right]){
                flag = 1;
                q.push(frontnode->right);
                visited[frontnode->right] = 1;
            }
            if(nodetoparent[frontnode] && !visited[nodetoparent[frontnode]]){
                flag = 1;
                q.push(nodetoparent[frontnode]);
                visited[nodetoparent[frontnode]] = 1;
            }
        }

        if(flag == 1){
            time++;
        }
    }
    return time;
}

int Burntime(node* root, int target)
{
    map<node*, node*> nodetoparent;
    node* targetnode = mappingparent(root, target, nodetoparent);

    int ans = Burn(targetnode, nodetoparent);
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
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);

    cout << "Time taken to Burn the the binary tree. "<< Burntime(root, 8);
}