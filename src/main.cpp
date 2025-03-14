#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.h"

Graph readGraphFromFile(const std::string& filename, int& start) {
    std::ifstream file(filename);

    if (!file)
    {
        throw std::runtime_error("Error opening file" + filename);
    }

    int V, E;
    file >> V >> E;
    Graph graph(V);

    int u, v;
    for (int i = 0; i < E; i++) {
        file >> u >> v;
        graph.addEdge(u, v);
    }

    file >> start;
    return graph;
}

int main() {
    std::string filename = "../graph.txt";
    int start;

    try
    {
        Graph graph = readGraphFromFile(filename, start);

        std::vector<int> distances(graph.getVertexCount(), -1);

        bfs(start, graph, distances);

        for (int i = 0; i < graph.getVertexCount(); i++) {
            std::cout << distances[i] << std::endl;
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

