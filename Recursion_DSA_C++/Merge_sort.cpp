///////////////////////////////////////////////////////////////////////////////////
//////(Merge Sort)///////////////////////////////////////////////////////////
//////////It is the fastest sorting algorithm
/*#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
  int mid = s + (e-s)/2;

  int len1 = mid - s + 1;
  int len2 = e - mid;

  int *first = new int[len1];
  int *second = new int[len2];

  //Copy values
  int minArrayindex = s;
  for(int i = 0; i<len1; i++){
    first[i] = arr[minArrayindex++];
  }

  minArrayindex = mid+1;
  for(int i = 0; i<len2; i++){
    second[i] = arr[minArrayindex++];
  }

  //Merge 2 Sorted arrays
  int index1 = 0;
  int index2 = 0;
  minArrayindex = s;

  while(index1 < len1 && index2 < len2){
    if(first[index1] < second[index2]){
      arr[minArrayindex++] = first[index1++];
    }
    else{
      arr[minArrayindex++] = second[index2++];
    }
  }

  while(index1 < len1){
    arr[minArrayindex++] = first[index1++];
  }
  while(index2 < len2){
    arr[minArrayindex++] = second[index2++];
  }

  delete []first;
  delete []second;
}

void mergeSort(int *arr, int s, int e)
{
  //Base case
  if(s >= e){
    return;
  }
  int mid = s + (e-s)/2;
  //left part sorting
  mergeSort(arr, s, mid);

  //Right part sorting
  mergeSort(arr, mid+1, e);

  merge(arr, s, e);
}

void print(int arr[], int n){
  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }
}

int main()
{
  int arr[15] = {2,5,1,6,9,3,13,11,18,35,20,23,36,80,78};
  int size = 15;

  mergeSort(arr, 0, size-1);
  print(arr, size);

  return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////
//Inversion count problem//////////////////////////////////////
