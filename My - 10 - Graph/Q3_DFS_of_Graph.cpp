// C++ Program to Implement Depth First Search (DFS) of a Graph
// standard dfs implementation using adjacency list

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach - 1: Using map to store adjacency list representation of the graph
// time complexity: O(V + E) where V is number of vertices and E is number
// space complexity: O(V + E) for storing the adjacency list
// for undirected graph
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
                // Print the connected vertex
                cout << v << " ";
            }
            cout << endl;
        }
    }
    // DFS traversal of the graph and this code for disconnected graph as well
    void DFS(int u, unordered_map<int, bool> &visited)
    {
        // here u is the current vertex
        // and v is the adjacent vertex of u 
        if(visited[u] == true){
            return;
        }
        // Mark the current vertex as visited
        visited[u] = true;
        cout << u << " ";
        // Recur for all the vertices adjacent to this vertex
        for (int v : adjList[u])
        {

            if (!visited[v])
            {
                DFS(v, visited);
            }
        }
    }
};
int main()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 6);

    g.print();

    unordered_map<int, bool> visited; // To keep track of visited vertices
    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS(0, visited); // Start DFS from vertex 0

    return 0;
}