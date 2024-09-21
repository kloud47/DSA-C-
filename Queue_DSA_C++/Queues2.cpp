/////(Queue Reversal)(Approach-1 using Stack)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> q)
{
    stack<int> s;

    while( !q.empty() ){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while( !s.empty() ){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    return q;
}

int main()
{
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    q = reverse(q);
    cout<< q.front() <<" "<< q.back() <<endl;
}*/
/////////(Approach-2)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int> &q){
    if( q.empty() ){
        return;
    }

    int num = q.front();
    q.pop();

    reverse(q);

    q.push(num);
}

int main()
{
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    reverse(q);
    
    while( !q.empty() ){
        cout<< q.front() <<" ";
        q.pop();
    }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Negative integer in window of size k)///////////////////////////////////////////////
/*#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> firstNegativeNum(int A[], int N, int K){
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i<K; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i = K; i<N; i++){
        if( !dq.empty() && i-dq.front() >= K){//Removal:
            dq.pop_front();
        }

        if(A[i] < 0){//Addition:
            dq.push_back(i);
        }

        if(dq.size() > 0){//Answer store:
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    int arr[6] = {-8, 2, 3, -6, 10};
    vector<int> ans;
    ans = firstNegativeNum(arr, 6, 2);

    for( int i:ans ){
        cout<< i <<" ";
    }

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////(Reverse first k elements of K)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reverse_K(queue<int> q, int k){
    stack<int> s;

    for(int i = 0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while( !s.empty() ){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size()-k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5);
    q = reverse_K(q, 3);
    while( !q.empty() ){
        cout<< q.front() <<" ";
        q.pop();
    }


    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(First non-repeating character in a stream)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

string FirstNonRepeating(string S)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for(int i = 0; i<S.length(); i++){
        char ch = S[i];

        count[ch]++;

        q.push(ch);

        while( !q.empty() ){
            if(count[q.front()] > 1){
                //Repeating character:
                q.pop();
            }
            else{
                //Non-repeating character:
                ans.push_back(q.front());
                break;
            }
        }
        //if only repeating character are present:
        if( q.empty() ){
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string str = "aabcb";

    str = FirstNonRepeating(str);
    cout<<str;

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//(Circular Tour)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n){
    int balance =  0;
    int deficit = 0;
    int start = 0;

    for(int i = 0; i < n; i++){
        balance = balance + p[i].petrol - p[i].distance;
        if( balance < 0 ){
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if( deficit + balance >= 0 ){
        return start;
    }
    else{
        return -1;
    }
}

int main()
{
    petrolPump *p = new petrolPump[4];
    p[0].petrol = 6; p[0].distance = 5;
    p[1].petrol = 7; p[1].distance = 6;
    p[2].petrol = 4; p[2].distance = 7;
    p[3].petrol = 10; p[3].distance = 8;    
    p[4].petrol = 6; p[4].distance = 6;
    p[5].petrol = 5; p[5].distance = 4;

    cout << tour(p, 6); 

    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Interleave the first half of the queue with second half)////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<queue>
using namespace std;

void Interleave(queue<int> &q){
    queue<int> p;
    int n = q.size();

    int i = 0;
    while( i < n/2 ){
        int val = q.front();
        q.pop();
        p.push(val);
        i++;
    }

    while( !p.empty() ){
        int val = q.front();
        q.pop();
        q.push(val);
        val = p.front();
        p.pop();
        q.push(val);
    }
}

int main()
{
    queue<int> q;
    q.push(1); q.push(2); q.push(3); q.push(4); q.push(5); q.push(6);

    Interleave(q);
    while( !q.empty() ){
        int num = q.front();
        q.pop();
        cout << num <<" ";
    }

    return 0;
}
