////////(Sort linked list)(By swapping values)//////////////////////////////////////////////////////////////////////////////////
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

Node* sortLL(Node* head){
    //counting:
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){ cnt0++; }
        
        else if(temp->data == 1){ cnt1++; }
        
        else if(temp->data == 2){ cnt2++; }

        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(cnt0 != 0){
            temp->data = 0; cnt0--;
        }

        else if(cnt1 != 0){
            temp->data = 1; cnt1--;
        }

        else if(cnt2 != 0){
            temp->data = 2; cnt2--;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 6);
    cout<<"Unsorted list"<<endl; print(head);

    Node* sortedhead = sortLL(head);
    cout<<"Sorted list" <<endl; print(head);
}*/
////////////(Approach - 2)(By merging other LL)//////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertmany(Node* &head, int n)
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

void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortLL(Node* head){
    //Creating dummy lists:
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;

    //Create separate list of 0, 1, 2:
    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(zerotail, curr);
        }

        if(curr->data == 1){
            insertAtTail(onetail, curr);
        }

        if(curr->data == 2){
            insertAtTail(twotail, curr);
        }

        curr = curr->next;
    }
    //Merge 3 sublist:
    if(onehead->next != NULL){
        zerotail->next = onehead->next;//1s list is not empty:
    }
    else{
        zerotail->next = twohead->next;//1s list is empty:
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    //Setup Head:
    head = zerohead->next;

    //Delete Dummy Nodes:
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 6);
    cout<< "Unsorted List" <<endl; print(head);

    Node* sorthead = sortLL(head);

    cout<< "Sorted List" <<endl; print(sorthead);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////(Merge 2 Sorted LL)///////////////////////////////////////////////////////////////////////
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

void solve(Node* first, Node* second){
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){

            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{//curr1 and next1 moved forward:
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node* sortTwolist(Node* first, Node* second){
    if(first == NULL){
        return second;
    }

    if(second == NULL){
        return first;
    }

    if(first->data <= second->data){
        sort(first, second);//second has to be adjusted:
    }
    else{
        sort(second, first);//first has to be adjusted:
    }
}

int main()
{

}
///// (Solution - 2) (merging 2 Sorted list)///////////////////////////////////////////////////////////
Node* solve2(Node* first, Node* second) {
    Node* l1 = first;
    Node* l2 = second;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    while (l1 != NULL) {
        temp->next = l1;
    }
    while (l2 != NULL) {
        temp->next = l2;
    }
    return dummy->next;
}