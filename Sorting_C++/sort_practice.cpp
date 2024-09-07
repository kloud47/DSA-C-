///////(Selection sort)/////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void SelectionSort(int *arr, int n)
{
  for(int i = 0; i<n; i++){
    int minindex = i;
    for(int j = i+1; j<n; j++){
      if(arr[j] < arr[minindex]){
        minindex = j;
      }
    }
    swap(arr[i], arr[minindex]);
  }

  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }cout<<endl;
}

int main()
{
  int list[5] = {3,5,6,1,9};
  int n = end(list) - begin(list);

  SelectionSort(list, n);
}*/
//////////////////(Bubble Sort)//////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
  for(int i = 1; i<n; i++){//Rounds (n-1)
    bool swapped = false;

    for(int j = 0; j<(n-i); j++){//swappings
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped == false){
      break;
    }
  }
  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }
}

int main()
{
  int list[5] = {3,5,2,6,1};
  int n = end(list)-begin(list);

  BubbleSort(list, n);
}*/
//////////(Insertion Sort)///////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
  for(int i = 1; i<(n-1); i++){
    int temp = arr[i];
    int j = i-1;
    for(; j>=0; j--){
      if(arr[j] > arr[j+1] ){
        arr[j+1] = arr[j];
      }
      else{
        break;
      }
    }
    arr[j+1] = temp;
  }

  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }
}

int main()
{
  int arr[6] = {10,4,5,9,7,11};
  int n = end(arr)-begin(arr);

  insertionSort(arr, n);

  return 0;
}*/
/*#include<iostream>
using namespace std;

void InsertSort(int *arr, int n)
{
  for(int i = 1; i<n; i++){
    int j = i-1;
    for(; j>=0; j--){
      if(arr[j+1] < arr[j]){
        swap(arr[j+1], arr[j]);
      }
    }
  }

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

int main()
{
  int arr[5] = {3,5,1,0,7};

  InsertSort(arr, 5);
}*/
//////////////(Insertion Sort using recursion)/////////////////////////////////////////
/*#include<iostream>
using namespace std;

void print(int *arr, int n)
{
  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }
}

void insertSort(int *arr, int s, int n)
{
  //Base case
  if( s == n-1 ){
    return;
  }

  int j = s-1;
  for(; j>=0; j--){
    if(arr[j+1] < arr[j]){
      swap(arr[j+1], arr[j]);
    }
  }
  insertSort(arr, s+1, n);
}

int main()
{
  int arr[6] = {10,4,5,9,7,11};
  int n = end(arr)-begin(arr);

  insertSort(arr, 1, n);
  print(arr, n);

  return 0;
}*/
///////////////////(Another using recursion)/////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void print(int *arr, int n)
{
  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }
}

void insertSort(int *arr, int s, int n)
{
  //Base case
  if( s == n-1 ){
    return;
  }

  int j = s-1;
  while(j>=0 && arr[j] > arr[j+1]){
    swap(arr[j+1], arr[j]);
    j--;
  }
  insertSort(arr, s+1, n);
}

int main()
{
  int arr[6] = {10,4,5,9,7,11};
  int n = end(arr)-begin(arr);

  insertSort(arr, 1, n);
  print(arr, n);

  return 0;
}*/
/*#include<iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
  int pivot = arr[s];

  int count = 0;
  for(int i = s+1; i<e; i++){
    if(arr[i] <= pivot){
      count++;
    }
  }
  //Changing pivot position
  int pivotindex = s + count;
  swap(arr[pivotindex], arr[s]);
  int i = s, j = e;
  while(i < pivotindex && j > pivotindex){
    while(pivot >= arr[i]){
      i++;
    }
    while(pivot < arr[j]){
      j--;
    }
    if(i < pivotindex && j > pivotindex){
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotindex;
}

void quicksort(int *arr, int s, int e)
{
  //Base case
  if(s >= e){
    return;
  }

  int p = partition(arr, s, e);

  //left part ko sort karna
  quicksort(arr, s, p-1);

  //Right part ko sort karna
  quicksort(arr, p+1, e);
}

int main()
{
  int arr[6] = {2,5,1,6,0,9};
  int n = end(arr) - begin(arr);

  quicksort(arr, 0, n);

  for(int i = 0; i<n; i++){
    cout<< arr[i] << " ";
  }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

void Merge(int *arr, int s, int e){
  int mid = (s+e)/2;

  int len1 = mid - s + 1;
  int len2 = e - mid;

  int *first = new int[len1];
  int *second = new int[len2];

  int minindex = s;
  for(int i = 0; i<len1; i++){
      
  }
}

void MergeSort(int *arr, int s, int e){
  if(s >= e){
    return;
  }

  int mid = (s+e)/2;
  MergeSort(arr, s, mid-1);
  MergeSort(arr, mid+1, e);

  Merge(arr, s, e);
}

int main()
{
  int arr[15] = {2,5,1,6,9,3,13,11,18,35,20,23,36,80,78};
  int size = 15;

  mergeSort(arr, 0, size-1);
  print(arr, size);

  return 0;
}