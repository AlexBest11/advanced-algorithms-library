#include "data_structures/queue.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
void bfs(std::vector< std::vector< int > >& graph, int start_v, std::vector< int >& visited)
{
	Queue< int > q;
	visited[start_v] = 1;
	q.push(start_v);
	while (!q.empty())
	{
		int vert;
		q.top(vert);
		q.pop();
		for (int to : graph[vert])
		{
			if (visited[to] == 0)
			{
				visited[to] = 1;
				q.push(to);
			}
		}
	}
}
