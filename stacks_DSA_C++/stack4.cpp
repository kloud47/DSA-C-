/////////(Celebrity Problem)////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> M, int a, int b){
    if( M[a][b] == 1 ){
        return true;
    }
    else{
        return false;
    }
}

int celebrity(vector<vector<int>> & M, int n)
{
    stack<int> s;
    //1) Push all elements to stack:
    for(int i = 0; i < n; i++){
        s.push(i);
    }

    //2) Pick out the celebrity:
    while(s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if( knows(M, a, b) ){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    // Verify if it is a celebrity:
    int candidate = s.top();

    bool rowCheck = false;

    for(int i  = 0; i < n; i++){
        if( M[candidate][i] == 1 ){
            rowCheck = true;
            break;
        }
    }

    bool columnCheck = false;

    for(int i = 0; i < n; i++){
        if( M[i][candidate] == 0 && i != n/2 ){
            columnCheck = true;
            break;
        }
    }

    if( rowCheck == false && columnCheck == false ){
        return candidate;
    }
    else{
        return -1;
    }
}

int main()
{
    vector<vector<int>> v{{0, 1, 0}, 
                          {0, 0, 0}, 
                          {0, 1, 0}};

    cout<< celebrity(v, 3);
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////(Max rectange in Binary matrix with all 1's)/////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

vector<int> nextSmaller(int *arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr ){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(int *arr, int  n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i<n; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr ){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangularArea(int* arr, int n){

    vector<int> next(n);
    next = nextSmaller(arr, n);

    vector<int> prev(n);
    prev = prevSmaller(arr, n);

    int area = INT_MIN;
    for(int i = 0; i<n; i++){
        int l = heights[i];

        if( next[i] == -1 ){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int MaxArea(vector<vector<int>> M, int n, int m){
    //Compute area of the first row:
    int area = largestRectangularArea(M[0], m);

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            //Row update by adding previous row's:
            if(M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
            //Entire row is updated now:
            area = max(area, largestRectangularArea(M[i], m));
        }
        return area;
    }
}

int main()
{
    vector<vector<int>> vec{{0, 1, 1, 0},
                            {1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {1, 1, 0, 0}};

    cout<< MaxArea(vec, 4, 4);
}