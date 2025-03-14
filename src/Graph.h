#pragma once

#include <unordered_map>
#include <unordered_set>

class Graph
{
private:
	int V;
	std::unordered_map<int, std::unordered_set<int>> adj;
	Graph(const Graph&) = delete;
	Graph& operator=(const Graph&) = delete;

public:
	Graph(int vertices) : V(vertices) {};
	Graph(Graph&& other) noexcept;
	Graph& operator=(Graph&& other) noexcept;

	void addEdge(int u, int v);

	const std::unordered_set<int>& getNeighbors(int u) const;

	int getVertexCount() const;
};

void bfs(int start, const Graph& graph, std::vector<int>& distances);

