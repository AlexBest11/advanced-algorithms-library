#include "data_structures/priority_queue.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

const int INF = 1000000;

void dejkstra(std::vector< std::vector< std::pair< int, int > > >& graph, int start)
{
	std::vector< int > dist(graph.size(), INF);
	dist[start] = 0;
	PriorityQueue< std::pair< int, int >, std::greater< std::pair< int, int > > > pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		std::pair< int, int > v = pq.top();
		int temp_dist = v.first;
		int temp_vertex = v.second;
		pq.pop();
		if (temp_dist > dist[temp_vertex])
			continue;
		for (std::pair< int, int > to : graph[temp_vertex])
		{
			if (dist[to.second] > temp_dist + to.first)
			{
				dist[to.second] = temp_dist + to.first;
				pq.push({ temp_dist + to.first, to.second });
			}
		}
	}
}
