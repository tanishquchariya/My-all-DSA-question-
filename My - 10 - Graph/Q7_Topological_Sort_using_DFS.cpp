// Topological Sort using DFS in a Directed Acyclic Graph (DAG)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Approach: Using DFS to perform topological sort
// time complexity: O(V + E) where V is number of vertices and E is number
// space complexity: O(V) for storing the adjacency list and recursion stack 
class Graph {
public:
    void dfs(vector<vector<int>>& adj, int u,
             vector<bool>& visited, stack<int>& st) {

        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited, st);
            }
        }
        st.push(u);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); // directed
        }

        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    Graph g;

    int V = 6;
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> topo_order = g.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int v : topo_order) cout << v << " ";
    cout << endl;

    return 0;
}
