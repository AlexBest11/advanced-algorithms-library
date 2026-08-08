#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void dfs_brigde(
	std::vector< std::vector< int > > &graph,
	std::vector< int > &tin,
	std::vector< int > &up,
	int v,
	int &timer,
	std::vector< std::pair< int, int > > &bridge,
	int p)
{
	tin[v] = up[v] = timer++;
	for (int to : graph[v])
	{
		if (to == p)
		{
			continue;
		}
		if (tin[to] == 0)
		{
			dfs_brigde(graph, tin, up, to, timer, bridge, v);
			up[v] = std::min(up[v], up[to]);
			if (up[to] > tin[v])
			{
				bridge.push_back({ v, to });
			}
		}
		else
		{
			up[v] = std::min(up[v], tin[to]);
		}
	}
}
void dfs_point(
	std::vector< std::vector< int > > &graph,
	std::vector< int > &tin,
	std::vector< int > &up,
	int v,
	int &timer,
	std::vector< std::pair< int, int > > &bridge,
	int p)
{
	tin[v] = up[v] = timer++;
	for (int to : graph[v])
	{
		if (to == p)
		{
			continue;
		}
		if (tin[to] == 0)
		{
			dfs_point(graph, tin, up, to, timer, bridge, v);
			up[v] = std::min(up[v], up[to]);
			if (up[to] >= tin[v])
			{
				bridge.push_back({ v, to });
			}
		}
		else
		{
			up[v] = std::min(up[v], tin[to]);
		}
	}
}
