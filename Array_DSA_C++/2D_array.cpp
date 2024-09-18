////////////////////////////////////////////////////////////////////////////////
////////(2D-Array [row][column])/////////////////////////
/*#include<iostream>
using namespace std;
/////////(linear seach 2D)////////////
bool ispresent(int arr[][4], int target, int row, int col){
  for(int i = 0; i<row; i++){
    for(int j = 0; j<col; j++){
      if(arr[i][j]==target){
        return 1;
      }
    }
  }
  return 0;
}

int main(){
  //int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
  //int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};
  int arr[3][4];
  //Taking input:Row wise;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<4; j++){
      cin>>arr[i][j];
    }
  }

  //Taking input:Column wise;
  /*for(int j = 0; j<4; j++){
    for(int i = 0; i<3; i++){
      cin>>arr[i][j];
    }
  }*/
  //Giving output:
  /*for(int i = 0; i<3; i++){
    for(int j = 0; j<4; j++){
      cout<<arr[i][j]<<" ";
    }cout<<endl;
  }

  cout<<"Enter the element to search ";
  int target;
  cin>>target;

  if(ispresent(arr, target, 3, 4)){
    cout<<"Target present "<<endl;
  }
  else{
    cout<<"Target not present "<<endl;
  }
}*/
////////////////////////////////////////////////////////////////////////////////
////////(Row-Wise sum)//////////////////////////////////////
/*#include<iostream>
using namespace std;

int rowwisesum(int arr[][4], int row){
  int i = row-1;
  int sum = 0;
  for(int j = 0; j<4; j++){
    sum = sum + arr[i][j];
  }
  return sum;
}

int largestrowsum(int arr[][4], int row){
  int maxrow = -1;
  int rowindex = 0;
  for(int i = 1; i<=row; i++){
    int rowsum = rowwisesum(arr, i);
    if(rowsum > maxrow){
      maxrow = rowsum;
      rowindex = i;
    }
  }
  return rowindex;
}

int main(){
  int arr[3][4] = {1,22,3,30,5,20,7,8,9,10,11,12};

  for(int i = 0; i<3; i++){
    for(int j = 0; j<4; j++){
      cout<<arr[i][j]<<" ";
    }cout<<endl;
  }

  cout<<"Sum of row 1: "<<rowwisesum(arr, 1)<<endl;
  cout<<"Sum of row 2: "<<rowwisesum(arr, 2)<<endl;
  cout<<"Sum of row 3: "<<rowwisesum(arr, 3)<<endl;

  cout<<"Row with the largest sum is "<<largestrowsum(arr, 3);

}*/
////////////////////////////////////////////////////////////////////////////////
//////////(Print like a wave)//////////////////////////////////////////
/*#include<iostream>
using namespace std;

void printwave(int arr[][3]){
  for(int col = 0; col<3; col++){
    if(col%2==0){
      for(int j=0; j<3; j++){
        cout<<arr[j][col]<<" ";
      }
    }
    else{
      for(int j=2; j>=0; j--){
        cout<<arr[j][col]<<" ";      }
    }
  }
}

int main(){
  int arr[3][3] = {1,2,3,4,5,6,7,8,9};

  cout<<"2D array is-> "<<endl;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      cout<<arr[i][j]<<" ";
    }cout<<endl;
  }

  cout<<"\n"<<endl;
  printwave(arr);
}*/
///////////////////////////////////////////////////////////////////////////////
/////////////(Spiral print)////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

void spiralprint(vector<vector<int>> matrix)
{
  vector<int> ans;

  int row = matrix.size();
  int col = matrix[0].size();

  int count = 0;
  int total = row*col;

  int startingrow = 0;
  int startingcol = 0;
  int endingrow = row-1;
  int endingcol = col-1;

  while(count < total){
    //Starting row:
    for(int i = startingcol; count < total && i<=endingcol; i++){
        ans.push_back(matrix[startingrow][i]);
        count++;
    }startingrow++;

    //Ending column:
    for(int i = startingrow; count < total && i<=endingrow; i++){
      ans.push_back(matrix[i][endingcol]);
      count++;
    }endingcol--;

    //Ending row:
    for(int i = endingcol; count < total && i>=startingcol; i--){
      ans.push_back(matrix[endingrow][i]);
      count++;
    }endingrow--;

    //Starting column:
    for(int i = endingrow; count < total && i>=startingrow; i--){
      ans.push_back(matrix[i][startingcol]);
      count++;
    }startingcol++;
  }
  for(int i:ans){
    cout<<i<<" ";
  }cout<<endl;
}

int main(){
  vector<vector<int>> vec{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

  cout<<"2D-array is "<<endl;
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      cout<<vec[i][j]<<" ";
    }cout<<endl;
  }

  spiralprint(vec);
}*/
///////////////////////////////////////////////////////////////////////////////
///////////(Rotate image)////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////(Binary search in 2D array)//////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

bool searchmatrix(vector<vector<int>> vec, int target)
{
  int row = vec.size();
  int col = vec[0].size();

  int start = 0;
  int end = row*col - 1;
  int mid = start + (end-start)/2;

  while(start<=end){
    int element = vec[mid/col][mid%col];
    if(element == target){
      return 1;
    }
    else if(element>target){
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
    mid = start + (end-start)/2;
  }
  return 0;
}


int main(){
  vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
  cout<<"2D-Array is "<<endl;
  for(int i = 0; i<matrix.size(); i++){
    for(int j = 0; j<matrix[0].size(); j++){
      cout<<matrix[i][j]<<" ";
    }cout<<endl;
  }

  cout<<"Target is ";
  int target;
  cin>>target;

  cout<<"If target is present or not "<<searchmatrix(matrix, target);
}*/
///////////////////////////////////////////////////////////////////////////////
////////////(Search a 2D matrix)///////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

bool search(vector<vector<int>> vec, int target)
{
  int row = vec.size();
  int col = vec[0].size();

  int rowindex = 0;
  int colindex = col-1;

  while(rowindex<row && colindex>=0){
    int element = vec[rowindex][colindex];
    if(element == target){
      return 1;
    }
    if(element > target){
      colindex--;
    }
    else{
      rowindex++;
    }
  }
  return 0;
}

int main()
{
  vector<vector<int>> matrix{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
  cout<<"2D array is-> "<<endl;
  for(int i = 0; i<matrix.size(); i++){
    for(int j = 0; j<matrix[0].size(); j++){
      cout<<matrix[i][j]<<" ";
    }cout<<endl;
  }

  cout<<"Enter the target ";
  int n;
  cin>>n;
  cout<<"if target is present or not "<<search(matrix, n);
}*/
///////////////////////////////////////////////////////////////////////////////
