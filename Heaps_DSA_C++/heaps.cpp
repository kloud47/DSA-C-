//(Implementation of Max Heap)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

class  heap// Max heap implementation:
{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i<size; i++){
            cout << arr[i] <<" ";
        }cout<<endl;
    }

    void deletefromheap(){
        if(size == 0){
            cout << "Nothing to delete." << endl;
        }

        arr[1] = arr[size];
        size--; // deleting the last element:

        int i = 1;
        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i + 1;

            if(leftindex < size && arr[i] < arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }
    }
};

int main()
{
    heap h1;
    h1.insert(1); h1.insert(2); h1.insert(3); h1.insert(4); h1.insert(6);
    h1.deletefromheap(); h1.deletefromheap();

    h1.print();

    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////(Heapify algorithm)////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;


void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 40, 53, 55, 56, 50};
    int n = end(arr) - begin(arr);
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout<<"Printing the heapifyed array now."<<endl;
    for(int i = 1; i<n; i++){
        cout<< arr[i] <<" ";
    }


    system("pause");
    return 0;
}*/
///(Implementation of Min Heap)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

class minheap
{
public:
    int arr[100];
    int size;
    
    minheap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout<< arr[i] <<" ";
        }cout<<endl;
    }
};

int main()
{
    minheap h;
    h.insert(60); h.insert(57); h.insert(80); h.insert(30); h.insert(34);
    h.print();

    system("pause");
    return 0;
}