//(Recursion)(Rat in a maze problem)//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> maze){
    if((x>=0 && x<n) && (y>=0 && y<n) && maze[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y, 
            vector<vector<int>> visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //Down: (x+1, y)
    if(isSafe(x+1, y, n, visited, maze)){
        path.push_back('D');
        solve(maze, n, ans, x+1, y, visited, path);
        path.pop_back();
    }

    //Left: (x, y-1)
    if(isSafe(x, y-1, n, visited, maze)){
        path.push_back('L');
        solve(maze, n, ans, x, y-1, visited, path);
        path.pop_back();
    }

    //Right: (x, y+1)
    if(isSafe(x, y+1, n, visited, maze)){
        path.push_back('R');
        solve(maze, n, ans, x, y+1, visited, path);
        path.pop_back();
    }

    //Up: (x-1, y)
    if(isSafe(x-1, y, n, visited, maze)){
        path.push_back('U');
        solve(maze, n, ans, x-1, y, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> findpath(vector<vector<int>> &maze, int n){
    vector<string> ans;

    if(maze[0][0] == 0){
        return ans;
    }

    int srcX = 0, srcY = 0;

    vector<vector<int>> visited = maze;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    string path = "";

    solve(maze, n, ans, srcX, srcY, visited, path);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<vector<int>> m{{1,1,0,0},
                          {0,1,1,0},
                          {0,1,1,0},
                          {0,1,1,1}};
    
    vector<string> ans = findpath(m, 4);

    for(string i:ans){
        cout<< i << " ";
    }

    return 0;
}
//(Back-tracking)(Rat in a maze)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
