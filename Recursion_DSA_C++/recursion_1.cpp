////////////////////////////////////////////////////////////////////////////////
////When function calls itself it is called (Recursion)///////////////
/*#include<iostream>
using namespace std;

int factorial(int n)
{
  if(n==0){//Base case:
    return 1;
  }

  int smallerProblem = factorial(n-1);
  int biggerProblem = n*smallerProblem;

  return biggerProblem;
}

int main()
{
  int n;
  cin>>n;

  int ans = factorial(n);

  cout<< ans <<endl;


  return 0;
}*/
////////////////////////////////////////////////////////////////////////////////
///////////////////(Power of 2^n)/////////////////////////////
/*#include<iostream>
using namespace std;

int power(int n)
{
  //Base case
  if(n==0){
    return 1;
  }
  //Recursive relation
  int smallerproblem = power(n-1);
  int biggerproblem = 2*smallerproblem;

  return biggerproblem;
}

int main()
{
  int n;
  cin>>n;
  int ans = power(n);
  cout<< ans <<endl;

  return 0;
}*/
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int power(int n)
{
  //basecase
  if(n==0)
    return 1;

  //Recursive relation
  return 2*power(n-1);
}

int main()
{
  int n;
  cin>>n;
  int ans = power(n);

  cout<< ans <<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
////(Counting)////////////////////////////////////
/*#include<iostream>
using namespace std;

void counting(int n)
{
  if(n==0){
    return;//stops the recursion
  }

  counting(n-1);
  cout<<n<<" ";

}

int main()
{
  int n;
  cin>>n;
  counting(n);
}*/
////////////////////////////////////////////////////////////////////////////////
//////(Destination)/////////////////////////
/*#include<iostream>
using namespace std;

void reachhome(int src, int dest)
{
  cout<<"Source "<<src<<" Destination "<<dest<<endl;
  if(src == dest){//Base case:
    cout<<"\n{pahuch gaya}\n"<<endl;
    return;
  }

  src++;//Processing:
  reachhome(src, dest);//Recursive relation:
  cout<<"Source "<<src<<" Destination "<<dest<<endl;
}

int main()
{
  int dest = 10, src = 1;
  cout<<endl;
  reachhome(src, dest);
}*/
////////////////////////////////////////////////////////////////////////////////
/////////(Fibonacci Series using Recursion)////////////////////////////
/*#include<iostream>
using namespace std;

int fibonacci(int n)
{
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }

  int ans = fibonacci(n-1) + fibonacci(n-2);
  return ans;
}

int main()
{
  int n;
  cin>>n;

  fibonacci(n);
}*/
////////////////////////////////////////////////////////////////////////////////
///////////(Climb Stairs)/////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int climb(int n)
{
  if(n<0){
    return 0;
  }
  if(n==0){
    return 1;
  }

  return climb(n-1) + climb(n-2);
}

int main()
{
  cout<<"Number of Stairs is ";
  int stairs;
  cin>>stairs;

  cout<<"\nNumber of ways of climbing stairs "<<climb(stairs);

}*/
/////////////////////////////////////////////////////////////////////////////////////////////
///////////(Say Digit)/////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int saydigit(int n, string arr[])
{
  //Base case
  if(n==0)
    return 1;

  //Processing
  int digit = n%10;
  n = n/10;

  //Recursive relation
  saydigit(n, arr);
  cout<< arr[digit] << " ";
}

int main()
{
  int n;
  cin >> n;

  string arr[10] = {"Zero", "First", "Second", "Third"
                  , "four", "Five", "Six", "Seven", "Eight", "Nine"};

  cout<<endl;
  saydigit(n, arr);
  cout<<endl<<endl;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
