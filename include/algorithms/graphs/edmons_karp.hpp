#include <data_structures/queue.hpp>

#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>


bool bfs(std::vector< std::vector< int > >& residual_graph, int v, int sink, std::vector< int >& parent, std::vector< int >& visited)
{
	visited[v] = 1;
	if (v == sink)
	{
		return true;
	}

	return false;
}

int Ford_Falkerson(std::vector< std::vector< int > >& graph, int source, int sink)
{
	std::vector< std::vector< int > > residual_graph = graph;
	int size = graph.size();
	std::vector< int > parent(size);
	int max_flow = 0;
	std::vector< int > visited(size, 0);

	while (dfs(residual_graph, source, sink, parent, visited))
	{
		int path_flow = INT_MAX;
		for (int v = sink; v != source;)
		{
			int vert = parent[v];
			path_flow = std::min(path_flow, residual_graph[vert][v]);
			v = vert;
		}
		for (int v = sink; v != source;)
		{
			int vert = parent[v];
			residual_graph[vert][v] -= path_flow;
			residual_graph[v][vert] += path_flow;
			v = vert;
		}
		max_flow += path_flow;
		visited.assign(size, 0);
	}
	return max_flow;
}
