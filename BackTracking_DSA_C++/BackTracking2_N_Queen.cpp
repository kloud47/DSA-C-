///(N-Queen)//////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> board, int n)
{
    int x = row, y = col;
    //row check:
    while( y>=0 ){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    //no need for column wise check:

    //Diagonal check (upper left):
    x = row, y = col;
    while(y>=0 && x>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--; y--;
    }

    //Diagonal check (lower left):
    x = row, y = col;
    while(y>=0 && x<n){
        if(board[x][y] == 1){
            return false;
        }
        x++; y--;
    }

    return true;
}

void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int n)
{
    if(col == n){
        addSolution(board, ans, n);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(board, ans, col+1, n);
            //Back_Track
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int> (n, 0));
    vector<vector<int>> ans;

    solve(board, ans, 0, n);

    return ans;
}

int main()
{
    int n; cin>>n;
    vector<vector<int>> ans = nQueens(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< ans[i][j] <<" ";
        }cout<<endl;
    }

    return 0;
}