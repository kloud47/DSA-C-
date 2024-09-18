/*#include<iostream>
#include<climits>
using namespace std;

/*void array(int arr[], int size){
  cout<< "Printing the array"<<endl;
  for(int i = 0; i < size; i++){
    cout<<arr[i]<<" ";
  }
}*/
/*int getmax(int num[], int n){
  int maxi = INT_MIN;
  for(int i = 0; i<n; i++){
    maxi = max(maxi, num[i]);
  //   if(num[i]>max){
  //     maxi = num[i];

  }
  return maxi;
}

int getmin(int num[], int n){
  int minm = INT_MAX;
  for(int i = 0; i<n; i++){
    minm = min(minm, num[i]);
    // if(num[i]<min){
    //   minm = num[i];

  }
  return minm;
}


int main(){
//  int var[3]={1,2,3};
//  cout<<"Value at zero index."<<var[0]<<endl;
  /*int array[10] = {4,5,6};
  int n = 10;
  for(int i = 0; i<n; i++){
    cout<<array[i]<<" ";
  }*/
  /*int kk[15];
  int ok[10] = {2,35,7};
  int ko[15] = {5,6,90,47};
  //array(ok, 3);
  array(ko, 15);
  cout<<"\n"<<sizeof(double)<<endl;*/
  /*int size;
  cin>>size;
  int num[100];
  for(int i = 0; i<size; i++){
    cin>>num[i];
  }

  cout<<"Maximum value is."<<getmax(num, size)<<endl;
  cout<<"Minimum value is."<<getmin(num, size)<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
#include<climits>
using namespace std;

int getmax(int num[], int n){
  int max = INT_MIN;
  for(int i = 0; i<n; i++){
    if(num[i]>max){
      max = num[i];
    }
  }
  return max;
}

int getmin(int num[], int n){
  int min = INT_MAX;
  for(int i = 0; i<n; i++){
    if(num[i]<min){
      min = num[i];
    }
  }
  return min;
}

int main(){
  int size;
  cin>>size;

  int num[100];
  //taking input in array
  for(int i = 0; i<size; i++){
    cin>>num[i];
  }

  cout<<"maximunm value is "<<getmax(num, size)<<endl;//num[100]100 int is not put in argument
  cout<<"minimum value is "<<getmin(num, size);
}*/
///////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int main(){
  int size;
  cin>>size;

  int arr[size];

  for(int i = 0; i<size; i++){
    cin>>arr[i];
  }

}*/
/////////////////////////////////////////////////////////////////////////////////////////////
////////////(Linear Search)//////////////////////////////

/*#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
  for(int i=0; i<size; i++){
    if(arr[i]==key){
      return 1;
    }
  }
  return 0;
}

int main(){
  int arrr[10] = {1,2,3,4,5,6,7,8,9,10};

  cout<<"Enter the element to search for is "<<endl;
  int key;
  cin>>key;

  bool ans = search(arrr, 10, key);
  if(ans){
    cout<<"Element is present"<<endl;
  }
  else{
    cout<<"Element is absent"<<endl;
  }
}*/
//////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void reverse(int arr[], int n){
  int start = 0;
  int end = n-1;

  while(start<=end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void printarray(int arr[], int size){
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){

  int arr[6] = {1,5,7,-4,2,8};
  int brr[5] = {5,7,-4,8,2};

  reverse(arr, 6);
  reverse(brr, 5);

  printarray(arr, 6);
  printarray(brr, 5);
}*/
////////////////////////////////////////////////////////////////////////////////
//Swaping alternate elements
/*#include<iostream>
using namespace std;

void rev_alt(int arr[], int n){
  int start = 0;
  int end = start+1;

  while(end<n){
    swap(arr[start], arr[end]);
    start+=2;
  }
}

void printarray(int arr[], int size){
  for(int i = 0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int arr[6] = {1,2,3,4,5,6};

  rev_alt(arr, 6);
  printarray(arr, 6);
}*/
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void revaltarr(int arr[], int n){
  for(int i=0; i<n; i+=2){
    if(i+1<n){
      swap(arr[i], arr[i+1]);
    }
  }
}

void printarray(int arr[], int size){
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){

  int even[6] = {1,2,3,4,5,6};
  int odd[5] = {1,2,3,4,5};

  revaltarr(even, 6);
  revaltarr(odd, 5);
  printarray(even, 6);
  printarray(odd, 5);
}*/
////////////////////////////////////////////////////////////////////////////////
////////(XOR use Find unique element)////////////////////////////////
/*#include<iostream>
using namespace std;

int main(){
  int arr[5] = {1,2,3,2,1};

  int ans = 0;
  for(int i=0; i<5; i++){
    ans = ans^arr[i];
  }

  cout<<"Unique element is : "<<ans;
}*/
////////////////////////////////////////////////////////////////////////////////
/////////(Find duplicate in an array)///////////////////////////
/*#include<iostream>
#include<vector>
using namespace std;

int findduplicate(vector<int> &arr){
  int ans=0;
  for(int i = 0; i<arr.size(); i++){
    ans = ans^arr[i];
  }

  for(int i = 0; i<arr.size(); i++){
    ans= ans^i;
  }

  return ans;
}

int main(){
  int array[6] = {1,2,2,1,1,3};

  cout<<"duplicate no. is ";
  int x = findduplicate(array);
  cout<<x;
}*/
///////////////////////////////////////////////////////////////////////////////
//////////(Initialize entire array with single value)//////////////////
/*#include<iostream>
#include<array>
using namespace std;

void Array(int arr[], int n)
{
  for(int i = 0; i<10; i++){
    arr[i] = n;
  }cout<<endl;
}

int main(){
  int arr[10];
  cout<<"Initializing value should be ";
  int n;
  cin>>n;
  cout<<"\nThe Array is "<<endl;
  Array(arr, n);
  for(int i = 0; i<10; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}*/
///////////////////////////////////////////////////////////////////////////////
///////////(Intersection of array)///////////////////////////
/*#include<iostream>
using namespace std;

int intersection(int arr1[], int arr2[])
{
  int temp = -1;
  for(int i = 0; i<5; i++){
    for(int j = 0; j<5; j++){
      if(arr1[i]==arr2[j]){
        temp = arr1[i];
      }
    }
  }
  return temp;
}

int main()
{
  int list1[5] = {1,3,4,2,5};
  int list2[5] = {6,2,3,8,9};

  cout<<"Intersecting element is "<<intersection(list1, list2);
}*/
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int main()
{
  cout<<"No. of elements in 1st array ";
  int n1;
  cin>>n1;
  int arr1[n1];

  cout<<"No. of elements in 2nd array ";
  int n2;
  cin>>n2;
  int arr2[n2];

  cout<<"Elements of first array "<<endl;
  for(int i = 0; i<n1; i++){
    cin>>arr1[i];
  }cout<<endl;

  cout<<"Elements of Second array "<<endl;
  for(int i = 0; i<n2; i++){
    cin>>arr2[i];
  }cout<<endl;

  cout<<"Intersection of array "<<endl;
  for(int i = 0; i<n1; i++){
    for(int j = 0; j<n2; j++){
      if(arr1[i]==arr2[j]){
        cout<<arr1[i]<<" ";
      }
    }
  }
}*/
////////////////////////////////////////////////////////////////////////////////
//////////(Pair Sum)///////(Time complexity O(n^2))/////////////////////////////////
/*#include<iostream>
using namespace std;

int sumpair(int arr[], int n)
{
  int sum = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      sum += arr[i] + arr[j];
    }
  }
  return sum;
}

int main()
{
  int array[5] = {1,2,3,1,4};

  int sum = sumpair(array, 5);
  cout<<"Sum of the pairs is "<<sum<<endl;
}*/

/////////(Time complexity O(n))/////////////
/*#include<iostream>
using namespace std;

int sumpair(int arr[], int n)
{
  int sum = 0;
  for(int i = 0; i<n; i++){
    sum += arr[i]*((2*n)-1);
  }
  return sum;
}

int main()
{
  int arr[5] = {1,2,3,1,4};

  cout<<"Sum of all the pair is "<<sumpair(arr, 5);
}*/
////////////////////////////////////////////////////////////////////////////////
/////////////(Segregate '0' and '1')//////////////////////////
/*#include<iostream>
using namespace std;

void segregate(int arr[], int n)
{
  int e = n-1;
  for(int i = n-1; i>=0; i--){
    if(arr[i]!=0){
      swap(arr[i], arr[e--]);
    }
  }
}

int main()
{
  int arr[6] = {1,0,1,1,0,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Initially array is "<<endl;
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;

  segregate(arr, n);
  cout<<"After segregating "<<endl;
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
