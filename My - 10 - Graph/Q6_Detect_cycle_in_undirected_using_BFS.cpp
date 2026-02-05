// cycle detection in undirected graph using BFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Approach - 1: Using map to store adjacency list representation of the graph
// time complexity: O(V + E) where V is number of vertices and E is number
// space complexity: O(V + E) for storing the adjacency list
class Graph
{
    unordered_map<int, vector<int>> adjList; // Adjacency list to store the graph

public:
    // Function to add an edge between vertices u and v of
    // the graph
    void add_edge(int u, int v)
    {
        // Add edge from u to v
        adjList[u].push_back(v);
        // Add edge from v to u because the graph is
        // undirected
        adjList[v].push_back(u);
    }

    // Function to print the adjacency list representation
    // of the graph
    void print()
    {
        cout << "Adjacency list for the Graph: " << endl;
        // Iterate over each vertex
        for (auto u : adjList)
        {
            // Print the vertex
            cout << u.first << " -> ";
            // Iterate over the connected vertices
            for (auto v : u.second)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // DFS to detect cycle in an undirected graph
    bool isCycleBFS(vector<vector<int>>& adj, int u,vector<bool>& visited) {
        queue<pair<int,int>> que;
        que.push({u,-1});
        
        visited[u] = true;
        while(!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            
            int source = p.first;
            int parent = p.second;
            
            for(int v : adj[source]){
                if(visited[v] == false){
                    visited[v] = true;
                    que.push({v,source});
                }else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCyclic(int V)
    {
        // Create adjacency list from the unordered_map
        vector<vector<int>> adj(V);

        for (auto u : adjList)
        {
            for (auto v : u.second)
            {
                adj[u.first].push_back(v);
            }
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCycleBFS(adj, i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// example usage

int main()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(1, 3);

    g.print();

    int V = 4; // Number of vertices
    if (g.isCyclic(V))
    {
        cout << "Graph contains cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain cycle" << endl;
    }

    return 0;
}