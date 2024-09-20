//////////(Sum of n numbers)///////////////////
/*#include<iostream>
using namespace std;

int  sumtill(int n){
  if(n <= 0){return 0;}//Termination Base case

  return sumtill(n-1) + n;
}

int main()
{
  int n;
  cin>>n;
  cout<< sumtill(n);

  return 0;
}*/
////////////////(Factorial)//////////////////////////////////////////
/*#include<iostream>
using namespace std;

int factorial(int n)
{
  if(n <= 1){
    return 1;
  }

  return factorial(n-1)*n;
}

int main()
{
  int n; cout<<"Enter the number: ";
  cin>>n;

  cout<< factorial(n);
}*/
/////////(Printing 1 to n)//////////////////////
//////(Tail Recursion)///////////
/*#include<iostream>
using namespace std;

void print(int n)
{
  if(n == 0){
    cout<< n ;
    return;
  }

  cout<< n <<" ";
  print(n-1);
}

int main()
{
  int n;
  cin>>n;

  print(n);
}*/
///////(Head recursion)/////////
/*#include<iostream>
using namespace std;

void print(int n)
{
  if(n == 0){
    cout<< n <<" ";
    return;
  }
  print(n-1);
  cout<< n <<" ";
}

int main()
{
  int n;
  cin>>n;

  print(n);
}*/
/////////////(Tree Recursion)///////////////////
/*#include<iostream>
using namespace std;

void printtree(int n)
{
  if(n <= 0){
    return;
  }

  printtree(n-1);
  printtree(n-2);
  cout<< n <<" ";
}

int main()
{
  int n; cin>>n;

  printtree(n);
}*/
////////(Nested recursion)//////////////////
/*#include<iostream>
using namespace std;

int nested(int n)
{
  if(n > 100)
  return n-10;

  return nested(nested(n + 11));
}

int main(){
  int n; cin>>n;

  cout<< " " <<nested(n);

  return 0;
}*/
//////(Fibonacci Series using recursion)////////////////
/*#include<iostream>
using namespace std;

int fibo(int n)
{
  if(n == 0 || n == 1){
    return n;
  }

  return fibo(n-1) + fibo(n-2);
}

int main()
{
  int n; cin>>n;
  for(int i = 0; i <= n; i++){
    cout<< fibo(i) <<" ";
  }
}*/
///////////(Recursion to print a number)/////////////
/*#include<iostream>
using namespace std;

void print(string str, int i)
{
  if(i >= str.length()){
    return;
  }
  cout<< str[i] <<" ";
  print(str, i+1);
}

int main()
{
  string a = "abcde";

  print(a, 0);
}*/
