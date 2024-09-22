////////(Remove duplicates from Sorted LL)//////////////////////////////////////////////////////////////////////
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

void insertmany(Node* &head, int n){
    int i = 0;
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

Node* uniqueSortedList(Node* head){
    //for Empty list:
    if(head == NULL){
        return NULL;
    }

    //for a Non-Empty list:
    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            delete(curr->next);
            curr->next = next_next;
        }

        else{
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 6);
    print(head);

    Node* newlist = uniqueSortedList(head);

    print(newlist);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Remove Duplicates from unsorted LL)//////////////////////////////////////////////////////
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

void insertmany(Node *&head, int n)
{
    int i = 0;
    while (i < n)
    {
        int d;
        cin >> d;
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        i++;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* uniqueUnsortedList(Node* head){
    if(head == NULL){
        return head;
    }

    Node* curr = head;
    
    while(curr != NULL){
        Node* temp = curr;
        while(temp != NULL && temp->next != NULL){
            if(curr->data == temp->next->data){
                Node* next_next = temp->next->next;
                delete(temp->next);
                temp->next = next_next;

                temp = temp->next;
            }

            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 6);
    print(head);

    Node* newlist = uniqueUnsortedList(head);

    print(newlist);
}*/
//////////////////(Approach-2)////////////////////////////////////////////////////////////////////////////////////

//////////(Split LL in two halves)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
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

void insertmany(Node* &head, int n){
    int i = 0;
    while(i<n){
        int d; cin>>d;
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
        i++;
    }
}

void print(Node* head){
    while(head != NULL){
        cout<< head->data <<" ";
        head = head->next;
    }cout<<endl;
}

Node* split(Node* head, int n){
    int i = 0;
    Node* temp = head;
    while(i < n/2){
        temp = temp->next;
        i++;
    }
    Node* head2 = temp->next;
    temp->next = NULL;

    return head2;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 5);
    print(head);

    Node* head2 = split(head, 5);

    print(head);
    print(head2);
}
