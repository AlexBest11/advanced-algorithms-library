#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

std::map< int, int > color(std::vector< std::vector< int > >& graph)
{
	int size = graph.size();
	std::map< int, int > res;
	std::vector< char > color(size, true);
	res[0] = 0;
	for (int i = 1; i < size; ++i)
	{
		for (int to : graph[i])
		{
			if (to < i)
			{
				int neighbor_color = res[to];
				color[neighbor_color] = false;
			}
		}
		for (int col = 0; col < size; ++col)
		{
			if (color[col] == true)
			{
				res[i] = col;
				break;
			}
		}
		color.assign(size, true);
	}
	return res;
}
