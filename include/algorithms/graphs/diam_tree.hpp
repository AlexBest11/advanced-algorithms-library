#include "data_structures/queue.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void bfs(std::vector< std::vector< int > >& graph, int start_v, std::vector< int >& dist)
{
	Queue< int > q;
	dist[start_v] = 0;
	q.push(start_v);
	while (!q.empty())
	{
		int vert;
		q.top(vert);
		q.pop();
		for (int to : graph[vert])
		{
			if (dist[to] == -1)
			{
				dist[to] = dist[vert] + 1;
				q.push(to);
			}
		}
	}
}

int Tree_Diam(std::vector< std::vector< int > >& graph)
{
	int count_v = graph.size();
	if (count_v == 0)
	{
		return 0;
	}
	std::vector< int > dist1(count_v, -1);
	bfs(graph, 0, dist1);
	auto max_dist_vert = std::max_element(dist1.begin(), dist1.end());
	int vert = std::distance(dist1.begin(), max_dist_vert);

	dist1.assign(count_v, -1);
	bfs(graph, vert, dist1);

	int diam = *(std::max_element(dist1.begin(), dist1.end()));

	return diam;
}
