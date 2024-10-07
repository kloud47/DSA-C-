///// Cycle detection in -> Directed graph /////////////////////////////////////////////////////////////////
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

bool checkDFS (unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited,
    unordered_map<int, bool> &DFSvisited, int src) {
    visited[src] = true;
    DFSvisited[src] = true;

    for (int i: adjlist[src]) {
        if (!visited[i]) {
            bool ans = checkDFS(adjlist, visited, DFSvisited, i);
            if (ans) return true;
        }
        else if (DFSvisited[i]) {
            return true;
        }
    }
    DFSvisited[src] = false;
    return false;
}

bool checkBFS (unordered_map<int, list<int>> adjlist, int src, int vertex) {/// using Kahn's Algorithm
    vector<int> in;// calculating inorder: =>
    for (auto i: adjlist) {
        for (int j: i.second) {
            in[j]++;
        }
    }

    queue<int> q;
    for (int i=1; i<=vertex; i++) {
        if (in[i] == 0) q.push(i);
    }

    int cnt = 0;// Count the number of nodes visited: =>
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cnt++;

        for (int i: adjlist[front]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }

    if (cnt == vertex) {
        return false;
    } else {
        return true;
    }
}

string cycleDetection (vector<vector<int>> edges, int n) {
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    for (vector<int> i: edges) {
        int u = i[0];
        int v = i[1];

        adjlist[u].push_back(v);
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            // bool ans = checkDFS(adjlist, visited, DFSvisited, i);
            bool ans = checkBFS(adjlist, i, n);
            if (ans) return "Yes";
        }
    }
    return "No";
}

int main () {
    vector<vector<int>> edges {{1, 2}, {2, 3}, {3, 8}, {3, 7}, {8, 7}, {2, 4}, {4, 5}, {5, 6}, {6, 4}};

    cout<< cycleDetection(edges, 8);

    return 0;
}