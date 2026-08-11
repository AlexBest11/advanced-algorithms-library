#include <data_structures/queue.hpp>

#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>

bool bfs(std::vector< std::vector< int > >& residual_graph, int v, int sink, std::vector< int >& parent, std::vector< int >& visited)
{
	visited[v] = 1;
	parent[v] = -1;
	Queue< int > q;
	q.push(v);
	while (!q.empty())
	{
		int vert;
		q.top(vert);
		q.pop();
		if (vert == sink)
		{
			return true;
		}
		for (int i = 0; i < residual_graph.size(); i++)
		{
			if (!visited[i] && residual_graph[vert][i] > 0)
			{
				q.push(i);
				visited[i] = 1;
				parent[i] = vert;
			}
		}
	}

	return false;
}

int Edmons_Karp(std::vector< std::vector< int > >& graph, int source, int sink)
{
	std::vector< std::vector< int > > residual_graph = graph;
	int size = graph.size();
	std::vector< int > parent(size);
	int max_flow = 0;
	std::vector< int > visited(size, 0);

	while (bfs(residual_graph, source, sink, parent, visited))
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
