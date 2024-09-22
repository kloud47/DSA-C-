///////////(check Palinndrome)///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
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
    }
}

bool check(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s <= e){
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(Node* head){
    vector<int> arr;

    Node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return check(arr);
}

int main()
{
    Node* head = NULL;
    insertmany(head, 3);
    print(head);

    if(isPalindrome(head)){
        cout<<"\nIs a Palindrome."<<endl;
    }
    else{
        cout<<"\nIs not a Palindrome."<<endl;
    }
}*/
////////////////////(Approach - 2)//////////////////////////////////////////////////////////////////////////////////////////////
/*#include <iostream>
#include <vector>
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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev  = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head->next == NULL){
        return true;
    }

    //Find Middle:
    Node* mid = getMid(head);

    //Reverse List after Mid:
    Node* temp = mid->next;
    mid->next = reverse(temp);

    //Compare both the halves:
    Node* head1 = head;
    Node* head2 = mid->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 5);
    print(head); cout<<endl;

    if(isPalindrome(head)){
        cout<< "It is a Palindrome." <<endl; print(head);
    }

    else{
        cout<< "It is not a Palindrome." <<endl; print(head);
    }
}*/