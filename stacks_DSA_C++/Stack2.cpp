///////////(Reverse a String using Stack)////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str = "Hello";

    stack<char> s;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while( !s.empty() ){
        char var = s.top();
        ans.push_back(var);//Function of string:
        s.pop();
    }

    cout<< ans <<endl;

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////(Delete Middle element from stack)/////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int cnt, int size){
    if(cnt == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    //Recursive call:
    solve(s, cnt+1, size);

    s.push(num);
}

void deletemid(stack<int> &s, int n){
    int cnt = 0;
    solve(s, cnt, n);
}

int main()
{
    stack<int> s;
    s.push(1); s.push(2); s.push(3); s.push(4);
    deletemid(s, s.size());
    s.pop();
    cout<< s.top() <<endl;
    cout<<s.size();

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////(valid Paranthesis)/////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
using namespace std;

bool isValidParanthesis(string str){
    stack<char> s;
    for(int i = 0; i<str.length(); i++){
        char ch = str[i];

        //If opening bracket stack push:
        if(ch == '{' || ch == '[' || ch == '('){
            s.push(ch);
        }
        //If closing bracket stack check and pop:
        else{
            if( !s.empty() ){
                char top = s.top();
                if( ch == '}' && top == '{' ||
                    ch == ')' && top == '(' ||
                    ch == ']' && top == '[' ){
                    s.pop();
                }
                else{/**/
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str = "({[]})";
    cout<< (isValidParanthesis(str) ? "Valid" : "Invalid");

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////(Insert Element at the end of the Stack)///////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int n){
    //Base case:
    if( !s.empty() ){
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, n);
    s.push(num);
}

stack<int> pushBottom(stack<int> &mystack, int x){
    solve(mystack, x);
    return mystack;
}

int main()
{
    stack<int> s;
    s.push(1); s.push(3); s.push(4);
    cout<<"Size before -> "<< s.size() <<endl;

    s = pushBottom(s, 5);
    cout<<"Size after -> "<< s.size() <<endl;

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////(Reverse a Stack using Recursion)//////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

void pushBottom(stack<int> &s, int n){
    if( s.empty() ){
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();

    pushBottom(s, n);

    s.push(num);
}

void reverse(stack<int> &s){
    if( s.empty() ){
        return;
    }

    int num = s.top();
    s.pop();

    reverse(s);

    pushBottom(s, num);
}

int main()
{
    stack<int> st;
    st.push(1); st.push(2); st.push(3); st.push(4);
    reverse(st);

    while( !st.empty() ){
        cout<< st.top() <<" ";
        st.pop();
    }

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////(Sort a Stack)(Sorted in descending order)/////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

void sorted(stack<int> &st, int n){
    if( st.empty() || (!st.empty() && n > st.top() )){
        st.push(n);
        return;
    }

    int num = st.top();
    st.pop();

    sorted(st, n);

    st.push(num);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sorted(s, num);
}

int main()
{
    stack<int> st;
    st.push(3); st.push(1); st.push(5); st.push(2); st.push(4);
    sortStack(st);

    while( !st.empty() ){
        cout<< st.top() <<" ";
        st.pop();
    }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Redundant Paranthesis)///////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string s){
    stack<char> st;
    for( int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while( st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                        st.pop();
                    }
                }

                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string str = "(a + b)";

    cout<< findRedundantBrackets(str);
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Minimum cost to make a string Valid)////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

int findMinCost(string str){
    if(str.length() % 2 != 0){
        return -1;
    }

    
    stack<int> st;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        
        if( ch == '{'){
            st.push(ch);
        }
        else{//here ch = '}':
            if( !st.empty() && st.top() == '{' ){
                st.pop();
            }
            else{
                st.push(ch);//push the '}' if no '{' present:
            }
        }
    }
    // stack contains invalid operation:
    int a = 0;
    int b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;

    return ans;
}

int main()
{
    string str = "{{}}}}}}";

    cout<< "The min cost is : "<< findMinCost(str);
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Implement Stack using queue)//////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;

class mystack{
public:
    queue<int> s;
    queue<int> q;

    mystack(){
    }

    void push(int x){
        if(s.empty()){
            s.push(x);
            return;
        }

        int num = s.front();
        s.pop();
        q.push(num);

        push(x);

        int n = q.front();
        s.push(n);
        q.pop();
    }

    int top(){
        return s.front();
    }

    int pop(){
        int n = s.front();
        s.pop();
        return n;
    }

    void print(){
        while(!s.empty()){
            cout<< s.front() <<" ";
            s.pop();
        }cout<<endl;
    }
};

int main()
{
    mystack st;
    st.push(3); st.push(4); st.push(6); st.push(2); st.push(9);

    // st.print();
    cout<< st.top() <<endl;
    st.pop();
    st.print();

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
using namespace std;

void sorted(stack<int> &s, int n){
    if(s.empty() || (!s.empty() && n > s.top())){
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();

    sorted(s, n);

    s.push(num);


}

void sortStack(stack<int> &s){
    if(!!s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sorted(s, num);
}

int main(){
    stack<int> s;
    s.push(3); s.push(0); s.push(4); s.push(7);

    sortStack(s);

    while(!s.empty()){
        cout<< s.top() <<" ";
        s.pop();
    }
}*/