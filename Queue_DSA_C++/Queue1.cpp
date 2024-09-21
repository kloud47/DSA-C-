//////(Queues)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"Size of queue is : "<< q.size() <<endl;

    q.pop();

    cout<<"Size of queue is : "<< q.size() <<endl;

    while( !q.empty() ){
        cout<< q.back() <<" ";
        cout<< q.front() <<" ";
        q.pop();
    }
}*/
///////////(Queues Implementation using Array)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue(){
        int size = 10000;
        arr = new int(size);
        qfront = rear = 0;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Queue is full."<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront == rear){
            return -1;
        }
        else{
            int poped = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = rear = 0;
            }
            return poped;
        }
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if(qfront == rear){
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    while( !q.isEmpty() ){
        cout<< q.front() <<" ";
        q.dequeue();
    }
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Circular Queue)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    CircularQueue(int size){
        this->size = size;
        arr = new int(size);
        front = rear = -1;
    }

    bool enqueue(int data){
        if((front == 0 && rear == size-1) || (rear = (front-1)%(size-1))){
            cout<<"Queue is already full."<<endl;
            return false;
        }
        else if(front == -1){//First element is needed to be pushed:
            front = rear = 0;
        }
        else if(front != 0 && rear == size - 1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    int dequeue(){
        if(front == -1){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){//Only one element is present:
            front = rear = -1;
        }
        else if(front == size-1){//last element is poped:
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};

int main()
{
    CircularQueue cq(5);
    cq.enqueue(1);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cout<< cq.dequeue();
    cq.enqueue(6);
    cq.enqueue(7);

    return 0;
}*/
//////(Input restricted Queue)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

template <typename T>
class Iqueue {
    T* arr;
    int front;
    int rear;
    int size;
public:
    Iqueue(int n) {
        size = n
        front = rear = -1;
        this->arr = new T(size);
    }

    bool push_rear(int data) {
        if (rear == this->size) return false;
        else if (this->rear == -1) {
            this->arr[++rear] = data;
            this->front++;
        }
        else {
            rear++;
            this->arr[rear] = data;
        }
        return true;
    }

    int pop_front() {
        if (this->rear == -1) return false;
        else if (this->rear == 0) {
            this->rear = this->front = -1
        }
        else {
            this->front++;
        }
    }

    int pop_rear() {
        if (this->rear == -1) return false;

    }
};

//////(Output restricted Queue)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////(Doubly ended Queue)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;


int main()
{
    deque<int> d;
    d.push_front(12); d.push_back(14);

    cout<< d.front() <<endl;
    cout<< d.back() <<endl;

    d.pop_front();
    cout<< d.front() <<endl;;

    return 0;
}*/
/////(Doubly ended queue Implementation using Array)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;

// class Deque
// {
//     int *arr;
//     int front;
//     int rear;
//     int size;
// public:   
//     Deque(int n){
//         size = n;
//         arr = new int(n);
//         front = rear = -1;
//     }

//     bool isFull()
//     {
//         if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (rear - 1)))
//         {
//             return true;
//         }
//         return false;
//     }

//     bool push_front(int data){
//         if( isFull() ){
//             return false;
//         }
//         else if(front == -1){//when the deque is empty:
//             front = rear = 0;
//         }
//         else if(front == 0){
//             front = size-1;
//         }
//         else{
//             front--;
//         }
//         arr[front] = data;

//         return true;
//     }

//     bool push_rear(int data){
//         if( isFull() ){
//             cout<<"Queue is full."<<endl;
//             return false;
//         }
//         else if(rear == -1){//When deque is empty:
//             front = rear = 0;
//         }
//         else if(rear == size-1 && front != 0){
//             rear = 0;
//         }
//         else{
//             rear++;
//         }
//         arr[rear] = data;
//         return true;
//     }

//     int pop_front(){
//         if(front == -1){
//             return -1; //Empty Deque:
//         }
//         int ans = arr[front];
//         arr[front] = -1;
//         if(front == rear){//Single element is present:
//             front = rear = -1;
//         }
//         else if(front = size-1){//front is the last element:
//             front = 0;
//         }
//         else{
//             front++;
//         }
//         return ans;
//     }

//     int pop_rear(){
//         if(rear == -1){
//             return -1;
//         }
//         int ans = arr[rear];
//         arr[rear] = -1;
//         if(front == rear){
//             front = rear = -1;
//         }
//         else if(rear == 0){
//             rear = size-1;
//         }
//         else{
//             rear--;
//         }
//         return ans;
//     }

//     int getfront(){
//         if( isEmpty() ){
//             return -1;
//         }
//         return arr[front];
//     }

//     int getrear(){
//         if( isEmpty() ){
//             return -1;
//         }
//         return arr[rear];
//     }

//     bool isEmpty(){
//         if(front == -1 ){
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     Deque d(5);
//     d.push_rear(3); d.push_rear(4); d.push_rear(5);
//     d.push_rear(6);
//     cout<< d.getfront() <<endl;
//     cout<< d.getrear() <<endl;
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Circular Queue using Linked List)//////////////////////////////
//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int val;
//    Node* next;
//    Node (int data) {
//        this->val = data;
//        this->next = NULL;
//    }
//};
//
//class MyCircularQueue {
//    Node* front;
//    Node* rear;
//    int size;
//public:
//    MyCircularQueue(int k) {
//        this->front = NULL;
//        this->rear = NULL;
//        if (this->rear != NULL) {
//            this->rear->next = this->rear;
//        }
//        this->size = k;
//    }
//    
//    bool enQueue(int value) {
//        Node* ele = new Node(value);
//        if (this->rear == NULL && this->front == NULL) {
//            this->front = ele;
//            this->rear = ele;
//            this->rear->next = this->front;
//            this->size--;
//        }
//        else if (this->size == 0) {
//            return false;
//        }
//        else {
//            this->rear->next = ele;
//            ele->next = this->front;
//            this->rear = ele;
//            this->size--;
//        }
//        return true;
//    }
//    
//    bool deQueue() {
//        if (this->front == NULL && this->rear == NULL) {
//            return false;
//        }
//        if (this->rear->next == this->rear) {
//            this->front = NULL;
//            this->rear = NULL;
//            this->size++;
//            return true;
//        } else {
//            Node* temp = this->front;
//            this->front = this->front->next;
//            temp->next = NULL;
//            this->rear->next = this->front;
//            this->size++;
//            return true;
//        }
//
//    }
//    
//    int Front() {
//        if (this->front == NULL && this->rear == NULL) {
//            return -1;
//        } else {
//            return this->front->val;
//        }
//    }
//    
//    int Rear() {
//        if (this->rear == NULL && this->front == NULL) {
//            return -1;
//        } else {
//            return this->rear->val;
//        }
//    }
//    
//    bool isEmpty() {
//        return front == NULL;
//    }
//    
//    bool isFull() {
//        return this->size == 0;
//    }
//};
//
////// Solution 2# /////////////////////////////////////////////////////////////////////////////////////////////////////
//
//class MyCircularQueue2 {
//
//private:
//    class Node {
//    public:
//        int data;
//        Node* next;
//        Node(int x) {
//            this->data = x;
//            this->next = NULL;
//        }
//    };
//    int si;
//    int max_si;
//    Node* root;
//    Node* rear;
//
//public:
//
//    MyCircularQueue2(int k) {
//        si = 0;
//        max_si = k;
//        root = NULL;
//        rear = NULL;
//    }
//
//    bool enQueue(int value) {
//        if (si == max_si) {
//            return false;
//        }
//        si++;
//        Node* newNode = new Node(value);
//        if (!root) {
//            root = newNode;
//            rear = newNode;
//            rear->next = root;
//        }
//        else {
//            rear->next = newNode;
//            rear = newNode;
//            rear->next = root;
//        }
//        return true;
//    }
//
//    bool deQueue() {
//        if (si == 0) {
//            return false;
//        }
//        si--;
//        if (root == rear) {
//            rear = NULL;
//            root = NULL;
//        }
//        else {
//            Node* newRoot = root->next;
//            root = newRoot;
//            rear->next = root;
//        }
//        return true;
//
//    }
//
//    int Front() {
//        if (!root) {
//            return -1;
//        }
//        return root->data;
//    }
//
//    int Rear() {
//        if (!root) {
//            return -1;
//        }
//        return rear->data;
//    }
//
//    bool isEmpty() {
//        return root == NULL;
//    }
//
//    bool isFull() {
//        return si == max_si;
//    }
//};
//
//int main() {
//
//}