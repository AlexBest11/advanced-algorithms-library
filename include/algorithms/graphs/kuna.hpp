#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>

bool dfs(const std::vector< std::vector< int > >& graph, size_t vert_A, std::vector< int >& used, std::vector< int >& mt, int timer)
{
	if (used[vert_A] == timer)
	{
		return false;
	}
	used[vert_A] = timer;
	for (int to : graph[vert_A])
	{
		if (mt[to] == -1 || dfs(graph, mt[to], used, mt, timer))
		{
			mt[to] = vert_A;
			return true;
		}
	}
	return false;
}

std::vector< std::pair< int, int > > Kuna(const std::vector< std::vector< int > >& graph, size_t A, size_t B)
{
	std::vector< int > mt(B, -1);
	std::vector< int > used(A, 0);
	int timer = 0;
	for (size_t i = 0; i < A; i++)
	{
		timer += 1;
		dfs(graph, i, used, mt, timer);
	}
	std::vector< std::pair< int, int > > result;
	for (size_t i = 0; i < B; ++i)
	{
		if (mt[i] != -1)
		{
			result.push_back({ mt[i], i });
		}
	}
	return result;
}
