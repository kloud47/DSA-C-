///////////////////////(Inclusion - Exclusion is used)////////////////////////////////////////////////////////////////////////////////
///////////////(Find the Power set)////////////////////////////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> & ans){
  //Base case
  if(index >= nums.size()){
    ans.push_back(output);
    return;
  }

  //Exclude
  solve(nums, output, index+1, ans);

  //Include
  int element = nums[index];
  output.push_back(element);
  solve(nums, output, index+1, ans);
}

vector<vector<int>> subsets(vector<int> &nums){
  vector<vector<int>> ans;
  vector<int> output;
    int index = 0;
  solve(nums, output, index, ans);
  return ans;
}

int main()
{
  vector<int> nums{1,2,3,4,5};

  vector<vector<int>> ans = subsets(nums);

  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<< ans[i][j] << " ";
    }cout<<endl;
  }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////(Find the subsequences)//////////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans){
  //Base basecase
  if(index >= str.length()){
    ans.push_back(output);
    return;
  }
  //Exclude
  solve(str, output, index+1, ans);
  //Include
  char element = str[index];
  output.push_back(element);
  solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
  vector<string> ans;
  string output = "";
  int index = 0;
  solve(str, output, index, ans);
  return ans;
}

int main()
{
  string chara = "abc";

  vector<string> ans = subsequences(chara);

  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout<< ans[i][j] << " ";
    }cout<<endl;
  }
}*/
////////////////////////////////////////////////////////////////////////////////////////
////////////(Subsequences)///////////////////////
#include<iostream>
using namespace std;

class Subsequences{
  string str;
public:
  Subsequences(string str){
    this->str = str;
  }

  void solve(str, string output, int i)
  {
    if(i == str.size()){
      cout<< output <<" ";
      return;
    }
    //Inclusion
    solve(str, output+str[i], i+1);
    //Exclusion
    solve(str, output+str[i], i+1);

    return;
  }

  vector<string> subsets()
  {
    vector<string> ans;
    solve(str, " ", 0);
    return ans;
  }

};

int main()
{
  Subsequences sub("abc");


}
