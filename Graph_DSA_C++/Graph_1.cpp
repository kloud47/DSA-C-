///(Graphs)(using list)/////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class Graph{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        //direction = 0 -> undirected graph:
        //direction = 1 -> directed graph:

        adj[u].push_back(v);//Creating an edge from u to v
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjlist(){
        for(auto i:adj){
            cout<< i.first <<"-> ";
            for(auto j:i.second){
                cout<< j <<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<< "Enter the number of nodes." <<endl; cin>>n;

    int e;
    cout<< "Enter the number of edges." <<endl; cin>>e;

    Graph<int> g;

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph:
        g.addEdge(u, v, 0);
    }

    g.printAdjlist();

    return 0;
}

///(Graphs)(using vector)/////////////////////////////////////////////////////////////////////////////////////////
// #include<iostream>
// #include<list>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// class Graph{
// public:
//     unordered_map<int, list<int>> adjlist;

//     void addEdge(vector<vector<int>> edges){
//         for(auto i:edges){
//             int u = i[0];
//             int v = i[1];

//             adjlist[u].push_back(v);
//             adjlist[v].push_back(u);
//         }
//     }

//     void printAdjlist(){
//         for(auto i:adjlist){
//             cout<< i.first << "-> ";
//             for(auto j:i.second){
//                 cout<< j << ", ";
//             }
//             cout<<endl;
//         }
//     }
// };

// int main(){
//     vector<vector<int>> edges{{1,2}, {2,1}, {2,3}, {2,4}, {3,2}, {4,2}};

//     Graph g;
//     g.addEdge(edges);
//     g.printAdjlist();
// }