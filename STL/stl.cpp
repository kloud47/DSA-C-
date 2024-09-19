//////////////(Array stl)///////////////////////////////////////////////////////
/*#include<iostream>
#include<array>
using namespace std;

int main(){
  array<int,4> a = {1,2,3,4};

  int size = a.size();

  for(int i = 0; i<size; i++){
    cout<<a[i]<<endl;
  }

  cout<<"Element at 2nd Index-> "<<a.at(2)<<endl;//Prints element at 2nd index
  cout<<"Empty or not-> "<<a.empty()<<endl;//Array is empty or not

  cout<<"First Element-> "<<a.front()<<endl;//1st element of stl array
  cout<<"Last Element-> "<<a.back()<<endl;//last element of stl array
}*/
///////////////////////////////////////////////////////////////////////////////
//////////(Vector stl)/////////////////////////////////
///dyanmic array)))))))))))
/*#include<iostream>
using namespace std;
#include<vector>

int main(){
  cout<<"\"Vector\""<<endl;

  vector<int> v;

  vector<int> a(5,1);

  vector<int> last(a);//copied a vector in last vector
  for(int i:last){
    cout<<i<<" ";
  }cout<<endl;

  vector<int> b{1,2,3,4,5};
  for(int i:b){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(2);

  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(3);

  cout<<"Capacity-> "<<v.capacity()<<endl;//capacity means space asigned for elements

  v.push_back(4);

  cout<<"Capacity-> "<<v.capacity()<<endl;//capacity doubled
  cout<<"Size-> "<<v.size()<<endl;//no. of elements inside vector
  cout<<"Element at index 2 is-> "<<v.at(2)<<endl;

  cout<<"Front-> "<<v.front()<<endl;
  cout<<"Back-> "<<v.back()<<endl;

  cout<<"Before pop"<<endl;
  for(int i:v){
    cout<<i<<" ";
  }
  cout<<endl;

  v.pop_back();

  cout<<"After pop"<<endl;
  for(int i:v){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Before clear size-> "<<v.size()<<endl;
  v.clear();
  cout<<"After clear size-> "<<v.size()<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
//////////(Deque stl)///////////////////////////
/////dynamic array))))))))))
/*#include<iostream>
#include<deque>
using namespace std;

int main(){
  deque<int> d;
  d.push_back(1);
  d.push_front(2);

  /*for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

  d.pop_back();
  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

  d.pop_front();
  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;*/

  /*cout<<"Print first index element-> "<<d.at(1)<<endl;
  cout<<"Front-> "<<d.front()<<endl;
  cout<<"Back-> "<<d.back()<<endl;

  cout<<"Empty or not "<<d.empty()<<endl;

  cout<<"Before erase size "<<d.size()<<endl;
  d.clear();
  cout<<"After erase size "<<d.size()<<endl;

  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_front(0);

  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

  d.erase(d.begin(), d.begin()+2);

  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
//////////////(list stl)///////////////////////////////
/*#include<iostream>
#include<list>
using namespace std;

int main(){
  list<int> l{1,2};

  l.push_front(0);
  l.push_front(3);

  for(int i:l){
    cout<<i<<" ";
  }cout<<endl;

  l.erase(l.begin());
  cout<<"After Erase "<<endl;
  for(int i:l){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Size of list "<<l.size()<<endl;

  list<int> k(4,100);

  for(int i:k){
    cout<<i<<" ";
  }cout<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
//////////////(Stack stl)/////////////////////////////////
////////last one is the first))))))))))))))))
/*#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<string> ch;

  ch.push("priyanshu");
  ch.push("rahul");
  ch.push("devanshu");

  cout<<"Element at the top ("<<ch.top()<<endl;
  ch.pop();
  cout<<"Element at the top after pop ("<<ch.top()<<endl;

  cout<<"Empty or not ("<<ch.empty()<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
/////////////(Queue stl)//////////////////////////
///////////First one is the first)))))))))))))))
/*#include<iostream>
#include<queue>
using namespace std;

int main(){
  queue<string> s;

  s.push("come");
  s.push("on");
  s.push("now");

  cout<<"Size before pop "<<s.size()<<endl;

  cout<<"First Element "<<s.front()<<endl;
  s.pop();
  cout<<"First element "<<s.front()<<endl;

  cout<<"Size after pop "<<s.size()<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////
//////////(Priority queue)//////////////////////////////////////////
/////////element stored in sorted way))))))))))))))))))))))))
/*#include<iostream>
#include<queue>
using namespace std;

int main(){
  //Max_heap
  priority_queue<int> maxi;

  //Min_heap
  priority_queue<int, vector<int>, greater<int>> mini;

  maxi.push(1);
  maxi.push(2);
  maxi.push(5);
  maxi.push(3);

  cout<<"Size-> "<<maxi.size()<<endl;
  int n = maxi.size();
  for(int i = 0; i<n; i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
  }cout<<endl;

  mini.push(2);
  mini.push(3);
  mini.push(1);
  mini.push(0);

  cout<<"Size-> "<<mini.size()<<endl;
  int k = mini.size();
  for(int i = 0; i<k; i++){
    cout<<mini.top()<<" ";
    mini.pop();
  }cout<<endl;

  cout<<"Empty or not mini "<<mini.empty()<<endl;
  cout<<"Empty or not maxi "<<maxi.empty()<<endl;
}*/
///////////////////////////////////////////////////////////////////////////////
//////////////////(Set stl)/////////////////////////////
//////////////Unique elements only))))))))))))))
/*#include<iostream>
#include<set>
using namespace std;

int main(){
  set<int> s;

  /*s.insert(1);
  s.insert(4);
  s.insert(1);
  s.insert(2);
  s.insert(2);
  s.insert(7);
  s.insert(7);

  for(auto i:s){//Auto keyword automatically assigns a data type:
    cout<<i<<" ";
  }cout<<endl;

  set<int>::iterator it = s.begin();//iterator is like a pointer
  it++;

  s.erase(it);

  for(auto i:s){
    cout<<i<<" ";
  }cout<<endl;


  int n;
  cin>>n;
  cout<<"Element is present or not "<<s.count(n)<<endl;

  //Find returns the iterator of the element:
  set<int>::iterator itr = s.find(n);

  it = itr;
  cout<<"Value present at itr "<<*it<<endl;*/

  /*set<int> st;
  st.insert(1);
  st.insert(4);
  st.insert(5);
  st.insert(7);

  cout<<"New set "<<endl;
  for(auto i:st){
    cout<<i<<" ";
  }cout<<endl;

  set<int>::iterator pt = st.find(4);

  cout<<"Iterator is-> "<<*pt<<endl;

  for(; st!=st.end(); st++){
    cout<<*st<<" ";
  }cout<<endl;
}*/
///////////////////////////////////////////////////////////////////////////////
//////////(Map stl)////////////////////////////////////////////////////
/////////key points to a value)))))))))))))))))))))))
/*#include<iostream>
#include<map>
using namespace std;

int main(){
  map<int, string> m;

  m[1] = "apple";
  m[2] = "banana";
  m[3] = "almond";

  m.insert({13, "grapes"});

  cout<<"Before erase--------------"<<endl;
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }

  cout<<"(Finding 13) "<<m.count(13)<<endl;//Tells if 13 is present or not

  cout<<"After erase---------------"<<endl;
  m.erase(13);//giving key to erase:
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }

  auto it = m.find(2);
  for(auto i = it; i!=m.end(); i++){
    cout<<(*i).first<<endl;
  }
}*/
/////////////////////////////////////////////////////////////////////////////////////
//////////////(Using algorithm)///////////////////
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

  vector<int> v;

  v.push_back(2);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  //Using Binary serach:
  cout<<"searching 5 "<<binary_search(v.begin(), v.end(), 5)<<endl;

  cout<<"Lower bound-> "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
  cout<<"Upper bound-> "<<upper_bound(v.begin(), v.end(), 6) - v.begin()<<endl;

  int a = 3;
  int b = 4;

  cout<<"Max-> "<<max(a,b)<<endl;;
  cout<<"Min-> "<<min(a,b)<<endl;;

  cout<<"String is-> ";
  string var = "Hello";
  cout<<var<<endl;
  reverse(var.begin(), var.end());
  cout<<"String after reverse is-> "<<var<<endl;

  cout<<"Rotating the vector "<<endl;
  rotate(v.begin(), v.begin()+1, v.end());

  for(int i:v){
    cout<<i<<" ";
  }cout<<endl;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///(Iterator - MAP)/////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
  unordered_map<string, int> ourmap;
  ourmap["abc"] = 1;
  ourmap["abc1"] = 2;
  ourmap["abc2"] = 3;
  ourmap["abc3"] = 4;

  //Iterating an unordered map:
  unordered_map<string, int>::iterator it = ourmap.begin();
  while(it != ourmap.end())
  {
    cout<< "Key : "<< it->first <<", Value : "<< it->second <<endl;
    it++;
  }cout<<endl;

  unordered_map<string, int>::iterator it2 = ourmap.find("abc3");
  while(it2 != ourmap.end()){
    cout<< "Key : "<<it2->first<<", Value : "<<it2->second <<endl;
    it2++;
  }

  //Iterating a vector:
  vector<int> v{1, 2, 3, 4, 5};
  vector<int>:: iterator it1 = v.begin();

  while(it1 != v.end()){
    cout<< *it1 << endl;
    it1++;
  }
  for(vector<int>:: iterator it1 = v.begin(); it1 != v.end(); it1++){
    cout<< *it1 <<endl;
  }

  return 0;
}