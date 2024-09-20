//////(Recursion using String)//////////////////////////////////////////////////////
//////////(Reversing a string)/////////////////////////////////////
/*#include<iostream>
using namespace std;

//Void type Recursion//

void reverse(string &s, int i, int j)
{
  //Base case
  if(i>j){
    return;//used as a break statement
  }

  swap(s[i++], s[j--]);

  //Recursive call
  reverse(s, i, j);
}

int main()
{
  string word = "abcde";

  reverse(word, 0, word.length()-1);

  cout<< word;

  return 0;
}*/
////////(using only i single pointer)/

/////////////////////////////////////////////////////////////////////////////////
////////(Check Palindrome )/////////////////////////////////
/*#include<iostream>
using namespace std;

bool CheckPalindrome(string str, int s, int e)
{
  //Base case
  if(s>e){
    return true;
  }
  if(str[s++] != str[e--]){
    return false;
  }

  return CheckPalindrome(str, s, e);
}

int main()
{
  string word = "aabbcaa";

  bool ans = CheckPalindrome(word, 0, word.length()-1);
  if(ans){
    cout<<"is Palindrome.";
  }
  else{
    cout<<"Not a Palindrome.";
  }

  return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int power(int n, int p)
{
  if(p==0){
    return 1;
  }
  if(p==1){
    return n;
  }

  int num = power(n, p/2);

  if(p%2 == 0){
    return num*num;
  }
  else{
    return n*num*num;
  }
}

int main()
{
  cout<<"Number and power "<<endl;
  int n, p;
  cin>>n>>p;

  int ans = power(n,p);

  cout<< "Answer is "<< ans <<endl;

  return 0;
}*/
////////////////////////////////////////////////////////////////////////////////
///////(Bubble sort using Recursion)////////////////////////////
/*#include<iostream>
using namespace std;

void print(int arr[], int n){
  for(int i = 0; i<n; i++){
    cout<< arr[i] <<" ";
  }cout<<endl;
}

void sortArray(int arr[], int n)
{
  //Base case
  if(n==0 || n==1){
    return;
  }

  for(int i = 0; i<n-1; i++){//n-1 due to taking i+1
    if(arr[i] < arr[i+1]){
      swap(arr[i], arr[i+1]);
    }
  }

  sortArray(arr, n-1);
}

int main()
{
  int arr[5] = {2,5,1,6,9};

  sortArray(arr, 5);

  print(arr, 5);
}*/
/////////////////////////////////////////////////////////////////////////////////
