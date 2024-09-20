///////////////////////////////////////////////////////////////////////////////////////
///////////(Permutations of a Array)/////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)//ans by refrence
{
  //Base class
  if(index >= nums.size()){
    ans.push_back(nums);
    return;
  }

  for(int j = index; j < nums.size(); j++){
    swap(nums[index], nums[j]);
    solve(nums, ans, index+1);
    //Backtracking
    swap(nums[index], nums[j]);
  }
}

vector<vector<int>> permutation(vector<int> &nums)//nums by refrence
{
  vector<vector<int>> ans;
  int index = 0;
  solve(nums, ans, index);
  return ans;
}

int main()
{
  vector<int> nums{1,2,3};

  vector<vector<int>> ans = permutation(nums);

  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<< ans[i][j] <<" ";
    }cout<<endl;
  }

  return 0;
}*/
///////////////(Permutation of string)///////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

void solve(string str, int i, vector<string> &ans)
{
  //Base case
  if(i >= str.length()){
    ans.push_back(str);
    return;
  }

  for(int j = i; j < str.length(); j++){
    swap(str[i], str[j]);
    solve(str, i+1, ans);
    //Backtracking
    swap(str[i], str[j]);
  }
}

vector<string> permutations(string &str)
{
  vector<string> ans;
  int index = 0;
  solve(str, index, ans);
  return ans;
}

int main()
{
  string str = "abc";

  vector<string> ans = permutations(str);

  for(string i : ans){
    cout<<i<<" ";
  }
}*/
