// Kahn's algorithm ///////////////////////////////////////////////////////////////
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

vector<int> TopoSort (vector<vector<int>> edges, int n) {
    unordered_map<int, list<int>> adjlist;
    for (vector<int> i: edges) {
        int u = i[0];
        int v = i[1];
        adjlist[u].push_back(v);
    }

    // calculating Indegree:
    vector<int> in(n+1);
    for (auto i: adjlist) {
        for (int j: i.second) {
            in[j]++;
        }
    }

    // finding indegree 0:
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) q.push(i);
    }
    
    // finding answer: =>
    vector<int> ans;
    
    while (!q.empty()) {
        int frontnode = q.front();
        ans.push_back(frontnode);
        q.pop();

        for (int i: adjlist[frontnode]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> edges {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};

    vector<int> ans = TopoSort(edges, 5);

    for (int i: ans) {
        cout<< i <<" ";
    }

    return 0;
}