//////(Selection sort)////////////////////////////
/*#include<iostream>
using namespace std;

void sortascend(int arr[], int n){
  for(int i = 0; i<(n-1); i++){
    int minindex = i;

    for(int j = i+1; j<n; j++){
      if(arr[j]<arr[minindex]){
        minindex = j;
      }
    }
    swap(arr[minindex], arr[i]);
  }
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<' ';
  }
}

int main(){
  int list[5] = {5,3,6,2,7};

  sortascend(list, 5);
}*/
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

void sortdescend(int arr[], int n){

  for(int i = 0; i<(n-1); i++){
    int minindex = i;

    for(int j = i+1; j<n; j++){
      if(arr[j]>arr[minindex]){
        minindex = j;
      }
    }
    swap(arr[minindex], arr[i]);
  }
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<' ';
  }
}

int main(){
  int list[5] = {2,5,6,3,1};

  sortdescend(list, 5);
}*/
////////////////////////////////////////////////////////////////////////////////
//////////(Bubble Sort)////////////////////////
/*#include<iostream>
using namespace std;

int Bubblesort(int arr[], int n){
  for(int i = 1; i<n; i++){

    bool swapped = false;
    for(int j = 0; j<(n-i); j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped==false){
      break;
    }
  }

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<' ';
  }
}


int main(){
  int list[7] = {10,4,5,9,7,2,11};

  Bubblesort(list, 7);
}*/
////////////////////////////////////////////////////////////////////////////////
//////////////(Insertion Sort)//////////////////////////
/*#include<iostream>
using namespace std;

int  insertsort(int arr[], int n){

  for(int i = 1; i<n; i++){
    int temp = arr[i];
    int j = i-1;
    for(; j>=0; j--){
      if(arr[j] > temp){
        arr[j+1] = arr[j];
      }
        else{
        break;
      }
    }
    arr[j+1] = temp;
  }

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  int list[6] = {10,4,5,9,7,10};

  insertsort(list, 6);
}*/
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

int Bubblesort(int arr[], int n){
  for(int i = 1; i<n; i++){

    bool swapped = false;
    for(int j = 0; j<(n-i); j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped==false){
      break;
    }
  }

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<' ';
  }
}


int main(){
  int list[8] = {100, 60, 0, 23, 2, 1, 78, 999};

  Bubblesort(list, 8);
}
