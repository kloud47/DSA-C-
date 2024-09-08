//////////////(N stacks in an Array)/////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

class Nstack
{
public:
    int *arr;
    int *top;
    int *next;

    int n, s;//n = number of stacks, s = size of array:

    int freespot;


    Nstack(int N, int S){
        n = N;
        s = S;
        arr = new int(s);
        top = new int(n);
        next = new int(s);

        //top initialize:
        memset(top, -1, n);

        //next initialize:
        for(int i = 0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        //freespot initialize:
        freespot = 0;
    }

    void push(int x, int m){
        //Check for stack over flow:
        if(freespot == -1){
            cout<< "No free spot available.";
        }

        //Find index:
        int index = freespot;

        //Update freespot:
        freespot = next[index];

        //Insert element into the array:
        arr[index] = x;

        //Update next:
        next[index] = top[m -1];

        //Update top:
        top[m-1] = index;
    }

    int pop(int m){
        if(top[m-1] = -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    Nstack   arr(3, 9);

    arr.push(10, 1);
    arr.push(11, 1);

    cout<< arr.top[0] << endl;
    cout<< arr.arr[0] << endl;
    cout<< arr.arr[1] << endl;

    return 0;
}