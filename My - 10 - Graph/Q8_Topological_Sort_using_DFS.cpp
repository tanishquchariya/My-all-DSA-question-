// Topological Sort using BFS in a Directed Acyclic Graph (DAG)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Approach: Using BFS to perform topological sort
// time complexity: O(V + E) where V is number of vertices and E is number
// space complexity: O(V) for storing the adjacency list and recursion stack
class Graph {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); // directed
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

// example usage
int main() {
    Graph g;
    int V = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    vector<int> ans = g.topoSort(V, edges);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}