//// Topological Sort ///////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
using namespace std;

void TopoSort(unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited, int src, stack<int> &s) {
    visited[src] = true;

    for (int i: adjlist[src]) {
        if (!visited[i]) {
            TopoSort(adjlist, visited, i, s);
        }
    }
    s.push(src);
    return;
}

vector<int> TopplogicalSort (vector<vector<int>> edges, int n) {
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    stack<int> s;

    for (vector<int> i: edges) {
        int u = i[0];
        int v = i[1];
        adjlist[u].push_back(v);
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            TopoSort(adjlist, visited, i, s);
        }
    }

    vector<int> ans;

    while (!s.empty()) {
        int num = s.top();
        s.pop();
        ans.push_back(num);
    }

    return ans;
}

int main() {
    vector<vector<int>> edges {{1, 2}, {2, 4}, {4, 5}, {5, 6}, {4, 6}, {1, 3}, {3, 4}};

    vector<int> ans = TopplogicalSort(edges, 6);

    for (int i: ans) {
        cout<< i << " ";
    }

    return 0;
}