//
// Created by user on 8/2/2024.
//
#include <iostream>
#include <list>
#include <vector>

class Graph {
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }

    void BFS(int s) {
        std::vector<bool> visited(V, false);
        std::list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop_front();

            for (auto adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }

    void DFSUtil(int v, std::vector<bool> &visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto adjacent : adj[v]) {
            if (!visited[adjacent]) {
                DFSUtil(adjacent, visited);
            }
        }
    }

    void DFS(int v) {
        std::vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2);
    std::cout << std::endl;

    std::cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2);
    std::cout << std::endl;

    return 0;
}
