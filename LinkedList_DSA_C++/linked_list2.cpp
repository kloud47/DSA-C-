////(Reversing a linked list)////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insertHead(Node* &head, int d){
  Node* insert = new Node(d);
  insert->next = head;
  head = insert;
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<< temp->data <<" ";
    temp = temp->next;
  }
}

Node* reverseLL(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;
  Node* forward = NULL;

  while(curr != NULL){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }

  return prev;
}

int main()
{
  Node* node1 = new Node(1);
  Node* head = node1;
  insertHead(head, 2);
  insertHead(head, 3);
  print(head);

  cout<< endl << "After the LL is reversed."<<endl;
  Node* head2 = reverseLL(head);
  print(head2);
}*/
/////////////////////////////////////////////////////////////////////////////////////////
//////(Using Recursion Reversing a LL)////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insertmany_head(Node* &head, int n){
  int i = 0;
  while(i < n){
    int d; cin>>d;
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    i++;
  }
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<< temp->data << " ";
    temp = temp->next;  }
}

void solve(Node* &head, Node* curr, Node* prev){
  if(curr == NULL){
    head = prev;
    return;
  }

  Node* forward = curr->next;
  solve(head, forward, curr);
  curr->next = prev;
}

Node* reversed(Node* &head){
  Node* curr = head;
  Node* prev = NULL;
  solve(head, curr, prev);

  return head;
}

int main()
{
  Node* head = NULL;
  insertmany_head(head, 5);
  print(head); cout<<endl;

  Node* head2 = reversed(head);
  print(head2);
}*/
//////////////(Approach - 2////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insertmany_head(Node* &head, int n){
  int i = 0;
  while(i < n){
    int d; cin>>d;
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    i++;
  }
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<< temp->data << " ";
    temp = temp->next;
  }
}

//Return head of the reversed linked list:

Node* reversel(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* newhead = reversel(head->next);
  head->next->next = head;
  head->next = NULL;

  return newhead;
}

Node* reverselist(Node* &head){
  return reversel(head);
}

int main()
{
  Node* head = NULL;
  insertmany_head(head, 5);
  print(head); cout<<endl;

  Node* head2 =  reverselist(head);
  print(head2);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////
///////(find Middle element in a linked list)////////////////
/*#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(int d){
    data = d;
    this->next = NULL;
  }
};

void insertmany_head(Node* &head, int n){
  int i = 0;
  while(i < n){
    int d; cin>>d;
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    i++;
  }
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<< temp->data <<" ";
    temp = temp->next;
  }cout<<endl;
}

int getlen(Node* head){
  int i = 0;
  while(head != NULL){
    i++;
    head = head->next;
  }

  return i;
}

Node* findmid(Node* head){
  int len = getlen(head);
  int mid = (len/2);

  Node* temp = head;
  int i = 0;
  while(i < mid){
    temp = temp->next;
    i++;
  }

  return temp;
}

int main()
{
  Node* head = NULL;
  insertmany_head(head, 5);
  print(head);

  Node* mid = findmid(head);
  cout<< mid->data <<endl;
}*/
///////////(Approach - 2)/////////////////////////////////
#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(int d){
    data = d;
    this->next = NULL;
  }
};

void insertmany_head(Node* &head, int n){
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

Node* middle(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  if(head->next->next == NULL){
    return head->next;
  }

  Node* fast = head->next;
  Node* slow = head;
  while( fast != NULL){
    fast = fast->next;
    if(fast != NULL){
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
}

int main()
{
  Node* head = NULL;
  insertmany_head(head, 5);
  print(head);

  cout<< middle(head)->data <<endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////
