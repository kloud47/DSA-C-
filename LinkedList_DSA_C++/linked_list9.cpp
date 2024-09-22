//////////(Clone a Linked List with random pointers)(With unordered MAP)////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* random;//Random pointer node:
    Node(int d){
        data = d;
        next = NULL;
        random = NULL;
    }
};

void printlist(Node* head){
    cout<< head->data <<"(" << head->random->data <<")";
    head = head->next;
    while(head != NULL){
        cout<< " -> " << head->data <<"(" << head->random->data << ")";
        head = head->next;
    }

    cout<< endl;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* cloneLL(Node* head){
    //Create a clone List:
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    //Create a MAP:
    unordered_map<Node*, Node*> oldTonew_Node;//map<key, value>:

    Node* originalnode = head;
    Node* clonenode = cloneHead;
    while(originalnode != NULL){
        oldTonew_Node[originalnode] = clonenode;
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }

    originalnode = head;
    clonenode = cloneHead;
    while(originalnode != NULL){
        clonenode->random = oldTonew_Node[originalnode->random];
        originalnode = originalnode->next;
        clonenode = clonenode->next;
    }

    return cloneHead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next->next;

    cout<<"The original Linked List: \n";
    printlist(head);

    Node* cloned = cloneLL(head);

    cout<< "\nThe cloned Linked list: \n";
    printlist(cloned); cout<<"Cloning is successful.";

    return 0;
}*/
//////////////////(Approach -2)(without MAP)////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* random;
    Node(int d){
        data = d;
        next = NULL;
        random = NULL;
    }
};

void printlist(Node* head){
    cout<< head->data <<"("<< head->random->data <<")";
    head = head->next;
    while(head != NULL){
        cout<<" -> " <<head->data<<"("<< head->random->data <<")";
        head = head->next;
    }
}

void insertAttail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* cloneLL(Node* head){
    //Create a clone LL:
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL){
        insertAttail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    //Merge clone LL and original LL:
    Node* originalnode = head;
    Node* clonenode = cloneHead;

    while(originalnode != NULL && clonenode != NULL){
        Node* next = originalnode->next;
        originalnode->next = clonenode;
        originalnode = next;

        next = clonenode->next;
        clonenode->next = originalnode;
        clonenode = next;
    }

    //random pointer copy:
    temp = head;
    while(temp != NULL){
        temp->next->random = temp->random ? temp->random->next : temp->random;//if temp->random = NULL:
        temp = temp->next->next;
    }

    //Revert back changes to both LL:
    originalnode = head;
    clonenode = cloneHead;

    while(originalnode != NULL && clonenode != NULL){
        originalnode->next = clonenode->next;
        originalnode = originalnode->next;

        if(originalnode != NULL){
            clonenode->next = originalnode->next;
        }
        clonenode = clonenode->next;
    }

    //return the Answer:
    return cloneHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << "The original Linked List: \n";
    printlist(head);

    Node *cloned = cloneLL(head);

    cout << "\nThe cloned Linked list: \n";
    printlist(cloned);
    cout << "Cloning is successful.";

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
