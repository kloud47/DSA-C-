/////////////(Reverse in group of k)///////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertmany_node(Node* &head, int n){
    int i= 0;
    while(i < n){
        int d; cin>>d;
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
        i++;
    } 
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }cout<<endl;
}

Node* k_reversel(Node* head, int k){
    //base call
    if(head == NULL){
        return NULL;
    }

    //reverse first k nodes:
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //Recursive call for the rest => (Join head of successive k groups):
    if(next != NULL){
        head->next = k_reversel(next, k);
    }

    return prev;
}

int main()
{
    Node* head = NULL;
    insertmany_node(head, 6);
    print(head);

    Node* head2 = k_reversel(head, 3);
    print(head2);
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
//////(Check if LL is circular or Not)//////////////////////////////////
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        this->next = NULL;
    }
};

void insertmany(Node* &tail, int n){
    int i = 0;
    while(i < n){
        int d; cin>>d;
        Node* temp = new Node(d);
        temp->next = tail;
        tail = temp;
        i++;
    }
}

void insertnode(Node *&tail, int element, int d)//for Cicular Linked list:
{
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }

    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

bool iscircular(Node* tail){
    if(tail == NULL){
        return 0;
    }

    Node* temp = tail->next;
    while(temp != NULL && temp != tail){
        temp = temp->next;
    }

    if(temp == NULL){
        return false; //is not circular:
    }

    else if(temp == tail){
        return true; //is circular:
    }
}

int main()
{
    Node *tail = NULL;
    insertnode(tail, 0, 1);
    insertnode(tail, 1, 2);
    insertnode(tail, 2, 3);
    insertnode(tail, 1, 0);
    print(tail);

    insertmany(tail, 4);

    if(iscircular(tail)){
        cout<< "Is circular."<<endl;
    }

    else{
        cout<<"Is not circular."<<endl;
    }
}