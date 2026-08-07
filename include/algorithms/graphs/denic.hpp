#include "data_structures/queue.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

struct Edge
{
	int to, flow, capasity;
	int reverse;
};

bool bfs(std::vector< std::vector< Edge > > &graph, int source, int sink, std::vector< int > &level)
{
	level.assign(graph.size(), -1);
	level[source] = 0;
	Queue< int > q;
	q.push(source);
	while (!q.empty())
	{
		int v;
		q.top(v);
		q.pop();
		for (Edge &i : graph[v])
		{
			if (i.capasity - i.flow > 0 && level[i.to] == -1)
			{
				level[i.to] = level[v] + 1;
				q.push(i.to);
			}
		}
	}
	if (level[sink] != -1)
	{
		return true;
	}
	return false;
}

int dfs(int v, int pushed, int sink, std::vector< std::vector< Edge > > &graph, std::vector< int > &level, std::vector< int > &ptr)
{
	if (pushed == 0)
	{
		return 0;
	}
	if (v == sink)
	{
		return pushed;
	}
	for (int &i = ptr[v]; i < graph[v].size(); i++)
	{
		Edge &e = graph[v][i];
		if (e.capasity - e.flow > 0 && level[e.to] == level[v] + 1)
		{
			int temp = dfs(e.to, std::min(pushed, e.capasity - e.flow), sink, graph, level, ptr);
			if (temp > 0)
			{
				e.flow += temp;
				graph[e.to][e.reverse].flow -= temp;
				return temp;
			}
		}
	}
	return 0;
}
int max_flow(std::vector< std::vector< Edge > > &graph, int source, int sink)
{
	int n = graph.size();
	int flow = 0;

	std::vector< int > level(n);
	std::vector< int > ptr(n);
	while (bfs(graph, source, sink, level))
	{
		std::fill(ptr.begin(), ptr.end(), 0);
		int pushed;
		while ((pushed = dfs(source, INT_MAX, sink, graph, level, ptr)) > 0)
		{
			flow += pushed;
		}
	}

	return flow;
}
