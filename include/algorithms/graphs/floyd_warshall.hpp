#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

const double INF = 1.7976931348623157e+308;

std::vector< std::vector< double > > floyd_warshall(std::vector< std::vector< double > >& graph, int count_v)
{
	for (int k = 0; k < count_v; k++)
	{
		for (int i = 0; i < count_v; i++)
		{
			for (int j = 0; j < count_v; j++)
			{
				if (graph[i][k] < INF && graph[k][j] < INF)
				{
					if (graph[i][j] > graph[i][k] + graph[k][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}
	return graph;
}
