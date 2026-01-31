// C++ Program to Implement a Graph Using Adjacency List for Undirected Graph
#include <iostream>
#include <vector>
#include <unordered_map>                  // For unordered_map
using namespace std;

// // Approach - 1: Using map to store adjacency list representation of the graph
// // time complexity: O(V + E) where V is number of vertices and E is number of edges
// // space complexity: O(V + E) for storing the adjacency list
// class Graph {
//     unordered_map<int, vector<int>> adjList; // Adjacency list to store the graph

// public:
//     // Function to add an edge between vertices u and v of
//     // the graph
//     void add_edge(int u, int v)
//     {
//         // Add edge from u to v
//         adjList[u].push_back(v);
//         // Add edge from v to u because the graph is
//         // undirected
//         adjList[v].push_back(u);
//     }

//     // Function to print the adjacency list representation
//     // of the graph
//     void print()
//     {
//         cout << "Adjacency list for the Graph: " << endl;
//         // Iterate over each vertex
//         for (auto i : adjList) {
//             // Print the vertex
//             cout << i.first << " -> ";
//             // Iterate over the connected vertices
//             for (auto j : i.second) {
//                 // Print the connected vertex
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//     }
// };
// or

// class Graph {

//     int V;                                // Total number of vertices
//     unordered_map<int, vector<int>> adj;  // Adjacency list using unordered_map

// public:

//     // Constructor
//     Graph(int vertices) {
//         V = vertices;                     // Store number of vertices
//     }

//     // Add edge (undirected graph)
//     void add_edge(int u, int v) {
//         adj[u].push_back(v);              // Add v to u's adjacency list
//         adj[v].push_back(u);              // Add u to v's adjacency list
//     }

//     // Print adjacency list using classic loop + iterator
//     void print() {
//         cout << "Adjacency list for the Graph:\n";

//         // Loop from 0 to V-1 (classic loop like vector graph)
//         for (int u = 0; u < V; u++) {

//             cout << u << " -> ";           // Print current vertex

//             // Check if vertex exists in unordered_map
//             if (adj.find(u) != adj.end()) {

//                 // Iterator-based loop (exact style you wanted)
//                 for (auto v = adj[u].begin();
//                      v != adj[u].end();
//                      v++) {

//                     cout << *v << " ";     // Dereference iterator
//                 }
//             }

//             cout << endl;                 // New line
//         }
//     }
// };



// Approach - 2: Using vector to store adjacency list representation of the graph
// time complexity: O(V + E) where V is number of vertices and E is number
// space complexity: O(V + E) for storing the adjacency list

#include <iostream>              // For input-output operations (cout, endl)
#include <vector>                // For using vector container
using namespace std;             // Avoid writing std:: repeatedly

// Graph class definition
class Graph {

    int V;                       // Number of vertices in the graph
    vector<vector<int>> adj;     // Adjacency list: each index stores neighbors

public:

    // Constructor: initializes graph with given number of vertices
    Graph(int vertices) {
        V = vertices;            // Store number of vertices
        adj.resize(V);           // Resize adjacency list to hold V vertices
    }

    // Function to add an undirected edge between u and v
    void add_edge(int u, int v) {
        adj[u].push_back(v);     // Add v to adjacency list of u
        adj[v].push_back(u);     // Add u to adjacency list of v (undirected)
    }

    // Function to print the adjacency list of the graph
    void print() {
        cout << "Adjacency List of the Graph:\n";

        // Loop through each vertex
        for (int i = 0; i < V; i++) {
            cout << i << " -> "; // Print current vertex

            // Loop through neighbors of vertex i
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " "; // Print connected vertex
            }

            cout << endl;        // Move to next line
        }
    }
};

int main() {

    Graph g(4);                  // Create graph with 4 vertices (0,1,2,3)

    g.add_edge(1, 0);            // Edge between 1 and 0
    g.add_edge(2, 0);            // Edge between 2 and 0
    g.add_edge(1, 2);            // Edge between 1 and 2
    g.add_edge(3, 2);            // Edge between 3 and 2 (FIXED from 5)

    g.print();                   // Print adjacency list

    return 0;                    // Program ends successfully
}
