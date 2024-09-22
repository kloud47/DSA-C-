///////(Add 2 Numbers represented by LL)///////////////////////////////////////////////////////////////////////////////////////////////
/*#include <iostream>
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
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

Node* add(Node* first, Node* second){
    int carry = 0;

    Node* anshead = NULL;
    Node* anstail = NULL;

    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
        }

        int val2 = 0;
        if(second != NULL){
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum%10;

        insertAttail(anshead, anstail, digit);//Making the answer LL:

        carry = sum/10;
        if(first != NULL){
            first = first->next;
        }

        if(second != NULL){
            second = second->next;
        }
    }

    return anshead;
}

Node* add2list(Node* first, Node* second){
    //Reverse input LL:
    first = reverse(first);
    second = reverse(second);

    //Add 2 LL:
    Node* ans = add(first, second);

    ans = reverse(ans);

    return ans;
}

int main()
{
    Node* head1 = NULL;
    insertmany(head1, 2);
    cout<<"LL 1 => "; print(head1); cout<<endl;

    Node* head2 = NULL;
    insertmany(head2, 3);
    cout<<"LL 2 => "; print(head2); cout<<endl;

    cout<<"Sum of 2 LL is => "; print(add2list(head1, head2));
}*/
