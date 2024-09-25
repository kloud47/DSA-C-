#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    system("color 02");
    unordered_map<string, int> m;


    //Insertion:
    
    //1
    pair<string, int> p2 = make_pair("d", 4);
    m.insert(p2);
    pair<string, int> p = make_pair("a", 3);
    m.insert(p);

    //2
    pair<string, int> p1{"b", 2};
    m.insert(p1);

    //3
    m["c"] = 1;

    m["c"] = 0; //This is Updation:(one key == 1 value only)

    //Search:
    cout<< m["a"] <<endl;
    cout<< m.at("b") <<endl;

    //size:
    cout << m.size() << endl;

    //to check presence:
    cout << m.count("a") <<endl; 

    //erase
    m.erase("a");
    cout << m.size() <<endl;

    //iterator
    unordered_map<string, int> :: iterator it = m.begin();

    cout<< "\n\nFor unordered map."<<endl;
    while(it != m.end()){
        cout<< it->first <<" "<< it->second <<endl;;
        it++;
    }

    map<string, int> l;
    l["a"] = 1;
    l["b"] = 2;
    l["c"] = 3;

    map<string, int> :: iterator i = l.begin();

    cout<<"\nFor ordered map."<<endl;
    while(i != l.end()){
        cout<< i->first <<" "<< i->second <<endl;
        i++;
    }

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//(Maximum Frequency Number)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// #include<unordered_map>
// #include<vector>
// using namespace std;

// int maximumFrequency(vector<int> &arr)
// {
//     unordered_map<int, int> count;

//     int maxFreq = 0;
//     int maxAns = 0;

//     for(int i = 0; i < arr.size(); i++){
//         count[arr[i]]++;
//         maxFreq = max(maxFreq, count[arr[i]]);
//     }

//     for(int i = 0; i < arr.size(); i++){
//         if(maxFreq == count[arr[i]]){
//             maxAns = arr[i];
//             break;
//         }
//     }

//     return maxAns;
// }

// int main()
// {
//     vector<int> v{1, 2, 3, 2, 2, 5, 4, 2, 4};

//     cout<< maximumFrequency(v);

//     return 0;
// }