// Q2) Write a C++ program to search a graph using the BFS algorithm and show whether the required information is found or not.
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool BFS(int s, int target);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::BFS(int s, int target) {
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while(!queue.empty()) {
        s = queue.front();
        queue.pop();

        // If target is found
        if (s == target) {
            return true;
        }

        for(auto adjVertex : adj[s]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    return false;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int target = 3;
    if(g.BFS(0, target))
        cout << "Target found in the graph." << endl;
    else
        cout << "Target not found in the graph." << endl;

    return 0;
}

// Graph Construction: 
// The graph is represented using an adjacency list. We store each vertex's adjacent vertices.
// BFS Function: We use a queue for the BFS traversal, marking visited vertices to avoid revisiting them.
// Searching: If the target is found during the traversal, we return true. Otherwise, after the queue is empty, we return false.