#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

const double INF = 1.7976931348623157e+308;

struct Edge
{
	int from;
	int to;
	double weight;
};

std::pair< std::vector< double >, bool > Ford_Bellman(std::vector< Edge >& graph, int start_v, int count_v)
{
	std::vector< double > dist(count_v, INF);
	dist[start_v] = 0.0;
	int count_e = graph.size();
	for (int i = 0; i < count_v - 1; i++)
	{
		bool changed = false;
		for (Edge& e : graph)
		{
			if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.weight)
			{
				dist[e.to] = dist[e.from] + e.weight;
				changed = true;
			}
		}
		if (!changed)
		{
			break;
		}
	}

	bool has_cycle = false;
	for (Edge& e : graph)
	{
		if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.weight)
		{
			has_cycle = true;
			break;
		}
	}

	return { dist, has_cycle };
}
