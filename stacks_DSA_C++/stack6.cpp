//////(Get minimum value)(Approach - 1)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

int main()
{
    return 0;
}*/
////////(Approach - 2)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
using namespace std;

class Specialstack
{
    stack<int> s;
    int mini;
public:

    void push(int data){
        if( s.empty() ){
            s.push(data);
            mini = data;
        }
        else{
            if( data < mini ){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){//It returns the poped element and updates the mini:
        if( s.empty() ){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if( curr > mini ){
            return curr;
        }
        else{
            int prevmini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevmini;
        }
    }

    int top(){
        if( s.empty() ){
            return -1;
        }
        
        int curr = s.top();
        if( curr < mini ){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){
        if( s.empty() ){
            return -1;
        }

        return mini;
    }

};

int main()
{
    Specialstack s;
    s.push(2); s.push(3); s.push(5); s.push(1); s.push(4);
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.pop() <<endl;
    cout<< s.top() <<endl;
    cout<< s.getMin() <<endl;

    return 0;
}