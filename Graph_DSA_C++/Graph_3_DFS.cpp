/*#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void prepareAdjlist(unordered_map<int, list<int>> &adjlist, vector<pair<int,int>> edges)
{
    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void DFS(int node, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> visited, vector<int> component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i:adjlist[node]){
        if(!visited[i]){
            DFS(i, adjlist, visited, component);
        }
    }
}

vector<vector<int>> DepthFirstSearch(int vertex, vector<pair<int,int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    prepareAdjlist(adjlist, edges);

    //Traversing the adjlist:
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            vector<int> component;
            DFS(i, adjlist, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> edges{{0,4}, {4,0}, {4,2}, {4,1}, {2,3}, {2,4}, {3,5}, {3,2},
    {5,1}, {5,3}, {1,4}, {1,5}};

    vector<vector<int>> ans = DepthFirstSearch(3, edges);

    for(auto i:ans){
        for(int j:i){
            cout<< j <<" ";
        }cout<<endl;
    }
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjlist)
{
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while(!s.empty()){
        int front = s.top();
        s.pop();

        ans.push_back(front);

        for(auto i:adjlist[front]){
            if(!visited[i]){
                s.push(i);
                visited[i] = true;
            }
        }
    }
}


vector<int> printDFS(vector<vector<int>> edges, int vertex)
{
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<int> ans;

    for(auto i:edges){
        int u = i[0];
        int v = i[1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            DFS(i, ans, visited, adjlist);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges{{1,2}, {2,1}, {1,3}, {3,1}, {2,4}, {4,2}, {3,4}, {4,3},
    {4,5}, {5,4}, {4,6}, {6,4}, {3,7}, {7,3}};

    vector<int> ans = printDFS(edges, 7);

    for(int i:ans){
        cout<< i <<" ";
    }
}