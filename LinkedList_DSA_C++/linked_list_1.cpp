////////(Creating a linked list)//////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Node{
public:
  string data;
  Node* next;

  Node(string data){
    this->data = data;
    this->next = NULL;
  }

  ~Node(){
    int value = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }
    cout<< "memory is free for node with data. "<< value <<endl;
  }
};

void InsertAt_Head(Node* &head, string d){
  //New node creation:
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}

void InsertAt_tail(Node* &tail, int d){
  //New node creation:
  Node* temp = new Node(d);
  tail->next = temp;
  tail = tail->next;
}

void InsertAt_position(Node* &tail, Node* &head, int position, int d){
  //Insert at start:
  if(position == 1){
    InsertAt_Head(head, d);
    return;
  }
  //To get the position:
  Node* temp = head;
  int count = 1;
  while(count < position-1){
    temp = temp->next;
    count++;
  }
  //Insert at end:
  if(temp->next == NULL){
    InsertAt_tail(tail, d);
    return;
  }
  //Insert at the position given:
  Node* insertnode = new Node(d);
  insertnode->next = temp->next;
  temp->next = insertnode;
}

void print(Node* &head)
{
  Node* temp = head;

  while(temp != NULL){
    cout<< temp->data <<" ";
    temp = temp->next;
  }
  cout<<endl;
}

void deleteNode(int position, Node* &head){
  if(position == 1){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else{
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while(count < position){
      prev = curr;
      curr = curr->next;
      count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  Node* node1 = new Node("ok");

  Node* head = node1;
  InsertAt_Head(head, "ok");
  InsertAt_Head(head, "okkk");
  InsertAt_Head(head, "Priyanshu");
  // InsertAt_Head(head, 13);
  print(head);//Print the Linked List:

  Node* tail = node1;
  InsertAt_tail(tail, 9);
  InsertAt_tail(tail, 8);
  InsertAt_tail(tail, 7);
  print(head);

  InsertAt_position(tail, head, 3, 100); cout<<"Insertion at position 3 => ";
  print(head);

  //Insertion ini beginning:
  InsertAt_position(tail, head, 1, 101); cout<<"Insertion at position 1 => ";
  print(head);

  //Insertion at End:
  InsertAt_position(tail, head, 10, 102); cout<<"Insertion at position 10 => ";
  print(head);

  deleteNode(1, head);//100 is removed:
  deleteNode(1, head);//13 is removed:
  print(head);
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Doubly Linked List)///////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* prev;
  Node* next;

  Node(int d){
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }

  ~Node(){
    int val = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }
    cout<<" memory is free for node with data => "<< val <<endl;
  }
};

void deleteNode(int position, Node* &head){
  //Deleting 1st Node:
  if(position == 1){
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }

  //Deleting middle node or last node:
  Node* curr = head;
  Node* prev = NULL;

  int cnt = 1;
  while(cnt < position){
    prev = curr;
    curr = curr->next;
    cnt++;
  }

  curr->prev = NULL;
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
}

void inserthead(Node* &tail, Node* &head, int d){
  if(head == NULL){//Corrections
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
  }
  else{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

void inserttail(Node* &tail, Node* &head, int d){
  if(tail == NULL){//Corrections
    Node* temp = new Node(d);
    tail = temp;
    head = temp;
  }
  else{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAt_position(Node* &tail, Node* &head,int position, int d){
  Node* temp = head;
  int count = 1;
  while(count < position-1){
    temp = temp->next;
    count++;
  }

  //Insertion at start:
  if(position == 1){
    inserthead(tail, head, d);
    return;
  }
  //Insertion at end:
  if(temp->next == NULL){
    inserttail(tail, head, d);
    return;
  }

  Node* insertNode = new Node(d);
  insertNode->next = temp->next;
  temp->next->prev = insertNode;
  temp->next = insertNode;
  insertNode->prev = temp;

}

//Traversing a linked list:
void print(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<< temp->data <<" ";
    temp = temp->next;
  }
  cout<< endl;
}


int getlength(Node* head){
  int len = 0;
  Node* temp = head;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }

  return len;
}

int main()
{
  Node* node1 = new Node(10);
  Node* head = NULL;
  Node* tail = NULL;

  cout<< getlength(head) <<endl;

  inserthead(tail, head, 9);
  inserthead(tail, head, 8);
  print(head);

  inserttail(tail, head, 11);
  inserttail(tail, head, 12);
  print(head);

  insertAt_position(tail, head, 2, 100);
  print(head);
  insertAt_position(tail, head, 1, 101);
  insertAt_position(tail, head, 7, 111);
  print(head);

  deleteNode(3, head);
  deleteNode(6, head);
  print(head);

  return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Circular Linked List)////////////////////////////////////////
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

  ~Node(){
    int value = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }
    cout<<"Memory is free for Node with data => "<< value <<endl;
  }
};

void insertNode(Node* &tail, int element, int d){
  //Empty list:
  if(tail == NULL){
    Node* newNode = new Node(d);
    tail = newNode;
    newNode->next = newNode;
  }
  else{//For non-Empty list:
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }

    //If element found:
    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
  }
}

void print(Node* &tail){
  //For a single node:
  /*if(tail->next == tail){
    cout<< tail->data ;
  }
  //For more than one node:
  Node* temp = tail;
  while(temp->next != tail){
    cout<< temp->data <<" ";
    temp = temp->next;
  }*//*
  //////////////////////////(Using do while loop)
  Node* temp = tail;

  do{
    cout<< temp->data <<" ";
    temp = temp->next;
  } while(temp != tail);
  cout<<endl;
}

void deleteNode(Node* &tail, int value){
  //Empty list:
  if(tail == NULL){
    cout<<"List is already empty." <<endl;
    return;
  }
  else{
    //Non-Empty list:
    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data != value){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  //Inserting in empty List:
  Node* tail = NULL;
  insertNode(tail, 0, 3);
  insertNode(tail, 3, 4);
  insertNode(tail, 4, 5);
  print(tail);

  insertNode(tail, 3, 100);
  insertNode(tail, 4, 101);
  print(tail);

  deleteNode(tail, 100);
  print(tail);
}*/
///////////////////////////////////////////////////////////////////////////
