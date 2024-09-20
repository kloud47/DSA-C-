///////////(Array is sorted or not)/////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
  //Base case
  if(size == 0 || size==1 )
  {
    return true;
  }

  if(arr[0] > arr[1]){
    return false;
  }

  else{
    return isSorted(arr + 1, size-1);
  }
}

int main()
{
  int arr[5] = {2,4,6,8,9};
  int size = 5;

  cout<<isSorted(arr, size);


  return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////
////////(Get Sum)/////////////////////
/*#include<iostream>
using namespace std;

int getSum(int *arr, int n)
{
  if(n==0){
    return 0;
  }
  if(n == 1){
    return arr[0];
  }

  int remainpart = getSum(arr+1, n-1);
  int sum = arr[0] + remainpart;

  return sum;
}

int main()
{
  int arr[5] = {2,4,8,9,5};
  int size = 5;

  int sum = getSum(arr, size);

  cout<<"Sum is "<< sum <<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
////////////////(Linear Search)//////////////////////////////////////////////
/*#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int n, int key)
{
  //Base case
  if(n == 0){
    return 0;
  }

  if(arr[0] == key){
    return 1;
  }

  return LinearSearch(arr+1, n-1, key);
}

int main()
{
  int arr[5] = {3,5,1,2,6};
  int size = 5;
  int key = 7;
  bool ans = LinearSearch(arr, size, key);

  if(ans){
    cout<<"Key is present."<<endl;
  }
  else{
    throw "key not present";
  }

  return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////
///////(Binary Search)///////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void print(int arr[], int s, int e)
{
  for(int i = 0; i<=e; i++){
    cout<< arr[i] <<" ";
  }cout<<endl;
}

bool binarySearch(int arr[], int s, int e, int key)
{
  int mid = s + (e-s)/2;

  cout<<"Search space is ";
  print(arr,s,e);

  cout<<endl<<"mid is "<<arr[mid]<<endl;
  //Base case
  //Element not found
  if(s>e){
    return false;
  }
  //Element found
  if(arr[mid] == key){
    return true;
  }

  if(arr[mid] < key){
    return binarySearch(arr, mid+1, e, key);
  }
  else{
    return binarySearch(arr, s, mid-1, key);
  }
}

int main()
{
  int arr[6] = {2,4,6,10,14,16};
  int size = 6;
  int key = 10;

  bool ans = binarySearch(arr, 0, 5, key);

  if(ans){
    cout<<"Key present."<<endl;
  }
  else{
    cout<<"Key absent."<<endl;
  }

  return 0;
}*/
