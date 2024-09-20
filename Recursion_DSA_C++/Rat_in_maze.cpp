#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
  bool issafe(int x, int y, int n, vector<vector<bool>> visited, vector<vector<bool>> maze){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1){
      return true;
    }
    else{
      return false;
    }
  }
  void solve(vector<vector<bool>> &maze, int n, vector<string> &ans,
              int x, int y, vector<vector<bool>> visited, string path)
  {///Base case // we have reached the stopping coordinate:
    if(x == n-1 && y == n-1){
      ans.push_back(path);
      return;
    }

    visited[x][y] = 1;
    //4 choices - D,L,R,U

    //Down
    if(issafe(x+1, y, n, visited, maze)){
      path.push_back('D');
      solve(maze, n, ans, x+1, y, visited, path);
      path.pop_back();
    }
    //Left
    if(issafe(x, y-1, n, visited, maze)){
      path.push_back('L');
      solve(maze, n, ans, x, y-1, visited, path);
      path.pop_back();
    }
    //Right
    if(issafe(x, y+1, n, visited, maze)){
      path.push_back('R');
      solve(maze, n, ans, x , y+1, visited, path);
      path.pop_back();
    }
    //Up
    if(issafe(x-1, y, n, visited, maze)){
      path.push_back('U');
      solve(maze, n, ans, x-1, y, visited, path);
      path.pop_back();
    }

    visited[x][y] = 0;
  }
public:
  vector<string> findpath(vector<vector<bool>> &maze, int n){
    vector<string> ans;

    if(maze[0][0] == 0){
      return ans;
    }

    //Initialize visited with zero/////////////////
    /*for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        visited[i][j] = 0;
      }
    }*/
    vector<vector<bool>> visited(n, vector<bool> (n, 0));

    string path = "";
    solve( maze, n, ans, 0, 0, visited, path);
    //sort(ans.begin(), ans.end());//For lexicographically

    return ans;
  }
};

int main()
{
  vector<vector<bool>> maze{{1,0,0,0},
                           {1,1,0,1},
                           {1,1,0,0},
                           {0,1,1,1}};
  Solution sol;

  vector<string> ans = sol.findpath(maze, 4);

  for(string i : ans){
    cout<< i <<" ";
  }

  return 0;
}
