// #include<iostream>
// using namespace std;
//
// int main(){
//   int n;
//   cin>>n;
//
//   int i = 1;
//
//   while(i<=n){
//
//     int j = 1;
//     while(j<=n){
//       cout<<"* ";
//       j = j + 1;
//     }
//     cout<<endl;
//   i = i + 1;
//   }
//
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n;
//   cin>>n;
//
//   int i = 1;
//
//   while(i<=n){
//
//     int j = 1;
//     while(j<=n){
//       cout<<i;
//       j = j + 1;
//     }
//     cout<<endl;
//   i = i + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n;
//   cin>>n;
//
//   int i = 1;
//
//   while(i<=n){
//
//     int j = n;
//     while(j>0){
//       cout<<j;
//       j = j - 1;
//     }
//     cout<<endl;
//   i = i + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
 // #include<iostream>
 // using namespace std;
 //
 // int main(){
 //   int col;
 //   cin>>col;
 //
 //   int i = 1;
 //
 //   while(i<=col){
 //     int j = 1;
 //
 //     while(j<=i){
 //       cout<<"*";
 //       j = j + 1;
 //     }
 //     cout<<endl;
 //     i = i + 1;
 //   }
 // }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int col;
//   cin>>col;
//
//   int i = 1;
//
//   while(i<=col){
//     int j = 1;
//
//     while(j<=i){
//       cout<<i;
//       j = j + 1;
//     }
//     cout<<endl;
//     i = i + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int row,i,col;
//   cin>>row;
//   i = 1;
//   while(i<=row){
//     col = 1;
//     int k = i;
//     while(col<=i){
//       cout<<k;
//       col = col + 1;
//       k = k + 1;
//     }
//     cout<<endl;
//     i = i + 1;
//   }
// }
////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n;
//   cin>>n;
//
//   int i = 1;
//   while(i <= n){
//
//     int j = 1;
//     while(j <= i){
//       cout<<i-j+1;
//       j = j + 1;
//     }
//     cout<<endl;
//     i = i + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row;
//   cin>>n;
//   n = n + 65 -1;
//   row = 65;
//
//   while(row<=n){
//     int col = 1;
//     int j = 65;
//
//     while(j<=n){
//       char var = row + col - 1;
//       cout<<var;
//       j = j + 1;
//       col = col + 1;
//     }
//     cout<<endl;
//     row = row + 1;
//   }
// }
////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n;
//   cin>>n;
//
//   int row = 1;
//   while(row<=n){
//     int col = 1;
//     char start = 65 + n - row;
//     while(col<=row){
//       cout<<start;
//       start = start + 1;
//       col = col + 1;
//     }
//     cout<<endl;
//     row = row + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row;
//   cin>>n;
//
//   row = 1;
//   while(row<=n){
//     int space = n - row;
//     while(space){
//       cout<<" ";
//       space = space - 1;
//     }
//
//   int col = 1;
//   while(col<=row){
//     cout<<"*";
//     col = col + 1;
//   }
//   cout<<endl;
//   row = row + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//
//   int n,row;
//   cin>>n;
//
//   row = 1;
//   while(row<=n){
//     int space = row -1;
//     while(space){
//       cout<<' ';
//       space = space - 1;
//     }
//
//     int col = n - row + 1;
//     while(col){
//       cout<<"*";
//       col = col - 1;
//     }
//     cout<<endl;
//     row = row + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row;
//   cin>>n;
//   row = 1;
//
//   cout<<"......[Pascal's Triangles]......"<<endl;
//
//   while(row<=n){
//     int space = n - row;
//     while(space){
//       cout<<' ';
//       space = space - 1;
//     }
//
//     int col = 1;
//     while(col <= row){
//       cout<<col;
//       col = col + 1;
//     }
//
//     int col2 = row - 1;
//     while(col2){
//       cout<<col2;
//       col2 = col2 - 1;
//     }
//     cout<<endl;
//     row = row + 1;
//
//   }
//
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row;
//   cin>>n;
//
//   row = 1;
//   while(row <= n){
//
//     int i = 1;
//     int k = n - row + 1;
//     while(k){
//       cout<<i;
//       i = i + 1;
//       k = k - 1;
//     }

//     int star = (row - 1)*2;
//     while(star){
//       cout<<'*';
//       star = star - 1;
//     }
//
//     int j = n - row + 1;
//     int q = n - row + 1;
//     while(q){
//       cout<<j;
//       j = j - 1;
//       q = q - 1;
//     }
//     cout<<endl;
//     row = row + 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,count,row;
//   cin>>n;
//
//   count = 1;
//   row = 1;
//   while(row<=n){
//     int j = 1;
//     while(j<=n){
//       cout<<count<<" ";
//       count += 1;
//       j += 1;
//     }
//     cout<<endl;
//     row += 1;
//   }
// }
////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row,count;
//   cin>>n;
//
//   row = 1;
//   count = 1;
//   while(row<=n){
//     int j = 1;
//     while(j <= row){
//       cout<<count<<' ';
//       count += 1;
//       j += 1;
//     }
//     cout<<endl;
//     row += 1;
//   }
// }
////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,row,count;
//   cin>>n;
//
//   row = 1;
//   count = 1;
//   while(row <= n){
//     int j  = 1;
//     int k = n - row + 1;
//     while(j <= k){
//       cout<<count<<" ";
//       count += 1;
//       j += 1;
//     }
//     cout<<endl;
//     row += 1;
//   }
// }
///////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// using namespace std;
//
// int main(){
//   int n,count,row;
//   cin>>n;
//
//   row = 1;
//   count =1;
//   while(row<=n){
//     int j = 1;
//     int k = n - row + 1;
//     while(j<=k){
//       cout<<count<<' ';
//       count += 1;
//       j += 1;
//     }
//     int space = 1;
//     while(space<=(row-1)){
//       cout<<'*'<<' ';
//       space += 1;
//     }
//     cout<<endl;
//     row += 1;
//   }
// }
////////////////////////////////////////////////////////////////////////////////
/*#include<iostream>
using namespace std;

int main(){

  int n,i,j;
  cin>>n;
  i = 1;
  while(i<=n){
    int j = 0;
    while(j<i&&j!=0){
      cout<<' ';
      j++;
    }

    int star = n - i + 1;
    while(star){
      cout<<"*";
      star--;
    }
    cout<<endl;
    i++;
  }
}*/
/////////////////////////////////////////
#include<iostream>
using namespace std;

int main()
{
  int n; cin>>n;
  char cnt = 'A';
  for(int i = 0; i<n; i++){

    for(int j = 0; j <= i; j++){

      cout<< cnt <<" ";
      cnt++;

    }cout<<endl;
  }
}