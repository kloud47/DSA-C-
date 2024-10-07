#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

void prepareAdjlist(unordered_map<int, list<int>> &adjlist, vector<pair<int, int>> edges)
{
    /*for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }*/
    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void BFS(unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited, 
    vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        //Store frontnode into ans:
        ans.push_back(frontnode);

        //traverse all neightbours of frontnode:
        for(auto i:adjlist[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BreadthFirstSearch(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<int> ans;

    prepareAdjlist(adjlist, edges);

    //Traverse all components of the graph:
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            BFS(adjlist, visited, ans, i);
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> edges{{0,4}, {4,0}, {4,2}, {4,1}, {2,3}, {2,4}, {3,5}, {3,2},
    {5,1}, {5,3}, {1,4}, {1,5}};

    vector<int> ans = BreadthFirstSearch(3, edges);

    for(int i:ans){
        cout<< i << " ";
    }
}