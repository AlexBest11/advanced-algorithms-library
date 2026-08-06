#include "sorting/quick_sort.hpp"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

struct Edge
{
	int u, v;
	int w;
	bool operator<(const Edge& other) const { return w < other.w; }
};

class DSU
{
  private:
	std::vector< int > parent;
	std::vector< int > rank;

  public:
	DSU(int count_v)
	{
		parent.resize(count_v);
		rank.assign(count_v, 0);
		for (int i = 0; i < count_v; i++)
		{
			parent[i] = i;
		}
	}

	int find(int vert)
	{
		if (parent[vert] != vert)
		{
			parent[vert] = find(parent[vert]);
		}
		return parent[vert];
	}

	void unite(int a, int b)
	{
		int root_a = find(a);
		int root_b = find(b);

		if (root_a != root_b)
		{
			if (rank[root_a] < rank[root_b])
			{
				parent[root_a] = root_b;
			}
			else if (rank[root_a] > rank[root_b])
			{
				parent[root_b] = root_a;
			}
			else
			{
				parent[root_b] = root_a;
				rank[root_a] += 1;
			}
		}
	}
};

std::pair< std::vector< Edge >, int > kruskal(std::vector< Edge >& edges, int count_v)
{
	std::vector< Edge > mst;
	int mst_weight = 0;
	DSU dsu(count_v);
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		if (dsu.find(edges[i].u) != dsu.find(edges[i].v))
		{
			mst.push_back(edges[i]);
			mst_weight += edges[i].w;
			dsu.unite(edges[i].u, edges[i].v);
			if (mst.size() == count_v - 1)
			{
				break;
			}
		}
	}
	return { mst, mst_weight };
}
