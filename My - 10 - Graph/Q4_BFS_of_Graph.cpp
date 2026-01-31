// C++ Program to Implement breadth first search (BFS) of a Graph
// standard bfs implementation using adjacency list

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

    // BFS traversal of the graph
    void BFS(int u)
    {
        unordered_map<int, bool> visited; // To keep track of visited nodes
        queue<int> q;                     // Queue for BFS

        // Mark the starting node as visited and enqueue it
        visited[u] = true;
        q.push(u);

        while (!q.empty())
        {
            // Dequeue a vertex from the queue and print it
            int u = q.front();
            cout << u << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex u
            for (int v : adjList[u])
            {
                // If an adjacent vertex has not been visited, mark it visited and enqueue it
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

// example usage
int main()
{
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(3, 6);
    g.print();
    cout << "BFS traversal starting from vertex 0: " << endl;
    g.BFS(0);

    return 0;
}