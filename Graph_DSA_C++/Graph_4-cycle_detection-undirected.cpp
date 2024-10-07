//(Cycle detection using BFS)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

// using BFS traversal: =>
bool BFScheck(int node, unordered_map<int, list<int>> adjlist, 
            unordered_map<int, bool> visited)
{
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        for(auto neighbour: adjlist[frontnode]){
            if(visited[neighbour] == true && neighbour != parent[frontnode]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontnode;
            }
        }
    }
    return false;
}

// using DFS tarversal: =>
bool DFScheck(int src, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited, int parent) {
    visited[src] = true;

    for (int i: adjlist[src]) {
        if (!visited[i]) {
            bool ans = DFScheck(i, adjlist, visited, src);
            if (ans) return true;
        }
        else if (visited[i] && parent != i)
        {
            return true;
        }
        
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n)
{
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;

    for(vector<int> i:edges){
        int u = i[0];
        int v = i[1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            // bool ans = BFScheck(i, adjlist, visited);
            bool ans = DFScheck(i, adjlist, visited, -1);
            if(ans){
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {4, 1}};

    string ans = cycleDetection(edges, 4);
    cout<< ans;
}