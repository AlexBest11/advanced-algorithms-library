#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void dfs(std::vector< std::vector< int > > &graph, int v, std::vector< int > &visited, std::vector< int > &ordered)
{
	visited[v] = 1;
	for (int to : graph[v])
	{
		if (!visited[to])
		{
			dfs(graph, to, visited, ordered);
		}
	}
	ordered.push_back(v);
}

std::vector< int > topologic_sort(std::vector< std::vector< int > > &graph)
{
	int size = graph.size();
	std::vector< int > visited(size, 0);
	std::vector< int > ordered;
	for (int i = 0; i < size; i++)
	{
		if (!visited[i])
		{
			dfs(graph, i, visited, ordered);
		}
	}
	std::reverse(ordered.begin(), ordered.end());
	return ordered;
}
