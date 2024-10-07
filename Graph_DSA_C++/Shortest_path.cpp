//////////// Shortest path - (Undirected Graph) ////////////////////////////////////////////////////////////////////
// #include<iostream>
// #include<list>
// #include<unordered_map>
// #include<queue>
// #include<vector>
// using namespace std;

// void ShortestPath(vector<vector<int>> edges, int vertex, int s, int d) {
//     unordered_map<int, list<int>> adjlist;
//     unordered_map<int, bool> visited;
//     for (vector<int> i: edges) {
//         int u = i[0];
//         int v = i[1];
//         adjlist[u].push_back(v);
//         adjlist[v].push_back(u);
//     }

//     vector<int> parent(vertex+1);
//     queue<int> q;

//     q.push(1);
//     parent[1] = -1;
//     visited[1] = true;

//     while (!q.empty()) {
//         int front = q.front();
//         q.pop();

//         for (int i: adjlist[front]) {
//             if (!visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//                 parent[i] = front;
//             }
//         }
//     }

//     // finding shortest path using parent array: =>
//     int i = d;
//     while (i != s) {
//         cout<< i << "->";
//         i = parent[i];
//     }cout<< i ;
// }

// int main() {
//     vector<vector<int>> edges {{1, 2}, {2, 5}, {5, 8}, {1, 3}, {3, 8}, {1, 4}, {4, 6}, {6, 7}, {7, 8}};

//     ShortestPath(edges, 8, 1, 8);

//     return 0;
// }

//// Shortest path - (Directed Acyclic Graph)( DAG ) ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<limits>
#include<unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge (vector<vector<int>> edges) {
        for (vector<int> i: edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adjlist[u].push_back(make_pair(v, w));
        }
    }

    void printAdj () {
        for (auto i: adjlist) {
            cout<< i.first << " -> ";
            for (pair<int, int> j: i.second) {
                cout<< "(" << j.first << "," << j.second << ")";
            }cout<<endl;
        }
    }

    void DFS (int node, unordered_map<int, bool> &visited, stack<int> &s) {
        visited[node] = true;

        for (auto i: adjlist[node]) {
            if (!visited[i.first]) {
                DFS(i.first ,visited, s);
            }
        }
        s.push(node);
    }
};

vector<int> shortestPath(Graph g, int vertex) {
    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i=0; i<=vertex; i++) {
        if (!visited[i]) {
            g.DFS(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(vertex+1);
    for (int i=0; i<=vertex; i++) {
        dist[i] = INT_FAST32_MAX;
    }

    dist[src] = 0;

    while (!s.empty()) {
        int top  = s.top();
        s.pop();

        if (dist[top] != INT_FAST32_MAX) {
            for (auto i: g.adjlist[top]) {
                if ((i.second + dist[top]) < dist[i.first]) {
                    dist[i.first] = i.second + dist[top];
                }
            }
        }
    }

    return dist;
}

int main () {
    vector<vector<int>> edges {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {1, 3, 6}, {2, 3, 7}, {2, 4, 4}, {2, 5, 2}, {3, 4, -1}, {4, 5, -2}};

    Graph G;
    G.addEdge(edges);
    // G.printAdj();

    vector<int> ans = shortestPath(G, 5);

    for (int i: ans) {
        cout << i << " ";
    }

    return 0;
}