#include <queue>
#include "Graph.h"

Graph::Graph(Graph&& other) noexcept : V(other.V), adj(std::move(other.adj)) {
    other.V = 0;
}

Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        V = other.V;
        adj = std::move(other.adj);
        other.V = 0;
    }
    return *this;
}

void Graph::addEdge(int u, int v)
{
	adj[u].insert(v);
	adj[v].insert(u);
}

const std::unordered_set<int>& Graph::getNeighbors(int u) const
{
	return adj.at(u);
}

int Graph::getVertexCount() const
{
	return V;
}

void bfs(int start, const Graph& graph, std::vector<int>& distances) {
    std::queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph.getNeighbors(current))
        {
            if (distances[neighbor] == -1)
            {
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }
}
