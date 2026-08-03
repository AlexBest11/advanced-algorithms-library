
#include "data_structures/stack.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void dfs(std::vector< std::vector< int > > &graph, int v, std::vector< int > &visited)
{
	visited[v] = 1;
	for (int to : graph[v])
	{
		if (!visited[to])
		{
			dfs(graph, to, visited);
		}
	}
}

void dfs_iteration(std::vector< std::vector< int > > &graph, int start_v, std::vector< int > &visited)
{
	Stack< int > st;
	st.push(start_v);
	while (!st.empty())
	{
		int v;
		st.top(v);
		st.pop();
		if (visited[v])
		{
			continue;
		}
		visited[v] = 1;
		for (int to : graph[v])
		{
			if (!visited[to])
			{
				st.push(to);
			}
		}
	}
}
