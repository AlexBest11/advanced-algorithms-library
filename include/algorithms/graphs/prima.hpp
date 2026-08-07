#include "data_structures/priority_queue.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

std::vector< std::pair< int, int > > prima(std::vector< std::vector< std::pair< int, int > > >& graph, int count_v)
{
	if (count_v == 0)
	{
		return {};
	}
	std::vector< int > visited(count_v, 0);
	std::vector< std::pair< int, int > > tree;
	PriorityQueue< std::pair< int, std::pair< int, int > >, std::greater< std::pair< int, std::pair< int, int > > > > pq;
	visited[0] = 1;
	for (auto to : graph[0])
	{
		pq.push({ to.first, { to.second, 0 } });
	}
	while (!pq.empty())
	{
		std::pair< int, std::pair< int, int > > v = pq.top();
		int weight = v.first;
		int to = v.second.first;
		int from = v.second.second;
		pq.pop();
		if (visited[to])
		{
			continue;
		}
		tree.push_back({ from, to });
		visited[to] = 1;
		for (auto next : graph[to])
		{
			if (visited[next.second])
				continue;
			pq.push({ next.first, { next.second, to } });
		}
	}
	return tree;
}
