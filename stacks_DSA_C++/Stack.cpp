//////( Stack )//////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;


int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.pop();

    cout<<"Printing the Top element. -> "<< s.top() <<endl;

    if(s.empty()){
        cout<<"Stack is empty."<<endl;
    }
    else{
        cout<<"Stack is not empty."<<endl;
    }

    cout<<"Size of stack is -> "<< s.size();

    return 0;
}*/
/////////(My own class of -> Stack)(Implementation using array)////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class Stack
{
    //Properties:
public:
    int *arr;
    int top;
    int size;

    //Behaviour:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack overflow."<<endl;
        }
    }

    int pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack underflow."<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack empty.";
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Stack st(5);

    st.push(1); st.push(2); st.push(3);

    cout<< st.peek() <<endl; st.pop();
    cout<< st.peek() <<endl;

    if(st.isEmpty()){
        cout<<"Stack is empty."<<endl;
    }
    else{
        cout<<"Stack is not empty."<<endl;
    }

    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////(Two Stack - implementation using 1 array)////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class TwoStack
{
public:
    //Properties:
    int top1; int top2;
    int *arr;
    int size;

    TwoStack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    //Push operation in stack 1:
    int push1(int n){
        if(top2 - top1 > 1){
            //at least 1 space is empty
            top1++;
            arr[top1] = n;
        }
        else{
            cout<<"Stack Overflow."<<endl;
        }
    }

    //Puah operation in stack 2:
    int push2(int n){
        if(top2 - top1 > 1){
            // at least 1 space is empty:
            top2--;
            arr[top2] = n;
        }
        else{
            cout<<"Stack Overflow."<<endl;
        }
    }

    //Pop from Stack 1 and return poped element:
    int pop1(){
        if(top1 >= 0){
            top1--;
            return arr[top1+1];
        }
        else{
            return -1;
        }
    }

    //Pop from Stack 2 and return poped element:
    int pop2(){
        if(top2 < size){
            top2++;
            return arr[top2-1];
        }
        else{
            return -1;
        }
    }
};

int main()
{
    TwoStack s1_s2(6);

    s1_s2.push1(1); s1_s2.push1(2); s1_s2.push1(3);
    s1_s2.push2(-1); s1_s2.push2(-2); s1_s2.push2(-3);

    cout<<"1st element of s1 stack. -> "<< s1_s2.pop1() <<endl;
    cout<<"1st element of s2 stack. -> "<< s1_s2.pop2() <<endl;

    return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////(Stack implementation using -> Linked List)/////////////////////////////////////////////////////

//////(Swapping two different stacks)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> st1;
    stack<int> st2;

    st1.push(1); st1.push(2); st1.push(3);

    st2.push(4); st2.push(5); st2.push(6);

    st1.swap(st2);

    while( !st2.empty() ){
        cout<< st2.top() <<" ";
        st2.pop();
    }
}
