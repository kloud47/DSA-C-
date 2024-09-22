//////////////////(Detect a loop)///////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<map>
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

void insertmany(Node *&head, int n){
    int i = 0;
    while (i < n){
        int d; cin >> d;
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        i++;
    }
}

bool detect_loop(Node* head){
    if(head == NULL){
        return false;
    }

    map <Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL){
        //cycle is present:
        if(visited[temp] == true){
            cout<< "Present on element."<< temp->data <<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;
    insertmany(head, 4);
    tail->next = head->next; //Node now contains a loop:
    
    if(detect_loop(head)){
        cout<< "Loop is present."<<endl;
    }

    else{
        cout<< "loop is not present."<<endl;
    }
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////(Floyd Cycle detection)//////////////////////////////////////////////////////
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

bool floydDetectloop(Node* head){
    if(head == NULL){
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;
    insertmany(head, 4);
    tail->next = head->next;

    if(floydDetectloop(head)){
        cout<< "Loop is present."<<endl;
    }

    else{
        cout<<"Loop is not present."<<endl;
    }
}*/
////////////////////(Find the starting Node)/////////////////////////////////////////////////////////////////////////////////////////////////
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

Node* floydDetectloop(Node* head){
    if(head == NULL){
        return head;
    }

    Node* fast = head;
    Node* slow = head;

    while(slow != NULL || fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }

    return NULL;
}

Node* startingnode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersect = floydDetectloop(head);
    Node* slow = head;

    while(slow != intersect){
        slow = slow->next;
        intersect = intersect->next;
    }

    return slow;
}

int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;

    insertmany(head, 4);
    tail->next = head->next;

    cout<<"Starting Node is : "<< startingnode(head)->data <<endl;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////(Remove the Loop)//////////////////////////////////////////////////////////////////
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

Node *floydDetectloop(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *fast = head;
    Node *slow = head;

    while (slow != NULL || fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node* startingnode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersect = floydDetectloop(head);
    Node *slow = head;

    while (slow != intersect)
    {
        slow = slow->next;
        intersect = intersect->next;
    }

    return slow;
}

void removeloop(Node* head){
    if(head == NULL){
        return;
    }

    Node* startnode = startingnode(head);
    Node* temp = startnode;

    while(temp->next != startnode){
        temp = temp->next;
    }

    temp->next = NULL;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }cout<<endl;
}

int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;

    insertmany(head, 4);
    tail->next = head->next;

    if(floydDetectloop(head) == NULL){
        cout<< "Loop is not present."<<endl;
    }

    else{
        cout<<"Loop is present."<<endl;
    }

    removeloop(head);//Loop is now removed:
    print(head);

    if (floydDetectloop(head) != NULL)
    {
        cout << "Loop is present." << endl;
    }

    else
    {
        cout << "Loop is deleted." << endl;
    }
}