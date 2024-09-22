/////(Merge Sort in LL)///////////////////////////////////////////////////////////////////////////////////////////////
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

Node* findmid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    //Merge 2 Sorted LL:
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;

    return ans;
}

Node* mergeSort(Node* head){
    //base case:
    if(head == NULL || head->next == NULL){
        return head;
    }
    //Finding mid:
    Node* mid = findmid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //Break LL into halves:
    left = mergeSort(left);
    right = mergeSort(right);

    //Merge both left and right parts:
    Node* result = merge(left, right);

    return result;
}

int main()
{
    Node* head = NULL;
    insertmany(head, 5);
    cout<<"LL is :\n"; print(head);

    Node* sorted = mergeSort(head);
    cout<<"Sorted LL si :\n"; print(sorted);

    return 0;
}