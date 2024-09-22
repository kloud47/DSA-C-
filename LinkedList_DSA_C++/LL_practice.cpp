#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node (int val) {
		this->val = val;
		this->next = NULL;
	};

	~Node() {
		int val = this->val;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "memory free for node with data : "<< val <<endl;
	}
};

class Singly_LL {
public:
	Node* head;
	Node* tail;
	// int length;

	void Singly_ll () {
		this->head = NULL;
		this->tail = NULL;
	};

	void push (int val) {
		Node* node = new Node(val);
		if (!this->head) {
			this->head = node;
			this->tail = this->head;
		} else {
		this->tail->next = node;
		this->tail = this->tail->next;
		}
		// this->length++;
	};

	Node* removeFromLast (int n) {
		Node* temp = this->head;
        Node* node = this->head;
        while (n) {
            temp = temp->next;
            n--;
        };
		if (temp == NULL) {
			return this->head->next;
		}
        while (temp->next != NULL) {
            node = node->next;
            temp = temp->next;
        };
		temp = node->next;
		node->next = node->next->next;
		delete temp;

        return this->head;
	}

	int length() {
        int len = 0;
        Node* temp = this->head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }

	// void pop () {
	// 	if(!this->length) cout<< "list is empty." <<endl;
	// };
};

void traverse (Node* head) {
	Node* node = head;
	while (node) {
		cout<< node->val <<" ";
		node = node->next;
	};
};

int main() {
	Singly_LL* list = new Singly_LL();

	list->push(1);
	list->push(2);
	list->push(3);
	list->push(4);
	list->push(5);
	traverse(list->head);
	// cout << list->length <<endl;
	// cout<< list->head->val <<endl;

	// Node* h1 = list->removeFromLast(2);
	// cout << endl << h1->val <<endl;
	cout << list->length() <<endl;
	// traverse(list->head);

	string str = "okla";
	cout << str[1] << str.length() <<endl;

	return 0;
}