/////////(Next samller element)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0 ; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr{2, 1, 4, 3};

    vector<int> ans = nextSmallerElement(arr, 4);

    for(int i:ans){
        cout<< i <<" ";
    }
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////(Largest Rectangular area in a Histogram)///////////////////////////////////////////////////////-
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int>  s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        while( s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

void largestRectangularArea(vector<int> &heights)
{
    int n = heights.size();
    
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int l = 0;
    int b = 0;
    int area = INT_MIN;
    for(int i = 0; i < n; i++){
        l = heights[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    cout<< area;;
}

int main()
{
    vector<int> histo{2,1,5,6,1,2};

    largestRectangularArea(histo);


    return 0;
}