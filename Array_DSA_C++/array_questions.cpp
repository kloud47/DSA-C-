///////////////////////////////////////////////////////////////////////////////
/////////(Reverse an array after a given index)///////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v, int index){
  int s = index + 1, e = v.size()-1;
  while(s<=e){
    swap(v[s], v[e]);
    s++;
    e--;
  }
  return v;
}

int print(vector<int> v){
  for(int i:v){
    cout<<i<<" ";
  }cout<<endl;
}

int main(){
  vector<int> v{5,2,3};
  v.push_back(6);
  v.push_back(1);

  cout<<"Before reversing the vector "<<endl;
  print(v);

  cout<<"Enter the index "<<endl;
  int in;
  cin>>in;

  vector<int> ans = reverse(v, in);

  cout<<"After reversing the vector "<<endl;
  print(ans);
}*/
////////////////////////////////////////////////////////////////////////////////
////////(Merging 2 sorted arrays)//////////////////////////
/*#include<iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]){
  int i = 0, j = 0, k = 0;

  while(i<n && j<m){
    if(arr1[i] < arr2[j]){
      arr3[k++] = arr1[i++];
    }
    else{
      arr3[k++] = arr2[j++];
    }
  }

  //Copy first array remaining elements
  while(i<n){
    arr3[k++] = arr1[i++];
  }

  //Copy second array remaining elements
  while(j<m){
    arr3[k++] = arr2[j++];
  }
}

void print(int arr[], int n){
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}

int main(){
  int a[5] = {1,3,5,7,9};
  int b[4] = {2,4,6,8};

  int c[9] = {0};

  merge(a, 5, b, 4, c);

  print(c, 9);

  return 0;
}*/
///////////////////////////////////////////////////////////////////////////////
//////////////(Merge without making a 3rd array)/////////////////////
/*#include<iostream>
using namespace std;

int main(){
  int arr1[6] = {1,2,3,0,0,0};
  int arr2[3] = {2,5,6};
}*/
////////////////////////////////////////////////////////////////////////////////
////////(Move the zeros)///////////////////////////////////////////
/*#include<iostream>
using namespace std;

void movezero(int arr[], int n){
  int i = 0;
  for(int j = 0; j<n; j++){
    if(arr[j]!=0){
      swap(arr[i++], arr[j]);
    }
  }
}

void print(int arr[], int n){
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}

int main(){
  int arr[6] = {0,1,0,3,0,6};

  movezero(arr, 6);

  print(arr, 6);
}*/
////////////////////////////////////////////////////////////////////////////////
////////(Move array elements forward)/////////////////
///(((((((Approach 1)))))))using array
/*#include<iostream>
using namespace std;

void move(int arr[], int n){
  int i = 0;
  int j = 1;
  while(j<n){
    swap(arr[i++], arr[j++]);
  }
}

int main(){
  int list[5] = {1,4,9,10,20};

  for(int i = 0; i<5; i++){
    cout<<list[i]<<" ";
  }cout<<endl;

  cout<<"Enter how much forward to move the elements ";
  int n;
  cin>>n;

  int i = 0;
  while(i<n){
    move(list, 5);
    i++;
  }

  for(int i = 0; i<5; i++){
    cout<<list[i]<<" ";
  }cout<<endl;
}*/
///////////////////////////////////////////////////////////////////////////////
/////////////(Move array elements forward)//////////////////////////////
//(((((((((((((approach 2)))))))))))))using vector
/*#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector<int> l, int k){
  vector<int> temp(l.size());
  for(int i = 0; i<l.size(); i++){
    temp[(i+k)%l.size()] = l[i];
  }
  l = temp;

  return l;
}

int print(vector<int> l){
  for(int i:l){
    cout<<i<<" ";
  }
}

int main(){
  vector<int> list{1,4,9,10,20};

  cout<<"Array is "<<endl;
  print(list);

  cout<<"\nRotated by ";
  int n;
  cin>>n;

  print(rotate(list, n));
}*/
///////////////////////////////////////////////////////////////////////////////
///////////////(Check if the array is rotated and sorted)///////
///in all rotated and sorted array only one pair is where num[i-1]>num[i];
/*#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> v){
  int n = v.size();
  int count = 0;
  for(int i = 1; i<n; i++){
    if(v[i-1]>v[i]){
      count++;
    }
  }
  if(v[n-1]>v[0]){
    count++;
  }

  return count<=1;
}

int main(){
  vector<int> list{9,10,20,1,9};

  if(check(list)){
    cout<<"Sorted and rotated array "<<endl;
  }

  else{
    cout<<"Not sorted or ratated array "<<endl;
  }
}*/
///////////////////////////////////////////////////////////////////////////////
////////////(Sum of two array)//////////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

vector<int> sum(vector<int> l1, vector<int> l2){
  int n = l1.size();
  int m = l2.size();
  int j = m-1;
  for(int i = n-1; i>=(m-1)&&j>=0; i--){
    int sum = l1[i]+l2[j];
    if(sum<10){
      l1[i] = sum;
    }
    if(sum>=10){
      l1[i] = sum%10;
      l1[i-1] = l1[i-1] + 1;
    }
    j--;
  }

  return l1;
}

void print(vector<int> l){
  for(int i:l){
    cout<<i<<" ";
  }
}

int main(){
  vector<int> list1{1,2};
  vector<int> list2{9,9};

  print(sum(list1,list2));
}*/
//////////////////////////////////////////////////////////////////
